class Matrix
{
private:
	int** datos;
	int filas;
	int columnas;
public:
	Matrix(int numFilas, int numColumnas);
	~Matrix();
	Matrix Suma(Matrix x);
	Matrix Resta(Matrix x);
	Matrix Multiplicacion(Matrix x);
	void setDato(int f, int c, int valor);
	int getDato(int f, int c);
	int getFilas();
	int getColumnas();
	void Imprimir();
};

