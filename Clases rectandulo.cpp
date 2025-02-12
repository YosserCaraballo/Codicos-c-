#include<iostream>
#include<stdlib.h>

using namespace std;

class Rectangulo{
	private: //atributos
		int largo;
		int ancho;
	public: //metodos
		Rectangulo(int,int);
		void perimetro();
		void area();
};

Rectangulo::Rectangulo(int _largo,int _ancho){
	largo = _largo;
	ancho = _ancho;
}

void Rectangulo::area(){
	cout<<"El area es: "<<ancho * largo<<endl;
}

void Rectangulo::perimetro(){
	cout<<"El perimetro es: "<<(ancho*2) + (largo*2)<<endl;
}


int main(){
	Rectangulo r1(5,7);
	r1.area();
	r1.perimetro();
	
	
	
	system("pause");
	return 0;
}

