#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

class SistemaEcuaciones {
private:
    vector<vector<double>> matriz;
    int numFilas, numColumnas;
public:
    SistemaEcuaciones(int filas, int columnas)
        : numFilas(filas), numColumnas(columnas) {
        matriz.resize(filas, vector<double>(columnas, 0.0));
    }

    void ingresarValor(int fila, int columna, double valor) {
        if (fila < 0 || fila >= numFilas || columna < 0 || columna >= numColumnas) {
            throw out_of_range("Índice fuera de rango.");
        }
        matriz[fila][columna] = valor;
    }

    void gaussJordan() {
        for (int pivote = 0; pivote < numFilas; ++pivote) {
            double valorPivote = matriz[pivote][pivote];
            if (valorPivote == 0.0) {
                for (int i = pivote + 1; i < numFilas; ++i) {
                    if (matriz[i][pivote] != 0.0) {
                        swap(matriz[pivote], matriz[i]);
                        valorPivote = matriz[pivote][pivote];
                        break;
                    }
                }
            }
            if (valorPivote != 0.0) {
                for (int col = 0; col < numColumnas; ++col) {
                    matriz[pivote][col] /= valorPivote;
                }
            }
            for (int fila = 0; fila < numFilas; ++fila) {
                if (fila != pivote) {
                    double factor = matriz[fila][pivote];
                    for (int col = 0; col < numColumnas; ++col) {
                        matriz[fila][col] -= factor * matriz[pivote][col];
                    }
                }
            }
        }
    }

    double obtenerSolucion(int fila) const {
        if (fila < 0 || fila >= numFilas) {
            throw out_of_range("Índice fuera de rango.");
        }
        return matriz[fila][numColumnas - 1];
    }

    void mostrarMatriz() const {
        for (const auto& fila : matriz) {
            for (double val : fila) {
                cout << setw(10) << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int filas, columnas;
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    SistemaEcuaciones sistema(filas, columnas);

    cout << "Ingrese los coeficientes de la matriz aumentada:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            double valor;
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> valor;
            sistema.ingresarValor(i, j, valor);
        }
    }

    cout << "\nMatriz ingresada:\n";
    sistema.mostrarMatriz();

    sistema.gaussJordan();

    cout << "\nMatriz después de Gauss-Jordan:\n";
    sistema.mostrarMatriz();

    cout << "\nSoluciones:\n";
    for (int i = 0; i < filas; ++i) {
        cout << "X" << i + 1 << " = " << sistema.obtenerSolucion(i) << endl;
    }

    return 0;
}
