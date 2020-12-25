ejercicio 1 hoja 1 bidimensionales
*/
#include<iostream>
#include<conio.h>
using namespace std;
int IngresaPositivo()
{
int Num;
do
{
cout << "numero positivo:"; cin >> Num;
} while (Num <= 1 || Num > 10);
return Num;
}
void IngresaDatos(int N, int M, int **Matriz)
{
for (int i = 0; i < N; i++)
for (int j = 0; j< M; j++)
{
cout << "Ingrese dato " << i + 1 << "," << j + 1 << ":";
cin >> Matriz[i][j];
}
}
void ImprimirDatos(int N, int M, int **Matriz)
{
cout << endl << " DATOS DE LA MATRIZ" << endl;
for (int i = 0; i < N; i++)
{
for (int j = 0; j< M; j++)
cout << Matriz[i][j] << " ";
cout << endl;
}
}
void OperarionFila(int N, int M, int **Matriz)
{
int Sumai, Menori;
cout << endl << " RESULTADOS" << endl;
for (int i = 0; i < N; i++)
{
Sumai = 0;
Menori = Matriz[i][0];
for (int j = 0; j< M; j++)
{
Sumai = Sumai + Matriz[i][j];
if (Matriz[i][j] < Menori)
Menori = Matriz[i][j];
}
cout << "Suma la fila " << i + 1 << ":" << Sumai << endl;
cout << "El menor numero es de la fila " << i + 1 << ":" << Menori << endl;
}
}
int main()
{
int N, M;
cout << "Ingrese N ";
N = IngresaPositivo();
cout << "Ingrese M ";
M = IngresaPositivo();
int **Matriz;
Matriz = new int *[N];
for (int i = 0; i<N; i++)
Matriz[i] = new int[M];
IngresaDatos(N, M, Matriz);
ImprimirDatos(N, M, Matriz);
OperarionFila(N, M, Matriz);
for (int i = 0; i<N; i++)
delete[] Matriz[i];
delete[] Matriz;
_getch();
}