#include <iostream>
class Matrix
{
private:
	int** datos;
	int filas;
	int columnas;
public:
	// Constructor con dos parametros
	Matrix(int numFilas, int numColumnas);
	// Constructor por copia
	Matrix(const Matrix& other);
	// Asignacion sobrecarga
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix Suma(Matrix x);
	Matrix Resta(Matrix x);
	Matrix Multiplicacion(Matrix x, int filas, int columnas);
	void setDato(int f, int c, int valor);
	int getDato(int f, int c);
	int getFilas();
	int getColumnas();
	void Imprimir();
	// << sobrecargado
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m1);
};

