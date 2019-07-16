#include "pch.h"
#include <iostream>
#include <fstream>

#include <iomanip>
#define _USE_MATH_DEFINES
#include<math.h>
#include<cstdlib>
#include<ctime>
#include <sstream>
using namespace std;

int main()
{
	float a, b, c,p;

	int n =20;
	int **T =new int*[2];
	float *R = new  float[n*(n-1)*(n-2)];
	T[0] = new int[n];
	T[1] = new int[n];



	int **A = new int*[2];
	A[0] = new int[n*(n - 1)*(n - 2)];
	A[1] = new int[n*(n - 1)*(n - 2)];

	int **B = new int*[2];
	B[0] = new int[n*(n - 1)*(n - 2)];
	B[1] = new int[n*(n - 1)*(n - 2)];

	int **C = new int*[2];
	C[0] = new int[n*(n - 1)*(n - 2)];
	C[1] = new int[n*(n - 1)*(n - 2)];
	
	srand(time(NULL));
	for (int i=0; i < n; i++)
	{
		T[0][i] = (int)rand() % 100;
		T[1][i] = (int)rand() % 100;
		cout << T[0][i] << "   ";
	}
	cout << endl;



	for (int i = 0; i < n; i++)
		cout << T[1][i] << "   ";
	cout << endl;
	cout << endl;


	int k = 0;
	int m = 0;
	for (int t1 = 0; t1 < n; t1++)
	{
		
		for (int t2 = 0; t2 < n; t2++)
		{
			for (int t3 = 0; t3 < n; t3++)
			{
				if ((t3 != t2) and (t3 != t1) and (t2 != t1))
				{
					A[0][m] = T[0][t1];
					A[1][m] = T[1][t1];

					B[0][m] = T[0][t2];
					B[1][m] = T[1][t2];

					C[0][m] = T[0][t3];
					C[1][m] = T[1][t3];

					m++;
				}
				
			}
		}
	}
	

	
/*for (int i = 0; i < 30; i++)
	cout << A[0][i] << "   ";
cout << endl;
for (int i = 0; i < 30; i++)
	cout << A[1][i] << "   ";
cout << endl;
for (int i = 0; i < 30; i++)
	cout << B[0][i] << "   ";
cout << endl;
for (int i = 0; i < 30; i++)
	cout << B[1][i] << "   ";
cout << endl;
for (int i = 0; i < 30; i++)
	cout << C[0][i] << "   ";
cout << endl;
for (int i = 0; i < 30; i++)
	cout << C[1][i] << "   ";
cout << endl;*/

	for (int i = 0; i < m; i++)
	{
		a = sqrt(abs(A[0][i]- B[0][i]) ^ 2 + abs(A[1][i]- B[1][i]) ^ 2);
		b = sqrt(abs(B[0][i] - C[0][i]) ^ 2 + abs(B[1][i] - C[1][i]) ^ 2);
		c = sqrt(abs(A[0][i] - C[0][i]) ^ 2 + abs(A[1][i] - C[1][i]) ^ 2);
		p = (a + b + c) / 2;
		R[i] = sqrt(abs(p-a)*abs(p-b)*abs(p-c)*p);

		
		cout <<  R[i] << "   ";
	}

	cout << endl;
	cout << m;





	
} 

