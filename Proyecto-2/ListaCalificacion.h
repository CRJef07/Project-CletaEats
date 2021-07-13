#ifndef LISTACALIFICACION_H
#define LISTACALIFICACION_H
#include "NodoCalif.h"

class ListaCalificacion
{
public:
	ListaCalificacion();
	~ListaCalificacion();
	void agregar(Calificacion*);
	std::string mostrar();


	NodoCalif* getCabeza();
private:
	NodoCalif* cabeza;
};

#endif