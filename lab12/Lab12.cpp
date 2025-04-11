#include <iostream>
using namespace std;


const int RANK = 5;


bool isallpositive(int row[RANK]) {
	for (int i = 0; i < RANK; i++) {
		if (row[i] <= 0) {
			return false;
		}
	}
	return true;
}

void printmatrix(int matrix[RANK][RANK]) {
	for (int i = 0; i < RANK; i++)
	{
		for (int j = 0; j < RANK; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
}

void flattenMatrix(int matrix[RANK][RANK], int array[RANK * RANK]) {
	int k = 0;
	for (int i = 0; i < RANK; i++) {
		for (int j = 0; j < RANK; j++) {
			array[k] = matrix[i][j];
			k++;
		}
	}
}

int findMax(int array[RANK * RANK]) {
	int max = array[0];
	for (int i = 1; i < RANK * RANK; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}


int main()
{
	srand(time(nullptr));

	int matrix[RANK][RANK];


	for (int i = 0; i < RANK; i++)
	{
		for (int j = 0; j < RANK; j++)
		{
			matrix[i][j] = rand() % 201 - 100;
		}
	}
	printmatrix(matrix);

	int sum = 0;
	for (int i = 0; i < RANK; i++) {
		if (isallpositive(matrix[i])) {
			for (int j = 0; j < RANK; j++) {
				sum += matrix[i][j];
			}
		}
	}
	cout << "The sum of the elements in those rows that contain only positive numbers:" << sum << endl;


	int array[RANK * RANK];
	flattenMatrix(matrix, array);

	int max = findMax(array);
	cout << "Maximum element in a one-dimensional array: " << max << endl;
}