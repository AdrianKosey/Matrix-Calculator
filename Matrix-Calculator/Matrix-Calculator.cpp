#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mostrarMenu() {
    cout << "\n+==============================================+\n";
    cout << "|      CALCULADORA DE MATRICES EN C++          |\n";
    cout << "+==============================================+\n";
    cout << "| A) Suma de matrices                          |\n";
    cout << "| B) Resta de matrices                         |\n";
    cout << "| C) Multiplicacion de matrices                |\n";
    cout << "+==============================================+\n";
    cout << "Seleccione una opcion: ";
}

void ingresarMatrizVisual(Matrix& M, const string& nombre, int startX = 5, int startY = 5) {
    int filas = M.getFilas();
    int columnas = M.getColumnas();

    system("cls");
    cout << "Ingrese los valores para " << nombre << ":\n";

    // Dibujar cuadrícula
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            gotoxy(startX + j * 6, startY + i * 2);
            cout << "[    ]";
        }
    }

    // Ingresar valores
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            gotoxy(startX + j * 6 + 1, startY + i * 2);
            int valor;
            cin >> valor;
            M.setDato(i, j, valor);
        }
    }

    system("cls");
}


int main() {
    char opcion;
    int f1, c1, f2, c2;

    mostrarMenu();
    cin >> opcion;
    opcion = toupper(opcion);

    // Validación anticipada
    bool dimensionesValidas = false;
    switch (opcion) {
    case 'A':
    case 'B':
        cout << endl << "Ingrese dimensiones de las matrices:" << endl;
        cout << "Filas de matriz A: "; cin >> f1;
        cout << "Columnas de matriz A: "; cin >> c1;
        cout << "Filas de matriz B: "; cin >> f2;
        cout << "Columnas de matriz B: "; cin >> c2;
        dimensionesValidas = (f1 == f2 && c1 == c2);
        if (!dimensionesValidas)
            cout << endl << "ERROR: Para suma/resta, ambas matrices deben tener el mismo tamanio." << endl;
        break;
    case 'C':
        cout << endl << "Ingrese dimensiones de las matrices:" << endl;
        cout << "Filas de matriz A: "; cin >> f1;
        cout << "Columnas de matriz A: "; cin >> c1;
        cout << "Filas de matriz B: "; cin >> f2;
        cout << "Columnas de matriz B: "; cin >> c2;
        dimensionesValidas = (c1 == f2);
        if (!dimensionesValidas)
            cout << endl << "ERROR: Para multiplicacion, columnas de A deben igualar filas de B." << endl;
        break;
    default:
        cout << endl << "Opcion invalida." << endl;
        return 1;
    }

    if (!dimensionesValidas) return 1;

    // Crear matrices
    Matrix A(f1, c1), B(f2, c2);
    ingresarMatrizVisual(A, "Matriz A");
    ingresarMatrizVisual(B, "Matriz B");

    cout << endl << "Resultado:" << endl;
    Matrix R(1, 1); // Inicialización temporal

    switch (opcion) {
    case 'A':
        R = A.Suma(B);
        A.Imprimir(); cout << "\n + \n\n"; B.Imprimir(); cout << "\n = \n\n"; R.Imprimir();
        break;
    case 'B':
        R = A.Resta(B);
        A.Imprimir(); cout << "\n - \n\n"; B.Imprimir(); cout << "\n = \n\n"; R.Imprimir();
        break;
    case 'C':
        R = A.Multiplicacion(B, f1, c2);
        A.Imprimir(); cout << "\n x \n\n"; B.Imprimir(); cout << "\n = \n\n"; R.Imprimir();
        break;
    }

    cout << endl << "Operacion completada." << endl;
    return 0;
}