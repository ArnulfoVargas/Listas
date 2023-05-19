#include <iostream>

class Nodo {
public:
	int dato;
	Nodo* nodoSiguiente = nullptr;

	Nodo(int dato) {
		this->dato = dato;
	}
	Nodo() {
		this->dato = 0;
	}

	~Nodo() {
		
	}
};

class List{
private:

	Nodo* lista;

public:
	List() {
		lista = nullptr;
	}

	~List() {
		if (lista != nullptr)
		{
			Nodo* ultimoNodo = lista;
			Nodo* penultimoNodo = lista;

			while (lista->nodoSiguiente)
			{
				while (ultimoNodo->nodoSiguiente != nullptr) 
				{
					ultimoNodo = ultimoNodo->nodoSiguiente;
				}
				while (penultimoNodo->nodoSiguiente != ultimoNodo) 
				{
					penultimoNodo = penultimoNodo->nodoSiguiente;
				}

				ultimoNodo->~Nodo();
				penultimoNodo->nodoSiguiente = nullptr;

				ultimoNodo = lista;
				penultimoNodo = lista;
			}

			ultimoNodo->~Nodo();
			penultimoNodo->~Nodo();
		}
		
		lista->~Nodo();
	}

	bool IsEmpty() {
		return lista == nullptr;
	}

	void PrintList() {
		Nodo* holder = lista;

		while (lista->nodoSiguiente != nullptr && holder != nullptr) {
			std::cout << "[" << holder->dato << "]->";

			holder = holder->nodoSiguiente;
		}

		std::cout << "[NULL]\n";
	}

	void InsertFirst(int value) {

		if (lista == nullptr) lista = new Nodo(value);

		else
		{
			Nodo* holder = new Nodo(value);
			holder->nodoSiguiente = lista;
			
			lista = holder;
		}
	}

	void InsertLast(int value) {

		if (lista == nullptr) lista = new Nodo(value);

		else {
			Nodo* holder = lista;

			while (holder->nodoSiguiente != nullptr)
			{
				holder = holder->nodoSiguiente;
			}

			holder->nodoSiguiente = new Nodo(value);
		}
	}

	void InsertBefore(int nextValue, int nodeValue) {
		if (lista == nullptr)
		{
			lista = new Nodo(nodeValue);
		}
		else if(lista != nullptr)
		{
			Nodo* node = new Nodo(nodeValue);
			Nodo* holder = lista;
			Nodo* previo = lista;

			while (holder->nodoSiguiente != nullptr && holder->dato != nextValue)
			{
				if (holder->dato == nextValue) {
					node->nodoSiguiente = holder;
					previo->nodoSiguiente = node;
				 }
			}

			lista = previo;

			holder->~Nodo();
		}
	}
};

int main()
{
	List* list = new List();

	std::cout << std::boolalpha << list->IsEmpty() << "\n";

	list->InsertFirst(10);

	std::cout << list->IsEmpty() << "\n";

	list->InsertLast(1);

	list->PrintList();

	list->InsertFirst(5);

	list->PrintList();

	list->InsertLast(3);

	list->PrintList();

	list->InsertBefore(5, 4);

	list->PrintList();

	list->InsertBefore(22, 7);

	list->PrintList();

	list->~List();
}