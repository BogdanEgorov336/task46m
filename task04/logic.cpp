#include "logic.h"

int get_first_pos_index(int** matrix, int i, int m) {

	for (int j = 0; j < m; j++) {
	
		if (matrix[i][j] > 0) {
			return j;
		}
	}

	return m;
}

int get_second_pos_index(int** matrix, int i, int m) {

	for (int j = get_first_pos_index(matrix, i, m) + 1; j < m; j++) {

		if (matrix[i][j] > 0) {
			return j;
		}
	}

	return m;
}


int get_sum_of_elements_between_positive_values(int** matrix, int n, int m) {

	int sum = 0;

	for (int i = 0; i < n; i++) {

		if (get_first_pos_index(matrix, i, m) != get_second_pos_index(matrix, i, m)) {

			for (int j = get_first_pos_index(matrix, i, m) + 1; j
				< get_second_pos_index(matrix, i, m); j++) {

				sum += matrix[i][j];
			}
		}
	}

	return sum;
}