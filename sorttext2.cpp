
#include "pch.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<cstdlib>
#include<ctime>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
#include <iostream>
using namespace std;
//функция, сливающая массивы
void Merge(string *A, int first, int last)
{
	int middle, start, final, j;
	string *mas =  new string[100];
	middle = (first + last) / 2; //вычисление среднего элемента
	start = first; //начало левой части
	final = middle + 1; //начало правой части
	for (j = first; j <= last; j++) //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (A[start].length() < A[final].length())))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	//возвращение результата в список
	for (j = first; j <= last; j++) A[j] = mas[j];
	delete[]mas;
};
//рекурсивная процедура сортировки
void MergeSort(string *A, int first, int last)
{
	{
		if (first < last)
		{
			MergeSort(A, first, (first + last) / 2); //сортировка левой части
			MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
			Merge(A, first, last); //слияние двух частей
		}
	}
};
//главная функция
void main()
{
	ofstream fout;
	ofstream fout2;
	ifstream fina;

	fina.open("text.txt");
	

	string a, b, c;
	int j = 0;
	int k = 0;
	int ns = 0;
	int n1, n;
	int ii = 0;

	while (!fina.eof())
	{
		fina >> a;
		
		ns++;

	}
	//cout << ns << endl;
	fina.clear();
	fina.seekg(0);
	string *s = new string[ns];
	j = 0;
	while (!fina.eof())
	{

		fina >> a;
		s[j] = a;
		j++;
	}
	fina.clear();
	fina.seekg(0);
	
	MergeSort(s, 0, ns-1); //вызов сортирующей процедуры
	
	for (int i = 0; i < ns; i++) cout << s[i] << " ";
	
	



	fina.close();


}


