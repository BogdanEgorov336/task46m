#include "util.h"
#include "logic.h"

int main() {
	srand(time(0));

	int n, m;
	cout << "Enter size of the matrix [n,m]: ";
	cin >> n >> m;

	int a, b;
	cout << "Enter range of generating values [a,b]: ";
	cin >> a >> b;

	int** matrix;
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}

	init(matrix, m, n, a, b);
	cout << "Matrix:\n" << convert_to_string(matrix, m, n) << endl;

	cout << "Sum between first positive elements of the matrix lines: "
		<< get_sum_of_elements_between_positive_values(matrix, n, m) << endl;

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	system("pause");
	return 0;
}