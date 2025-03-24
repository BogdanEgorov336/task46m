#include "logic.h"

int find_max_increasing_line(int** matrix, int i, int m) {

	int max_line = 0;
	int counter = 0;

	for (int j = 0; j < m; j++) {

		if (matrix[i][j] < matrix[i][j + 1]) {
			counter++;
		}
		else {

			if (counter > max_line) {
				max_line = counter;
			}

			counter = 0;
		}
	}

	return max_line;
}

int find_max_decreasing_line(int** matrix, int i, int m) {

	int max_line = 0;
	int counter = 0;

	for (int j = 0; j < m; j++) {

		if (matrix[i][j] > matrix[i][j + 1]) {
			counter++;
		}
		else {

			if (counter > max_line) {
				max_line = counter;
			}

			counter = 0;
		}
	}

	return max_line;
}

int compare(int** matrix, int i, int n, int m) {

	if (matrix == nullptr || n <= 1 || m <= 1) {
		return 0;
	}

	return find_max_increasing_line(matrix, i, m)
		> find_max_decreasing_line(matrix, i, m)
		? find_max_increasing_line(matrix, i, m)
		: find_max_decreasing_line(matrix, i, m);
}

int get_max_combo_line_index(int** matrix, int n, int m) {

	int max_combo_line_index = 0;
	bool flag;

	flag = compare(matrix, 0, m, n) ? true : false;

	for (int i = 1; i < n; i++) {

		if (compare(matrix, i, m, n)
	> compare(matrix, max_combo_line_index, m, n)) {

			max_combo_line_index = i;
			flag = true;
		}
	}

	return flag ? ++max_combo_line_index : -1;
}