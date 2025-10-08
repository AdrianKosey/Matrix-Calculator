#include <iostream>
#include "Matrix.h"
using namespace std;

int main(void)
{
	int nColum1 = 0, nFilas1 = 0, nColum2 = 0, nFilas2 = 0, dato = 0;
	char opcion;
	cout << "============= Elige la operacion a realizar ==============" << endl;
	cout << "A) Suma" << endl << "B) Resta" << endl << "C) Multiplicacion" << endl;
	cin >> opcion;
	opcion = toupper(opcion);
	cout << "================== Tamaño de Matrices  ===================" << endl;
	cout << "Cantidad de filas de la matriz 1: ";
	cin >> nFilas1;
	cout << "Cantidad de columnas de la matriz 1: ";
	cin >> nColum1; cout << endl;
	cout << "Cantidad de filas de la matriz 2: ";
	cin >> nFilas2;
	cout << "Cantidad de columnas de la matriz 2: ";
	cin >> nColum2;
	cout << "=================== Rellenar Matrices ===================" << endl;
	Matrix A(nFilas1, nColum2), B(nFilas1, nColum2);
	cout << "Matriz 1" << endl;
	for (int i = 0; i < nFilas1; ++i) {
		for (int j = 0; j < nColum1; ++j) {
			cout << "Dato[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> dato;
			A.setDato(i, j, dato);
		}
	}
	cout << endl << "Matriz 2" << endl;
	for (int i = 0; i < nFilas2; ++i) {
		for (int j = 0; j < nColum2; ++j) {
			cout << "Dato[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> dato;
			B.setDato(i, j, dato);
		}
	}
	cout << "======================= Resultado =======================" << endl;
	switch (opcion)
	{
	case 'A':
		if (nFilas1 == nFilas2 && nColum1 == nColum2) {
			Matrix R(nFilas1, nColum1);
			R = A.Suma(B);
			A.Imprimir();
			cout << endl << " + " << endl << endl;
			B.Imprimir(); cout << endl;
			R.Imprimir();
		}
		else cout << "ERROR: No se pueden sumar matrices de diferente tamanio" << endl;
		break;
	case 'B':
		if (nFilas1 == nFilas2 && nColum1 == nColum2) {
			Matrix R(nFilas1, nColum1);
			R = A.Resta(B);
			A.Imprimir();
			cout << endl << " - " << endl << endl;
			B.Imprimir(); cout << endl;
			R.Imprimir();
		}
		else cout << "ERROR: No se pueden restar matrices de diferente tamanio" << endl;
		break;
	case 'C':
		if (nColum1 == nFilas2) {
			Matrix R(nFilas1, nColum2);
			R = A.Multiplicacion(B, nFilas1, nColum2);
			A.Imprimir();
			cout << endl << " x " << endl << endl;
			B.Imprimir(); cout << endl;
			R.Imprimir();
			break;
		}
		else cout << "ERROR: Requiere que el numero de columnas de la primera matriz sea igual al numero de filas de la segunda matriz" << endl;
	default:
		break;
	}
}