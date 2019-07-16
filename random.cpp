// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>

#define _USE_MATH_DEFINES
#include<math.h>
#include<cstdlib>
#include<ctime>
#include <sstream>
using namespace std;
int main()
{
	int a = 11;
	int b = 25;
	int c = 43;
	long long int q, w, e;
	long long int aa;
	int m = 100000;
	long long int a1, a2, a3;
	int n = 20;
	long long int *A = new long long int[n];
	long int  Q[30];
	long long int *R = new long long int[n];
	for (int i = 0; i < n; i++)
	{
		R[i] = 0;
	}
	srand(time(NULL));
	string s;
	stringstream ss(s);
	
	    A[0] = (int)rand() ;
		A[1] = (int)rand() ;
		A[2] = (int)rand() ;
		for (int i = 3; i < n; i++)
		{
			A[i] = 0;
		}

		for (int i = 3; i < n; i++) {

			a1 = a * A[i - 1];
			a2 = b * A[i - 2] * A[i - 2];
			//cout << "a2 " << a2 << endl;

			int t = 0;
			aa = a2;
			while (aa) {
				aa /= 10;
				t++;
			}

			for (int i = 0; i < t; i++)
			{

				q = (pow(10, t - i - 1));
				Q[i] = (a2 / q) % (10);
			}

			for (int j = 0; j < 4; j++)
			{
				q = Q[0];
				for (int i = 0; i < t - 1; i++)
				{

					Q[i] = Q[i + 1];

				}
				Q[t - 1] = q;
			}

			a2 = 0;
			for (int i = 0; i < t; i++)
			{
				a2 = a2 + Q[i] * pow(10, t - 1 - i);

			}
			//cout << "a2* " << a2 << endl;



			a3 = c * A[i - 3];
			t = 0;
			aa = a3;
			//cout<<"a3 " << a3<<endl;
			while (aa) {
				aa /= 10;
				t++;
			}

			for (int i = 0; i < t; i++)
			{

				q = (pow(10, t - i - 1));
				Q[i] = (a3 / q) % (10);
			}
			for (int j = 0; j < 2; j++)
			{
				q = Q[t - 1];
				for (int i = t - 1; i > 0; i--)
				{

					Q[i] = Q[i - 1];
				}

				Q[0] = q;
			}
			a3 = 0;
			for (int i = 0; i < t; i++)
			{
				a3 = a3 + Q[i] * pow(10, t - 1 - i);

			}


			//cout <<"a3* "<< a3<<endl;


			A[i] = (a1 + a2 + a3) % m;

		}
		for (int i = 0; i < n; i++) { cout << A[i] << " ";}cout << endl;
		int mat=0;
		
		for (int i = 0; i < n; i++) 
		{
			mat += A[i] / n;

		}
		cout << "mato = "<<mat << endl;
		int dis = 0;
		for (int i = 0; i < n; i++)
		{
			
			dis +=(pow( (A[i]-mat),2 ))/ n;
			
		}
		cout << "dis = " << dis << endl;
		float min = 32000;
		float max = -32000;
		for (int i = 0; i < n; i++)
		{
			if (A[i] > max)max = A[i];
			if (A[i] < min)min = A[i];
		}

		cout << min << "  " << max<<endl;

		float u = 10;
		float l = (max - min) / u;
		

		
		
		for (int i = 1; i < u+1; i++)
		{	
			for (int j = 0; j < n; j++)
			{
				if ((A[j] <= min + l * i) and (A[j]>=min+l*(i-1))) { R[i-1]++; };
			}
			
		}
		for (int i = 0; i < u; i++)
		{
			cout << R[i] << " ";
		}
		ofstream fout;
		fout.open("file.txt");
		for (int i = 0; i < u; i++)
		{
			fout << R[i] << endl;
		}
		fout.close();

		float ksi = 0;
		cout << endl;
		
		for (int i = 0; i < u; i++)
		{
			float t =  n*(R[i] / u);
			
			if (R[i] != 0) {
				ksi += pow(R[i] - n * (R[i] / u), 2)/t;
			}
			//cout << pow(R[i] - n * (R[i] / u), 2) << "   " << t << endl;
			
		}
		cout << "hi = " << ksi << endl;





	delete[] A;
	delete[] R;
	
}
