#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int numFilas, int numColumnas) {
	filas = numFilas;
	columnas = numColumnas;
	datos = new int* [filas];
	for (int i = 0; i < filas; ++i) {
		datos[i] = new int[columnas];
	}
	//cout << "Matriz creada con " << filas << " filas y " << columnas << " columnas." << endl;
}

Matrix::~Matrix() {
	/*for (int i = 0; i < filas; ++i) {
		delete[] datos[i]; // Liberar memoria de cada columna
	}
	delete[] datos; // Liberar memoria de las filas*/
}

Matrix Matrix::Suma(Matrix x) {
	Matrix R(getFilas(), getColumnas());
	// Recorrer ambas matrices y sumarlas
	for (int fil = 0; fil < getFilas(); ++fil) {
		for (int col = 0; col < getColumnas(); ++col) {
			R.datos[fil][col] = datos[fil][col] + x.datos[fil][col];
		}
	}
	return R;
}

Matrix Matrix::Resta(Matrix x) {
	Matrix R(getFilas(), getColumnas());
	// Recorrer ambas matrices y sumarlas suponiendo que ambas matrices son del mismo tamaño
	for (int fil = 0; fil < getFilas(); ++fil) {
		for (int col = 0; col < getColumnas(); ++col) {
			R.datos[fil][col] = datos[fil][col] - x.datos[fil][col];
		}
	}
	return R;
}

Matrix Matrix::Multiplicacion(Matrix x, int filas, int columnas) {
	Matrix R(filas, columnas);
	int c = 0, suma = 0;
	/*for (int fil1 = 0; fil1 < getFilas(); ++fil1) { // Ciclo fila matriz 1
		for (int col2 = 0; col2 < x.getColumnas(); ++col2) { // Ciclo columnas matriz 2
			for (int col1 = 0; col1 < getColumnas(); ++col1) { // Ciclo columnas matriz 1
				for (int fil2 = 0; fil2 < x.getFilas(); ++fil2) { // Ciclo filas matriz 2
					datoNuevo = datos[fil1][col1] * x.datos[fil2][col2];
					datoNuevo += datoNuevo;
				}
			}
			R.datos[fil1][col2] = datoNuevo;
			datoNuevo = 0;
		}
	}*/

	for (int i = 0; i < filas; ++i) {
		c = 0;
		while (c < columnas) {
			suma = 0;
			for (int j = 0; j < getColumnas(); ++j) {

			}
		}
	}

	return R; // Temporal
}

void Matrix::setDato(int f, int c, int valor) {
	if (f >= 0 && f < filas && c >= 0 && c < columnas) {
		datos[f][c] = valor;
	}
	else {
		cout << "Error: Fuera de rango." << endl;
	}
}

int Matrix::getDato(int f, int c) {
	if (f >= 0 && f < filas && c >= 0 && c < columnas) {
		return datos[f][c];
	}
	else {
		cout << "Error: Fuera de rango." << endl;
	}
}

int Matrix::getFilas() { return filas; }

int Matrix::getColumnas() { return columnas; }

void Matrix::Imprimir() {
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			cout << datos[i][j] << " ";
		}
		cout << endl;
	}
}