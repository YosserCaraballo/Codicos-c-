/*

Diseña las clases para un sistema de gestión de pedidos de una pizzería. 
¿Qué clases crearías y qué atributos y métodos tendrían?

realizado por:

Nombre: yosser jose caraballo julio
Codigo: T00078120


*/
#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

// Declarando clases

class Cliente{
	private:
		int id;
		string nombre;
		string direccion;
		int telefono;
		int precio;
	public:
		Cliente(int,string,string,int,int);
		void paga();
	
};


class Menu{
	private:
		float precio;
		string producto;
	public:
		Menu(float,string);
		void mostrar();
		
	
};


class Repartidor{
	private:
		string nombre;
	
	public:
		Repartidor(string);
		void repartir();
};



class Cocinero{
	private:
		string nombre;
	public:
		Cocinero(string);
		void cocinar();
};





// Definiciones de las clases

//definicion clase cleinte

Cliente::Cliente(int _id,string _nombre,string _direccion,int _telefono,int _precio){
	id = _id;
	nombre = _nombre;
	direccion = _direccion;
	telefono = _telefono;
	precio = _precio;
}

void Cliente::paga(){
	cout<<"\nEl pedido ha llegado con exito\n";
	cout<<"El cliente "<<nombre<<" paga $"<<precio<<endl;
}


//definicion clase menu

Menu::Menu(float _precio,string _producto){
	precio = _precio;
	producto = _producto;
}

void Menu::mostrar(){
	cout<<"Ha escojido Pizza de "<<producto<<endl;
	cout<<"Precio a pagar: $"<<precio<<endl;
}

//definicion clase repartidor

Repartidor::Repartidor(string _nombre){
	nombre =_nombre;
	
}

void Repartidor::repartir(){
	cout<<"El repartidor "<<nombre<<" esta repartiendo";
}

//definicion clase cocinero
Cocinero::Cocinero(string _nombre){
	nombre =_nombre;
}

void Cocinero::cocinar(){
	cout<<"El cocinero "<<nombre<<" esta cocinando";
}






int main(){
	srand(time(NULL));
	string producto;
	string nombrecliente,dirreccion,nombrerepartidor = "Jose maria",nombrecocinero ="Tony";
	float telefono,precio,idcl;
	
	cout<<"\nEstacion de pedidos\n";
	cout<<"\n\n";
	cout<<"Digite sus datos:";
	cout<<"\nNombre: "; 
	getline(cin,nombrecliente);
	fflush(stdin);
	cout<<"Dirreccion: ";
	getline(cin,dirreccion);
	cout<<"Telefono: "; cin>>telefono;
	cout<<"Dijite el tipo de pizza que desea: "; cin>>producto;
	precio = (rand() + 20000);
	idcl = rand()%45;
	
	
	//mandando valores a las clases
	
	Cliente cl(idcl,nombrecliente,dirreccion,telefono,precio);
	Menu m(precio,producto);
	Repartidor re(nombrerepartidor);
	Cocinero co(nombrecocinero);
	
	// llamando a los metodos de las clases
	
	cout<<"\n";
	m.mostrar();
	cout<<"\n";
	co.cocinar();
	cout<<"\n\n";
	re.repartir();
	cout<<"\n\n";
	cl.paga();
	cout<<"\n";
	
	
	system("pause");
	return 0;
}





