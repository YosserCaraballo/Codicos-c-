//insertar elementos en la pila

#include<iostream>
#include<conio.h>
#include<stdlib.h> //new
using namespace std;


struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarpila(Nodo *&,int); //prototipo


int main(){
	
	Nodo *pila = NULL;
	int n1,n2;
	
	cout<<"Digite un numero: "; cin>>n1;
	
	agregarpila(pila,n1);
	
	cout<<"Digite otro numero: "; cin>>n2;
	
	agregarpila(pila,n2);
	
	
	getch();
	return 0;
}

void agregarpila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	
	cout<<"Elemento "<<n<<"Agregado a pila correctamente"<<endl;
	
}

