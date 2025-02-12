#include <iostream>
using namespace std;

class ColaArrInfSup{
private:
    int* arr;
    int frente, fondo;
    int capacidad;

public:
    ColaArrInfSup(int size){
        arr = new int[size];
        capacidad = size;
        frente = 0;
        fondo = 0;
    }

    ~ColaArrInfSup(){
        delete[] arr;
    }

    void enqueue(int data) {
        if (isFull()){
            cout<<"Cola llena.\n";
            return;
        }
        arr[fondo++] = data;
    }

    int dequeue(){
        if (isEmpty()){
            cout<<"Cola vacía.\n";
            return -1;
        }
        return arr[frente++];
    }

    int peek(){
        if (isEmpty()){
            cout<<"Cola vacía.\n";
            return -1;
        }
        return arr[frente];
    }

    int count(){
        return fondo - frente;
    }

    bool isFull(){
        return fondo == capacidad;
    }

    bool isEmpty(){
        return frente == fondo;
    }
};

int main(){
    ColaArrInfSup cola(5);
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);

    cout<<"Frente de la cola es: "<<cola.peek()<<endl;
    cola.dequeue();
    cout<< "Frente de la cola despues de dequeue es: "<< cola.peek()<<endl; 

    cout<<"El tamano de la cola es: "<<cola.count()<<endl;

    return 0;
}
