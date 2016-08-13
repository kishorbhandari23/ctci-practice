#include "stdafx.h"
#include<iostream>
using namespace std;

void printmatrix(int* matrix, int row, int column)
{
	for (int row_index = 0; row_index < row; row_index++)
	{
		for (int col_index = 0; col_index < column; col_index++)
		{
			cout << matrix[row_index*column + col_index] << "  ";
		}
		cout << endl;
	}
}

void rotate(int* matrix, int n)
{
	for (int layer = 0; layer < n / 2; ++layer)
	{
		int first = layer;
		int last = n - 1 - layer;

		for (int i = first; i < last; ++i)
		{
			int offset = i - first;
			// save top
			int top = matrix[first * n + i];

			// left to top
			matrix[first * n + i] = matrix[(last - offset) * n + first];

			// bottom to left
			matrix[(last - offset) * n + first] = matrix[last * n + (last - offset)];

			// right to bottom
			matrix[last * n + (last - offset)] = matrix[i * n + last];

			// top to right
			matrix[i * n + last] = top;
		}
	}
}


void rotateMatrix(int* matrix, int n) 
{
	for (int layer = 0; layer < n/2; layer++)
	{
		int first = layer; //first element for starting rotation
		int last = n - 1 - layer; //last eleemnt of rotation
		for (int i = first; i < last; i++)
		{	
			//int top = matrix[layer][i + layer];
			int top = matrix[layer*n + i + layer];

			//top=left
			//matrix[layer][i + layer] = matrix[last - i][first];
			matrix[layer*n + i + layer] = matrix[(last - i)*n + first];

			//left=buttom
			//matrix[last - i][first] = matrix[last][last - i];
			matrix[(last - i)*n + first]= matrix[last*n+last - i];

			//buttom=right
			//matrix[last][last - i] = matrix[layer + i][last];
			matrix[last*n + last - i] = matrix[(layer + i)*n + last];

			//right=top
			//matrix[layer + i][last] = top;
			matrix[(layer + i)*n + last] = top;
		}
	}

}

int main()
{
	int matrix[5][5] = { { 1,2,3,4,5 },{6,7,8,9,10 },{11,12,13,14,15 },{16,17,18,19,20 },{21,22,23,24,25}};
	int* matrixPtr = (int*)matrix;
	cout << "Original Matrix" << endl;
	printmatrix(matrixPtr, 5, 5);
	cout << "Rotated Matrix" << endl;
	rotateMatrix(matrixPtr, 5);
	printmatrix(matrixPtr, 5, 5);
}

