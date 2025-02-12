#include <iostream>
using namespace std;

class Cola {
private:
    int* elementos;
    int capacidad, inicio, fin, numElementos;

    void redimensionar() {
        int* nuevoArray = new int[capacidad * 2];
        for (int i = 0; i < numElementos; i++)
            nuevoArray[i] = elementos[(inicio + i) % capacidad];
        delete[] elementos;
        elementos = nuevoArray;
        capacidad *= 2;
        inicio = 0;
        fin = numElementos;
    }

public:
    Cola(int cap = 10) : capacidad(cap), inicio(0), fin(0), numElementos(0) {
        elementos = new int[capacidad];
    }
    
    ~Cola() { delete[] elementos; }

    bool empty() { return numElementos == 0; }
    
    void push(int valor) {
        if (numElementos == capacidad) redimensionar();
        elementos[fin] = valor;
        fin = (fin + 1) % capacidad;
        numElementos++;
    }
    
    void pop() { if (!empty()) { inicio = (inicio + 1) % capacidad; numElementos--; } }
    
    int front() { return empty() ? -1 : elementos[inicio]; }

    // Añadido para facilitar la ordenación: permite sacar el elemento por índice
    int getElementAt(int idx) {
        return elementos[(inicio + idx) % capacidad];
    }

    void setElementAt(int idx, int value) {
        elementos[(inicio + idx) % capacidad] = value;
    }

    int size() {
        return numElementos;
    }
};

// Función para ordenar usando un simple algoritmo de burbuja
void ordenarCartas(Cola& cartas) {
    int n = cartas.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cartas.getElementAt(j) > cartas.getElementAt(j + 1)) {
                // Intercambiar
                int temp = cartas.getElementAt(j);
                cartas.setElementAt(j, cartas.getElementAt(j + 1));
                cartas.setElementAt(j + 1, temp);
            }
        }
    }

    // Imprimir cartas ordenadas
    cout << "Cartas ordenadas: ";
    while (!cartas.empty()) {
        cout << cartas.front() << " ";
        cartas.pop();
    }
    cout << endl;
}

int main() {
    Cola cartas;
    int numeroDeCartas, valor;
    cout << "¿Cuántas cartas quieres agregar? "; cin >> numeroDeCartas;
    for (int i = 0; i < numeroDeCartas; i++) {
        cout << "Ingresa el valor de la carta " << i + 1 << ": "; cin >> valor;
        cartas.push(valor);
    }
    ordenarCartas(cartas);
    return 0;
}
