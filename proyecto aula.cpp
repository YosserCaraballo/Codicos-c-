/*
yosser jose caraballo julio   T00078120
sebastian paternina           T00078378
jesus velaz                   T00078789
jean carlos

*/

#include <iostream>
#include <vector>
#include <iomanip> // Para formatear la salida
#include <stdexcept>

class SistemaEcuaciones {
private:
    std::vector<std::vector<double>> matriz;
    int numFilas, numColumnas;

public:
    SistemaEcuaciones(int filas, int columnas)
        : numFilas(filas), numColumnas(columnas) {
        matriz.resize(filas, std::vector<double>(columnas, 0.0));
    }

    void ingresarValor(int fila, int columna, double valor) {
        if (fila < 0 || fila >= numFilas || columna < 0 || columna >= numColumnas) {
            throw std::out_of_range("Índice fuera de rango.");
        }
        matriz[fila][columna] = valor;
    }

    void gaussJordan() {
        for (int pivote = 0; pivote < numFilas; ++pivote) {
            double valorPivote = matriz[pivote][pivote];
            if (valorPivote == 0.0) {
                for (int i = pivote + 1; i < numFilas; ++i) {
                    if (matriz[i][pivote] != 0.0) {
                        std::swap(matriz[pivote], matriz[i]);
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
            throw std::out_of_range("Índice fuera de rango.");
        }
        return matriz[fila][numColumnas - 1];
    }

    void mostrarMatriz() const {
        for (const auto& fila : matriz) {
            for (double val : fila) {
                std::cout << std::setw(10) << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int filas, columnas;

    std::cout << "Ingrese el numero de filas: ";
    std::cin >> filas;
    std::cout << "Ingrese el numero de columnas: ";
    std::cin >> columnas;

    SistemaEcuaciones sistema(filas, columnas);

    std::cout << "Ingrese los coeficientes de la matriz aumentada:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            double valor;
            std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> valor;
            sistema.ingresarValor(i, j, valor);
        }
    }

    std::cout << "\nMatriz ingresada:\n";
    sistema.mostrarMatriz();

    sistema.gaussJordan();

    std::cout << "\nMatriz después de Gauss-Jordan:\n";
    sistema.mostrarMatriz();

    std::cout << "\nSoluciones:\n";
    for (int i = 0; i < filas; ++i) {
        std::cout << "X" << i + 1 << " = " << sistema.obtenerSolucion(i) << std::endl;
    }

    return 0;
}
