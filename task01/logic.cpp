#include "logic.h"

bool is_line_increasing(int** matrix, int m, int i) {

	for (int j = 1; j < m; j++) {

		if (matrix[i][j - 1] > matrix[i][j]) {

			return false;
		}
	}

	return true;
}

bool is_line_decreasing(int** matrix, int m, int i) {

	for (int j = 1; j < m; j++) {

		if (matrix[i][j - 1] < matrix[i][j]) {

			return false;
		}
	}

	return true;
}

int get_max_element_from_all_ordered_lines(int** matrix, int n, int m) {

	int max = -1;

	for (int i = 0; i < n; i++) {

		if (is_line_increasing(matrix, m, i)
			|| is_line_decreasing(matrix, m, i)) {


			for (int j = 0; j < m; j++) {

				if (matrix[i][j] > max) {
					max = matrix[i][j];
				}
			}
		}
	}

	return max;
}