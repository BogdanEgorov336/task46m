#include "util.h"

void init(int** matrix, int n, int m, int a, int b) {

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			matrix[i][j] = rand() % (b - a) + a + 1;
		}
	}
}

string convert_to_string(int** matrix, int n, int m) {

	string str = "";

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			str += to_string(matrix[i][j]) + "	";
		}
		str += "\n";
	}

	return str;
}