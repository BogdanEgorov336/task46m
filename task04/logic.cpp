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

		int fst_index = get_first_pos_index(matrix, i, m);
		int scnd_index = get_second_pos_index(matrix, i, m);

		if (fst_index != scnd_index) {

			for (int j = fst_index + 1; j < scnd_index; j++) {

				sum += matrix[i][j];
			}
		}
	}

	return sum;
}