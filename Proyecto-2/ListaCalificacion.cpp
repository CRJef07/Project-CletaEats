#include "ListaCalificacion.h"

ListaCalificacion::ListaCalificacion()
{
	this->cabeza = nullptr;
}

ListaCalificacion::~ListaCalificacion()
{
	NodoCalif* nodoBorrar = nullptr;
	while (cabeza != nullptr) {
		nodoBorrar = cabeza;
		cabeza = cabeza->getSig();
		nodoBorrar->setSig(nullptr);
		delete nodoBorrar;
	}
}

void ListaCalificacion::agregar(Calificacion* id)
{
	NodoCalif* nuevo = new NodoCalif(id);

	if (cabeza == NULL) {
		cabeza = nuevo;

	}
	else {
		nuevo->setSig(cabeza);
		cabeza = nuevo;

	}
}



std::string ListaCalificacion::mostrar()
{
	std::stringstream x;

	NodoCalif* tempAux = cabeza;

	if (tempAux == nullptr) {
		x << "No hay repartidores registrados" << std::endl;
	}

	while (tempAux != nullptr) {
		
		x << tempAux->getDatoCalif()->toString();

		x << "\n---------------------------------------------------------------\n";
		tempAux = tempAux->getSig();
	}

	return x.str();
}





NodoCalif* ListaCalificacion::getCabeza()
{
	return cabeza;
}
