#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("result.txt");

void in(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> matrix[i][j];
}

void out(int **matrix, int n)
{
	for(int i = 0; i < n; i++, fout << endl)
		for(int j = 0; j < n; j++)
			fout << matrix[i][j] << " ";
	fout << endl;
}

int op1(int **matrix, int n)
{
	int stolbec;
	if (n % 5 != 0)
		stolbec = n / 5 + 1;
	else
		stolbec = n / 5;
	for (int i = 0; i < n; ++i)
	{
		matrix[i][stolbec - 1] = matrix[i][stolbec - 1] * 2;
	}
	return **matrix;
}

int op2(int **matrix, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 != 0 && j % 2 != 0) {
				if (matrix[i][j] % 2 == 0) {
					matrix[i][j] = matrix[i][j] / 2;
				}
			}
		}
	}
	return **matrix;
}


bool AE(int **matrix, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((matrix[i][j] > 0 && matrix[i][j] % 6 == 0) || matrix[i][j] < -100) {
				count += 1;
				j = n;
			}
		}
	}
	if (count == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int statement_true(int **A, int **B, int **C, int n)
{
	int i, j;
	op1(B, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = A[i][j] * 4;
			C[i][j] = B[i][j] + A[i][j];
		}
	}
	return **C;
}

int statement_false(int **A, int **B, int **C, int n)
{
	int i, j, k;
	op2(A, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			B[i][j] = B[i][j] * -1;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				C[i][j] += (B[i][k] * A[k][j]);
			}
		}
	}
	return **C;
}


int main()
{
	int n, m, i = 0, j = 0;
	
	cout << "Type in n: " << endl;
	cin >> n;

	int **A;
	A = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	// input of elements of matrix a
	in(A, n);

	int **B;
	B = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		B[i] = new int[n];
	}
	// input of elements of matrix a
	in(B, n);

	int **C;
	C = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		C[i] = new int[n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}

	if (AE(B, n))
	{
		statement_true(A, B, C, n);
		out(C, n);
	}
	else 
	{
		statement_false(A, B, C, n);
		out(C, n);
	}
}