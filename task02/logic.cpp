#include "logic.h"

int find_max_combo_line(int** matrix, int i, int m) {

	int max_combo = 0;
	int counter = 0;

	for (int j = 0; j < m; j++) {

		if (matrix[i][j] == matrix[i][j + 1]) {
			counter++;
		}
		else {

			if (counter > max_combo) {
				max_combo = counter;
			}

			counter = 0;
		}
	}

	return max_combo;
}

int get_max_combo_line_index(int** matrix, int n, int m) {

	int max_combo_line_index = 0;
	bool flag;

	flag = find_max_combo_line(matrix, 0, m) ? true : false;

	for (int i = 1; i < n; i++) {

		if (find_max_combo_line(matrix, i, m)
	> find_max_combo_line(matrix, max_combo_line_index, m)) {

			max_combo_line_index = i;
			flag = true;
		}
	}

	return flag ? ++max_combo_line_index : -1;
}