#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include "Nodo.h"

#include <fstream>

class ListaCliente{
public:
	ListaCliente();
	~ListaCliente();

	Nodo* getCabeza();
	void setCabeza(Nodo*);

	void agregar(Cliente*);
	bool eliminar(std::string);
	std::string mostrar();
private:
	Nodo* cabeza;
};
#endif