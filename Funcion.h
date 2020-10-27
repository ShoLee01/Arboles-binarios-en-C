#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
template< class T >
class Nodo
{
public:
	Nodo* der;
	Nodo* izq;
	int ID;
	int altura;
	string Nombre;
	Nodo(){
		der = nullptr;
		izq = nullptr;
		altura = 0;
	}
};
template<class T>
class Arbol {
private:
	vector<Nodo<T>*> data;
	Nodo<T>* raiz;

public:
	Arbol() {
		raiz = nullptr;
	}
	void _insertar(T numero, string nombre, Nodo<T>*& nodo=nullptr) {
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->ID = numero;
			nodo->Nombre = nombre;
		}else if(nodo->ID < numero) {
			_insertar(numero,nombre,nodo->izq);
		}else if(nodo->ID >= numero) {
			_insertar(numero,nombre,nodo->der);
		}
	}
	void InOrden(Nodo<T>*& nodo=nullptr) {
		if (nodo == nullptr)return;
			InOrden(nodo->der);
			data.push_back(nodo);
			InOrden(nodo->izq);
	}
	void Insertar(int numero, string nombre) {
		_insertar(numero, nombre, raiz);
	}
	void Imprimir_Vector(){
		for_each(data.begin(), data.end(), [&](Nodo<T>*& nodo){
			cout << "ID: " << nodo->ID << " Nombre: " << nodo->Nombre<<endl;
			});
	}
	void Orden() {
		data.clear();
		InOrden(raiz);
	}
	
	void _BuscardorBinario(int n, Nodo<T>*& nodo){
		if (nodo==nullptr)
		{
			return;
		}
		else if(nodo->ID==n)
		{
			cout << "Encontrado || ID: " << nodo->ID << " Nombre: " << nodo->Nombre<<endl;
			_BuscardorBinario(n, nodo->der);
		}
		else if (n > nodo->ID) {
			return _BuscardorBinario(n, nodo->izq);
		}
		else
		{
			return _BuscardorBinario(n, nodo->der);
		}
	}
	bool _eliminar(Nodo<T>*& nodo, T e) {
		if (nodo == nullptr) return false;
		else {
			int r = e - nodo->ID;
			if (r < 0) {
				return _eliminar(nodo->der, e);
			}
			else if (r > 0) {
				return _eliminar(nodo->izq, e);
			}
			else { // r==0 es porque se encontró el elemento e en el arbol
				if (nodo->der == nullptr && nodo->izq == nullptr) {//caso 1
					nodo = nullptr;
					delete nodo;
					return true;
				}
				else if (nodo->izq == nullptr) { //caso 2
					nodo = nodo->der;
					return true;
				}
				else if (nodo->der == nullptr) { //caso 3
					nodo = nodo->izq;
					return true;
				}
				else { //caso 4
					Nodo<T>* aux = nodo->der; //Se establece buscar el menor elemento por la derecha
					while (aux->izq != nullptr)
					{
						aux = aux->izq; //Se obtiene la hoja menor
					}
					nodo->ID = aux->ID;
					nodo->Nombre = aux->Nombre;//Se actualiza el elemento en el nodo raiz y
					return _eliminar(nodo->der, aux->ID); //se envía a eliminar el elemento en el arbol por la derecha
				}
			}
		}
	}
	void Borrar(int n)
	{
		_eliminar(raiz, n);
	}
	void BusquedaBinaria(int n) 
	{
		_BuscardorBinario(n, raiz);
	}
};
template<class T >
class Heap {
private:
	vector<Nodo<T>*> data;
	//Nodo<T>* raiz;
	int size;
	bool key = true;
public:
	Heap() {
		size = 0;
	}
	int Numtor(int x, bool key = false) {
		int value = 0;
		int cont = 0;
		for_each(data.begin(), data.end(), [&](Nodo<T>*& nodo) {
			if (x == cont) {
				value = nodo->ID;
			}
			if (key) {
				cout << "ID: " << nodo->ID << " Nombre: " << nodo->Nombre << endl;
			}
			cont++;
			});
		return value;
	}
	void Reasic(int x, int n) {
		int cont = 0;
		for_each(data.begin(), data.end(), [&](Nodo<T>*& nodo) {
			if (x == cont) {
				nodo->ID=n;
			}
			cont++;
			});
	}
	void Insertar(int ID, string Nombre) {
		Nodo<T>* nodo = new Nodo<T>();
		nodo->ID = ID;
		nodo->Nombre = Nombre;
		data.push_back(nodo);
		nodo = nullptr;
	}
	///Max Heapify////
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int rigth(int i) {
		return 2 * i + 2;
	}
	void MinHeapify(int n, int i) {
		int l = left(i);
		int r = rigth(i);
		int largest(0);
		if (l <= (n - 1) && Numtor(l) > Numtor(i)) {
			largest = l;
		}
		else
			largest = i;
		if (r <= (n - 1) && Numtor(r) > Numtor(largest)) {
			largest = r;
		}
		if (largest != i) {
			swap(data[i], data[largest]);
			MinHeapify(n, largest);
		}
	}
	void buildMinHeap(int n) {
		buildMaxHeap(n);
		for (int i = n - 1; i >= 0; --i) {
			swap(data[0], data[i]);
			MinHeapify(--n, 0);
		}
	}
	void maxHeapify(int n, int i) {
		int l = left(i);
		int r = rigth(i);
		int largest(0);
		if (l <= (n - 1) && Numtor(l) > Numtor(i)) {
			largest = l;
		}
		else
			largest = i;
		if (r <= (n - 1) && Numtor(r) > Numtor(largest)) {
			largest = r;
		}
		if (largest != i) {
			swap(data[i], data[largest]);
			maxHeapify(n, largest);
		}
	}

