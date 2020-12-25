#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;
using namespace System;

void ingresadatos(int *n, int *m, int **simetrica)
{
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *m; j++)
		{
			cout << "ingrese dato [" << i + 1 << "],[" << j + 1 << "]:";
			cin >> simetrica[i][j];
		}
}

void salidadatos(int *n, int *m, int **simetrica)
{
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *m; j++)
			cout << simetrica[i][j] << " ";
		cout << endl;
	}
}

void validacionsimetrica(int *n, int *m, int **simetrica)
{
	
	int  menor;
	int suma;

	for (int i = 0; i < *n; i++)
	{
		suma = 0;
		menor = simetrica[i][0];
		for (int j = 0; j < *m; j++)
		{
			suma = suma + simetrica[i][j];
			if (simetrica[i][j] < menor)
				menor = simetrica[i][j];
		}
			cout << "la suma de la fila " << i+1 << "es"<<suma<<endl;
			cout << "El menor valor de la fila es" << i + 1 << "es" << menor << endl;
			
	}


}

void promymayorvalorcolumna(int *n, int *m, int **simetrica)
{

	int  mayor;
	int promedio;
	int suma;

	for (int j = 0; j < *n; j++)
	{
		suma = 0;
		mayor = simetrica[0][j];
		for (int i = 0; i < *m; i++)
		{
			suma = suma + simetrica[i][j];
			promedio = suma / (*n);

			if (simetrica[i][j] > mayor)
				mayor = simetrica[i][j];
		}
		cout << "la suma de la columna " << j + 1 << "es" << promedio << endl;
		cout << "El mayor valor de la columna es" << j+ 1 << "es" << mayor << endl;

	}


}

void mayorvalor(int *n, int *m, int **simetrica)
{
	int posc, posf;
	int  mayor;
	posc, posf = 0;

	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *m; j++)
			if (simetrica[i][j] > mayor)
			{
				mayor = simetrica[i][j];
				posc = j;
				posf = i;

			}


	cout << "el mayor valor de la matriz es" << mayor << endl;
	cout << "el dato se encuentra en la fila " << posf + 1 << "y la columna :" << posc + 1 << endl;
}


int main()
{
	int n, m;
	cout << "ingresa filas"; cin >> n;
	cout << "ingresa columnas"; cin >> m;
	int **simetrica;
	simetrica = new int *[n];
	for (int i = 0; i < n; i++)
		simetrica[i] = new int[m];
	ingresadatos(&n,&m,simetrica);
	salidadatos(&n, &m, simetrica);
	validacionsimetrica(&n, &m, simetrica);
	mayorvalor(&n, &m, simetrica);
	promymayorvalorcolumna(&n, &m, simetrica);
	_getch();

}