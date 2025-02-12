#include <iostream>
using namespace std;

class NodoCola{
public:
    int data;
    NodoCola* siguiente;

    NodoCola(int data) : data(data), siguiente(nullptr){}
};

class ColaLista{
private:
    NodoCola* frente;
    NodoCola* fondo;
    int tamano;

public:
    ColaLista() : frente(nullptr), fondo(nullptr),tamano(0){}

    void enqueue(int data){
        NodoCola* nuevoNodo = new NodoCola(data);
        if (isEmpty()){
            frente = fondo = nuevoNodo;
        } else {
            fondo->siguiente = nuevoNodo;
            fondo = nuevoNodo;
        }
        tamano++;
    }

    int dequeue(){
        if (isEmpty()){
            cout << "Cola vacía.\n";
            return -1;
        }
        int valor = frente->data;
        NodoCola* temp = frente;
        frente = frente->siguiente;
        delete temp;
        tamano--;
        if(frente == nullptr){
            fondo = nullptr;
        }
        return valor;
    }

    int peek(){
        if (isEmpty()){
            cout<<"Cola vacía.\n";
            return -1;
        }
        return frente->data;
    }

    int count(){
        return tamano;
    }

    bool isEmpty(){
        return frente == nullptr;
    }
};

int main(){
	
    ColaLista cola;
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);

    cout<<"Frente de la cola es: "<<cola.peek()<<endl; 
    cola.dequeue();
    cout<<"Frente de la cola despues del pop es: "<<cola.peek()<<endl; 

    cout<<"El tamano de la cola es: "<<cola.count()<<endl;

    return 0;
}
