#include <iostream>

using namespace std;

//PILA
class nodo{
    int dato;
    nodo* enlace;
public :
    nodo(int elemento){
        this ->dato=elemento;
        enlace = NULL;
    }
    int getDato(){
        return dato;
    }
    void setDato(int elemento){
        this->dato=elemento;
    }
    nodo* getEnlace(){
        return this->enlace;
    }
    void setEnlace(nodo* _enlace){
        this->enlace=_enlace;
    }
    void imprime(){
        cout << "/-------------------\\" << endl;
        cout << "|Dato: " << dato << endl;
    }
};
class Pila
{
private:

	//atributos
	nodo* inicio;
public:
	//constructor
	Pila()
	{
		this->inicio = NULL;
	}
	//métodos
	//Pila vacia
	bool PilaVacia()
	{
		if (inicio == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//Insertar elemento
	void Insertar(int dato)//Push
	{
	    nodo* temp= new nodo(dato);
	    if(PilaVacia()){
            inicio = temp;
	    }
	    else{
            nodo* recorre= this->inicio;
            this->inicio = temp;
            this->inicio->setEnlace(recorre);
	    }
	}
	/// Quitar elemento
	int Quitar() // Pop
	{
		if (PilaVacia())
		{
			cout << "No hay en elementos en la pila" << endl;
			return NULL;
		}
		else
		{
		    nodo* recorre = inicio;
		    while(recorre->getEnlace()!= NULL){
                if(recorre->getEnlace()->getEnlace()!=NULL){
                    recorre = recorre->getEnlace();
                }
                else{
                    break;
                }
            cout<<endl;
		    }
		}
	}
	//Imprimir
	void Imprimir()
	{
	     nodo* recorre= inicio;
        cout << "Pila\n***************************" << endl;
        while (recorre!= NULL)
        {
            cout <<"\t|"<< recorre->getDato() <<"|"<<endl;
            recorre = recorre->getEnlace();
        }
        cout << "****************************" << endl << endl;
	}
};

void Menu()
{
	cout << "1) Insertar elemento " << endl;
	cout << "2) Quitar elemento " << endl;
	cout << "3) Imprimir pila " << endl;
	cout << "0) Salir " << endl;
}

int main()
{
	int opcion = 0;
	int elemento= 0;
	Pila pila = Pila();
	do
	{
		Menu();
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			cout << "Ingrese el elemento" << endl;
			cin >> elemento;
			pila.Insertar(elemento);
			break;
		case 2:
			elemento = pila.Quitar();
			cout << "El elemento quitado es: " << pila.Quitar() << endl;
			break;
		case 3:
			pila.Imprimir();

			break;
		default:
			cout << "opción no valida" << endl;
			break;
		}
		cout << "==============================================" << endl;
	} while (opcion != 0);
}
