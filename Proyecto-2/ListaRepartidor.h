#ifndef LISTAREPARTIDOR_H
#define LISTAREPARTIDOR_H
#include "Nodo.h"

class ListaRepartidor{
public:
	ListaRepartidor();
	~ListaRepartidor();
	void agregar(Repartidor*);
	bool eliminar(std::string id);
	std::string mostrar();
	std::string mostrarParaCliente();
	void buscarEspecifico(Nodo* lista,Repartidor* n);


	Nodo* getCabeza();
	int convertirInt(std::string);
	float convertirFloat(std::string );
	
private:
	Nodo *cabeza;
};
#endif