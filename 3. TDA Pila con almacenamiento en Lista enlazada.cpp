#include <iostream>
using namespace std;

class Nodo{
public:
    int data;
    Nodo* siguiente;

    Nodo(int data) : data(data), siguiente(nullptr){}
};

class PilaLista{
private:
    Nodo* tope;
    int tamano;

public:
    PilaLista() : tope(nullptr), tamano(0){}

    void push(int data){
        Nodo* nuevoNodo = new Nodo(data);
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
        tamano++;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Pila vacía.\n";
            return -1;
        }
        int valor = tope->data;
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
        tamano--;
        return valor;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Pila vacía.\n";
            return -1;
        }
        return tope->data;
    }

    int count(){
        return tamano;
    }

    bool isEmpty(){
        return tope == nullptr;
    }
};

int main(){
	
    PilaLista pila;
    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout<<"El tope de la pila es: "<<pila.peek()<<endl; 
    pila.pop();
    cout<<"El tope de la pila despues de pop es: "<<pila.peek()<< endl; 

    cout<<"El tamano de la pila es: "<<pila.count()<<endl;

    return 0;
}
