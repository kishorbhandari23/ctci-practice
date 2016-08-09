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

void makeRowZero(int*matrix, int row, int column, int row_zero)
{
	for (int i = 0; i < column; i++)
		matrix[row_zero*column + i] = 0;

}

void makeColZero(int*matrix, int row, int column, int col_zero)
{
	for (int i = 0; i < row; i++)
		matrix[i*column + col_zero] = 0;

}

void make_zero(int* matrix, int row, int column)
{
	bool firstRowHasZero = false, firstColHasZero = false;
	for (int i = 0; i < column; i++)
	{
		if (matrix[column] == 0)
			firstRowHasZero = true;
	}

	for (int i = 0; i < row; i++)
	{
		if (matrix[i*column] == 0)
			firstColHasZero = true;
	}

	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < column; j++)
		{
			if (matrix[i*column + j] == 0)
			{
				matrix[j] = 0; //column
				matrix[i*column] = 0; //row
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		if (matrix[i*column] == 0)
			makeRowZero(matrix,row, column,i);
	}

	for (int i = 0; i < column; i++)
	{
		if (matrix[i] == 0)
			makeColZero(matrix, row, column, i);
	}

	if(firstRowHasZero)
		makeRowZero(matrix, row, column, 0);

	if (firstColHasZero)
		makeColZero(matrix, row, column, 0);

}

int main()
{	

	int matrix[5][4] = { {1,2,3,4},{5,0,7,8},{9,10,11,12},{13,14,0,16},{17,18,19,20}};
	int* matrixPtr = (int*)matrix;
	cout << "Original Matrix" << endl;
	printmatrix(matrixPtr, 5, 4);
	make_zero(matrixPtr, 5, 4);
	cout << "Changed Matrix" << endl;
	printmatrix(matrixPtr, 5, 4);

}