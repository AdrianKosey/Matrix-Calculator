#include "Matrix.h"
#include <iostream>
#include <iomanip> // Para alinea los numeros dentro de los corchete

using namespace std;

Matrix::Matrix(int numFilas, int numColumnas) {
	filas = numFilas;
	columnas = numColumnas;
	datos = new int* [filas];
	for (int i = 0; i < filas; ++i) {
		datos[i] = new int[columnas];
	}
	//cout << "Constructor con dos parametros llamado" << endl;
}

Matrix::Matrix(const Matrix& other) {
	filas = other.filas;
	columnas = other.columnas;

	datos = new int* [filas];
	for (int i = 0; i < filas; ++i) {
		datos[i] = new int[columnas];
		for (int j = 0; j < columnas; ++j) {
			datos[i][j] = other.datos[i][j]; // Copia profunda
		}
	}
	//cout << "Constructor por copia llamado" << endl;
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this == &other) return *this; // Evita autoasignacion

	// Liberar memoria existente
	for (int i = 0; i < filas; ++i) {
		delete[] datos[i];
	}
	delete[] datos;

	// Copiar dimensiones
	filas = other.filas;
	columnas = other.columnas;

	// Asignar nueva memoria y copiar datos
	datos = new int* [filas];
	for (int i = 0; i < filas; ++i) {
		datos[i] = new int[columnas];
		for (int j = 0; j < columnas; ++j) {
			datos[i][j] = other.datos[i][j];
		}
	}
	//cout << "Operador de asignacion sobrecargado usado" << endl;
	return *this;
}

Matrix::~Matrix() {
	for (int i = 0; i < filas; ++i) {
		delete[] datos[i]; // Liberar memoria de cada columna
	}
	delete[] datos; // Liberar memoria de las filas
	//cout << "Objeto destruido" << endl;
}

Matrix Matrix::Suma(Matrix x) {
	Matrix R(getFilas(), getColumnas());
	// Recorrer ambas matrices y las suma
	for (int fil = 0; fil < getFilas(); ++fil) {
		for (int col = 0; col < getColumnas(); ++col) {
			R.datos[fil][col] = datos[fil][col] + x.datos[fil][col];
		}
	}
	//cout << "Retornando objeto" << endl;
	return R;
}

Matrix Matrix::Resta(Matrix x) {
	Matrix R(getFilas(), getColumnas());
	// Recorrer ambas matrices y las resta
	for (int fil = 0; fil < getFilas(); ++fil) {
		for (int col = 0; col < getColumnas(); ++col) {
			R.datos[fil][col] = datos[fil][col] - x.datos[fil][col];
		}
	}
	return R;
}

Matrix Matrix::Multiplicacion(Matrix x, int filas, int columnas) {
	Matrix R(filas, columnas);
	for (int i = 0; i < getFilas(); ++i) {
		for (int j = 0; j < x.getColumnas(); ++j) {
			R.datos[i][j] = 0;
			for (int k = 0; k < getColumnas(); ++k) {
				R.datos[i][j] += datos[i][k] * x.datos[k][j];
			}
		}
	}
	return R;
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
			cout << "[" << setw(4) << datos[i][j] << "] ";
		}
		cout << endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Matrix& m1) {
	for (int i = 0; i < m1.filas; ++i) {
		for (int j = 0; j < m1.columnas; ++j) {
			out << "[" << setw(4) << m1.datos[i][j] << "] ";
		}
		out << endl;
	}
	return out;
}