	void buildMaxHeap(int n) {
		for (int i = n / 2 - 1; i >= 0; --i) {
			maxHeapify(n, i);
		}
	}

	void print() {
		Numtor(0, true);
	}

	//aplicación de ordenamiento
	void heapsort(int n) {
		buildMaxHeap(n);
		for (int i = n - 1; i >=0; --i) {
			swap(data[0], data[i]);
			maxHeapify(--n, 0);
		}
	}
	//////// Cola de Prioridad /////////

	void insert(int ID,string numero)
	{
		size = data.size();
		Insertar(ID, numero);
		size++;
		int i = size - 1;
		while (i > 0 && Numtor(parent(i)) < Numtor(i))
		{
			swap(data[i], data[parent(i)]);
			i = parent(i);
		}
	}
	int  maximum()
	{
		//buildMaxHeap(data.size());
		size = data.size();
		if (size <= 0)
		{
			cerr << "heap overflow" <<endl;
			return -1;
		}
		return Numtor(0);
	}

	int  extract_max()
	{
		int max = 0;
		if (size <= 0)
		{
			cerr << "heap overflow" << endl;
			return -1;
		}else{
			data[0] = data[size - 1];
			data.erase(data.begin() + size - 1);
			size--;
			maxHeapify(size, 0);
			max = Numtor(0);
		}
		return max;
	}

	void  increase_key(int i, int x) {
		if (Numtor(i) < x) {
			Reasic(i, x);
			while (i >= 0 && Numtor(parent(i)) < Numtor(i)) {
				swap(data[parent(i)], data[i]);
				i = parent(i);
			}
		}
		//	a[i] = max(a[i], x);
	}

};
//////////////// ARBOLES BALANCEADOS ///////////////////
template<class T>
class ArbolAVL {
private:
	vector<Nodo<T>*> data;
	Nodo<T>* raiz; 
public:
	ArbolAVL() {
		raiz = nullptr;
	}
	//Operaciones privadas
	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}

	void _rotarDerecha(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;
		//Actualizamos la altura

		nodo = p;
	}

	void _rotarIzquierda(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;
		//Actualizamos la altura

		nodo = p;
	}
	void _balanceo(Nodo<T>*& nodo) {
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;

		if (fb > 1) { //rotar a la izq
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) { //verificar si aplica doble rotación
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) { //rotar a la der
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) {//verificar si aplica doble rotación 
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		//Actualizar la altura del nodo raiz
		hizq = _altura(nodo->izq);
		hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(Nodo<T>*& nodo, T ID, string Nombre) {

		if (nodo == nullptr) {
			//Nuevo elemento
			nodo = new Nodo<T>();
			nodo->ID = ID;
			nodo->Nombre = Nombre;
			return true;
		}
		else if (ID == nodo->ID)
			return false;
		else if (ID < nodo->ID) {
			_insertar(nodo->izq, ID,Nombre);
		}
		else if (ID > nodo->ID) {
			_insertar(nodo->der,ID,Nombre);
		}
		_balanceo(nodo);
		return true;
	}

	void _inOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		data.push_back(nodo);
		_inOrden(nodo->der);
	}
	void _onOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_onOrden(nodo->der);
		data.push_back(nodo);
		_onOrden(nodo->izq);
	}

	void _inOrdenH(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		data.push_back(nodo);
		_inOrdenH(nodo->der);
	}

	bool Insertar(T ID, string Nombre) {
		return _insertar(raiz,ID,Nombre);
	}
	void onOrden_() {
		data.clear();
		_onOrden(raiz);
	}
	void inOrden_() {
		data.clear();
		_inOrden(raiz);
	}
	void inOrdenH() {
		data.clear();
		_inOrdenH(raiz);
	}
	void print() {
		for_each(data.begin(), data.end(), [&](Nodo<T>* nodo) {
			cout << "ID: " << nodo->ID << " Nombre: " << nodo->Nombre << endl;
			});
	}
};