#include <iostream>
#include <string>
#include "Funcion.h"
using namespace std;

int main() {
	int valor;
	Heap<int>* hep = new Heap<int>;
	ArbolAVL<int>* hap = new ArbolAVL<int>;
	Arbol<int>* arbolito = new Arbol<int>;
	while (true)
	{
		cout << "//////// Menu ////////"<<endl;
		cout << "1.- Arbol binario: " << endl;
		cout << "2.- Heap: " << endl;
		cout << "3.- buildMaxHeap: " << endl;
		cout << "4.- HeapSort: " << endl;
		cout << "5.- Implementacion: " << endl;
		cout << "6.- buildMinxHeap: " << endl;
		cout << "7.- BorrarArbolBinario: " << endl;
		cout << "8.- Arbol Balanceado: " << endl;
		cout << "9.- Acendente: " << endl;
		cout << "10.- Desendente: " << endl;
		cout << "11.- En Horizontal: " << endl;
		cout << "Digite opcion: "; cin >> valor;
		system("cls");
		switch (valor)
		{
		case 1:
			arbolito->Insertar(12, "Miguel");
			arbolito->Insertar(9, "Sofia");
			arbolito->Insertar(9, "Luis");
			arbolito->Insertar(13, "Juan");
			arbolito->Insertar(14, "Bryam");
			arbolito->Insertar(9, "Lola");
			arbolito->Insertar(1, "Emanuel");
			arbolito->Insertar(9, "Lala");
			arbolito->Orden();
			arbolito->Imprimir_Vector();
			arbolito->BusquedaBinaria(9);
			break;
		case 2: 
			hep->Insertar(12, "Miguel");
			hep->Insertar(13, "Juan");
			hep->Insertar(14, "Bryam");
			hep->Insertar(9, "Luis");
			hep->Insertar(9, "Lola");
			hep->Insertar(1, "Emanuel");
			break;
		case 3:
			hep->buildMaxHeap(6);
			hep->print();
			break;
		case 4:
			hep->heapsort(6);
			hep->print();
			break;
		case 5: 
			hep->increase_key(0, 5);
			 cout << hep->maximum() << endl;
			hep->insert(20,"Miguel");
			hep->insert(10,"Angel");
			 cout << hep->maximum() <<  endl;
			hep->extract_max();
			 cout << hep->maximum() <<  endl;
			 cout << hep->maximum() <<  endl;
			hep->extract_max();
			 cout << hep->maximum() <<  endl;
			hep->increase_key(1, 30);
			 cout << hep->maximum() <<  endl;
			 
			break;
		case 6: 
			hep->buildMinHeap(6);
			hep->print();
			break;
		case 7: 
			arbolito->Borrar(12);
			arbolito->Orden();
			arbolito->Imprimir_Vector();
				break;
		case 8:
			hap->Insertar(12, "Miguel");
			hap->Insertar(13, "Juan");
			hap->Insertar(14, "Bryam");
			hap->Insertar(9, "Luis");
			hap->Insertar(9, "Lola");
			hap->Insertar(1, "Emanuel");
			break;
		case 9:
			hap->inOrden_();
			hap->print();
			break;
		case 10:
			hap->onOrden_();
			hap->print();
			break;
		case 11:
			hap->inOrdenH();
			hap->print();
			break;

		default:
			cout << "Opcion no valida !!!"<<endl;
			break;
		}
		system("pause");
		system("cls");
		hep->print();
		system("pause");
		system("cls");
	}
	
	return 0;
}