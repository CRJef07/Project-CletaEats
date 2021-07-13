#ifndef LISTARESTAURANTE_H
#define LISTARESTAURANTE_H
#include "Nodo.h"

class ListaRestaurante{
public:
	ListaRestaurante();
	~ListaRestaurante();
	void agregar(Restaurante*);
	bool eliminar(std::string id);
	void mostrar();
	void mostrarParaAdmin();
	std::string buscarEspecifico(ListaRestaurante* lista, std::string n);
	Nodo* getCabeza();
	
	
private:
	Nodo *cabeza;
};
#endif