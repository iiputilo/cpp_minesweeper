#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>


int main() {
	bool flag0, flag1, flag2, isRunning;
	int numOfMines, m, n, x, y;
	std::cout << "Choose the dimensity of the field (for example '5 5'): ";
	std::cin >> m >> n;
	std::cout << "Choose the number of mines: ";
	std::cin >> numOfMines;
	if (numOfMines <= m * n) {
		srand(time(0));
		std::vector<std::vector<int>> mineField(m, std::vector<int>(n));
		std::vector<std::vector<char>> gameField(m, std::vector<char>(n, char(35)));
		std::vector<std::vector<int>> coords(numOfMines, std::vector<int>(2)), choices;
		std::vector<int> coord;
		int start = 1, end1 = m, end2 = n;
		for (int i = 0; i != numOfMines; ++i) {
			flag0 = 0;
			while (flag0 == 0) {
				x = rand() % (end1 - start + 1) + start;
				y = rand() % (end2 - start + 1) + start;
				coord = { x, y };
				if (std::find(coords.begin(), coords.end(), coord) == coords.end()) {
					coords[i] = coord;
					flag0 = 1;
				}
			}
		}
		for (int i = 0; i != numOfMines; ++i) {
			x = coords[i][0];
			y = coords[i][1];
			flag1 = 0;
			flag2 = 0;
			if (x - 1 != 0) {
				mineField[x - 2][y - 1] += 1;
				flag1 = 1;
			}
			if (x + 1 <= m) {
				mineField[x][y - 1] += 1;
				flag2 = 1;
			}
			if (y - 1 != 0) {
				mineField[x - 1][y - 2] += 1;
				if (flag1 == 1) {
					mineField[x - 2][y - 2] += 1;
				}
				if (flag2 == 1) {
					mineField[x][y - 2] += 1;
				}
			}
			if (y + 1 <= n) {
				mineField[x - 1][y] += 1;
				if (flag1 == 1) {
					mineField[x - 2][y] += 1;
				}
				if (flag2 == 1) {
					mineField[x][y] += 1;
				}
			}
		}
		for (int i = 0; i != numOfMines; ++i) {
			x = coords[i][0] - 1;
			y = coords[i][1] - 1;
			mineField[x][y] = -1;
		}

		isRunning = 1;
		coord.clear();
		while (isRunning == 1) {
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			for (int i = 0; i != m; ++i) {
				for (int j = 0; j != n; ++j) {
					coord = { i + 1, j + 1 };
					if (std::find(choices.begin(), choices.end(), coord) != choices.end()) {
						if (mineField[i][j] != -1) {
							std::cout << mineField[i][j] << " ";
						}
						else {
							std::cout << "* ";
						}
					}
					else {
						std::cout << gameField[i][j] << " ";
					}
				}
				std::cout << "\n";
			}
			std::cout << "\n" << "Choose the coords of the cell you want to open: ";
			std::cin >> x >> y;
			coord = { x, y };
			choices.push_back(coord);
			if ((m * n) - choices.size() == numOfMines) {
				std::cout << "\n" << "You won!" << "\n\n\n\n\n\n";
				isRunning = 0;
			}
			if (std::find(coords.begin(), coords.end(), coord) != coords.end()) {
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				for (int i = 0; i != m; ++i) {
					for (int j = 0; j != n; ++j) {
						if (mineField[i][j] != -1) {
							std::cout << mineField[i][j] << " ";
						}
						else {
							std::cout << "* ";
						}
					}
					std::cout << "\n";
				}
				std::cout << "\n" << "Game is over!" << "\n\n\n\n\n\n";
				isRunning = 0;
			}
		}
	}
	else {
		std::cout << "The number of mines is more than the number of field cells.";
	}
}