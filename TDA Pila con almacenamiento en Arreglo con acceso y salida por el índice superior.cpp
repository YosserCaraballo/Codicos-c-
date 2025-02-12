/*

1. TDA Pila con almacenamiento en Arreglo con acceso y salida por el índice superior


*/

#include <iostream>
using namespace std;

class PilaArrSup{
	private:
		int* arr;
		int tope;
		int capacidad;

	public:
		PilaArrSup(int size){
			arr = new int[size];
			capacidad = size;
			tope = -1;
		}

		~PilaArrSup(){
			delete[] arr;
		}

		void push(int data){
			if(isFull()){
				cout<<"Pila llena.\n";
				return;
			}
			arr[++tope] = data;
		}

		int pop(){
			if(isEmpty()){
				cout<<"Pila vacía.\n";
				return -1;
			}
			return arr[tope--];
		}

		int peek(){
			if(isEmpty()){
				cout<<"Pila vacía.\n";
				return -1;
			}
			return arr[tope];
		}

		int count(){
			return tope + 1;
		}

		bool isFull(){
			return tope == capacidad - 1;
		}

		bool isEmpty(){
			return tope == -1;
		}
};



int main(){
	
    PilaArrSup pila(5);
    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout<<"El tope de la pila es: "<<pila.peek()<<endl;
    pila.pop();
    cout<<"El tope de la pila despues de pop es: "<<pila.peek()<<endl;

    cout<<"El tamano de la pila es: "<<pila.count()<<endl;

    return 0;
}

