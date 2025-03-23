#include "util.h"
#include "logic.h"

int main() {
	srand(time(0));

	int n, m;
	cout << "Enter size of matrix (n, m): ";
	cin >> n >> m;

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {

		*(matrix + i) = new int[m];
	}

	init(matrix, n, m);
	cout << "Matrix: \n" << convert_to_string(matrix, n, m);

	cout << "Max number from the ordered lines: "
		<< get_max_element_from_all_ordered_lines(matrix, n, m) << endl;

	for (int i = 0; i < n; i++) {

		delete[] *(matrix + i);
	}
	delete[] matrix;
	
	system("pause");
	return 0;
}