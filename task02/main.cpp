#include "util.h"
#include "logic.h"

int main() {
	srand(time(0));

	int n, m;
	cout << "Enter size of the matrix [n, m]: ";
	cin >> n >> m;

	int** matrix;
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}

	init(matrix, m, n);
	cout << "Matrix:\n" << convert_to_string(matrix, m, n) << endl;

	cout << "Max combo is in the line: "
		<< (get_max_combo_line_index(matrix, n, m) != -1 
			? to_string(get_max_combo_line_index(matrix, n, m)) 
			: "invalid values were found / there isn't such lines.") << endl;

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	system("pause");
	return 0;
}