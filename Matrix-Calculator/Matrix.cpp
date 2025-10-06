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
	cout << "Matriz creada con " << filas << " filas y " << columnas << " columnas." << endl;
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
	for (int col = 0; col < getFilas(); ++col) {
		for (int fil = 0; fil < getColumnas(); ++fil) {
			R.datos[col][fil] = datos[col][fil] + x.datos[col][fil];
		}
	}
	return R;
}

Matrix Matrix::Resta(Matrix x) {
	return x; // Temporal
}

Matrix Matrix::Multiplicacion(Matrix x) {
	return x; // Temporal
}

void Matrix::setDato(int f, int c, int valor) {
	if (f >= 0 && f < filas && c >= 0 && c < columnas) {
		datos[f][c] = valor;
	}
	else {
		cerr << "Error: Fuera de rango." << endl;
	}
}

int Matrix::getDato(int f, int c) {
	if (f >= 0 && f < filas && c >= 0 && c < columnas) {
		return datos[f][c];
	}
	else {
		cerr << "Error: Fuera de rango." << endl;
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