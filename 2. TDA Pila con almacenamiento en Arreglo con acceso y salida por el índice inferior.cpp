#include <iostream>
using namespace std;

class PilaArrInf{
private:
    int* arr;
    int fondo;
    int capacidad;

public:
    PilaArrInf(int size){
        arr = new int[size];
        capacidad = size;
        fondo = 0;
    }

    ~PilaArrInf(){
        delete[] arr;
    }

    void push(int data){
        if (isFull()){
            cout<<"Pila llena.\n";
            return;
        }
        arr[fondo++] = data;
    }

    int pop(){
        if(isEmpty()){
            cout << "Pila vacía.\n";
            return -1;
        }
        return arr[--fondo];
    }

    int peek(){
        if(isEmpty()){
            cout<<"Pila vacía.\n";
            return -1;
        }
        return arr[fondo - 1];
    }

    int count(){
        return fondo;
    }

    bool isFull(){
        return fondo == capacidad;
    }

    bool isEmpty(){
        return fondo == 0;
    }
};

int main(){
	
    PilaArrInf pila(5);
    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout<<"El tope de la pila es: "<<pila.peek()<<endl; 
    pila.pop();
    cout<<"El tope de la pila despues de pop es: "<<pila.peek()<<endl;

    cout<<"El tamano de la pila es: "<<pila.count()<<endl;
    return 0;
}
