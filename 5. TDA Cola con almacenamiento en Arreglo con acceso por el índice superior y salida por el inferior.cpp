#include <iostream>
using namespace std;

class ColaArrSupInf{
private:
    int* arr;
    int frente, fondo;
    int capacidad;

public:
    ColaArrSupInf(int size){
        arr = new int[size];
        capacidad = size;
        frente = size - 1;
        fondo = size - 1;
    }

    ~ColaArrSupInf(){
        delete[] arr;
    }

    void enqueue(int data){
        if (isFull()){
            cout<<"Cola llena.\n";
            return;
        }
        arr[frente--] = data;
    }

    int dequeue(){
        if (isEmpty()){
            cout<<"Cola vacía.\n";
            return -1;
        }
        return arr[--fondo];
    }

    int peek(){
	
        if (isEmpty()) {
            cout << "Cola vacía.\n";
            return -1;
        }
        return arr[fondo - 1];
    }

    int count(){
        return capacidad - fondo;
    }

    bool isFull(){
        return frente == -1;
    }

    bool isEmpty(){
        return fondo == capacidad;
    }
};

int main(){
    ColaArrSupInf cola(5);
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);

    cout<<"Frente de la cola es: "<<cola.peek()<<endl;
    cola.dequeue();
    cout<<"Frente de la cola despues del pop es: "<<cola.peek()<<endl; 

    cout<<"El tamano de la cola es: "<<cola.count()<<endl;

    return 0;
}
