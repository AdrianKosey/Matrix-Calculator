#include <iostream>
#include "Matrix.h"
using namespace std;

int main(void)
{
    cout << "Calculadora de matrices\n";
    Matrix A(8, 8), B(8, 8), R(8, 8);
	// Para la prueba llenamos los dos arreglos con valores fijos
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			A.setDato(i, j, 1);
			B.setDato(i, j, 3);
		}
	}
	R = A.Suma(B);
	A.Imprimir(); cout << endl;
	B.Imprimir(); cout << endl;
    R.Imprimir();
}
