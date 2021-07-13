#include "ListaRestaurante.h"

ListaRestaurante::ListaRestaurante()
{
	cabeza = nullptr;
}

ListaRestaurante::~ListaRestaurante() {
	Nodo* nodoBorrar = nullptr;
	while (cabeza != nullptr) {
		nodoBorrar = cabeza;
		cabeza = cabeza->getSig();
		nodoBorrar->setSig(nullptr);
		delete nodoBorrar;
	}
}

void ListaRestaurante::agregar(Restaurante* id)
{
	Nodo* nuevo = new Nodo(id);

	if (cabeza == nullptr) {
		cabeza = nuevo;

	}
	else {
		nuevo->setSig(cabeza);
		cabeza = nuevo;

	}
}

bool ListaRestaurante::eliminar(std::string id)
{
	Nodo* Borrar = cabeza;
	Nodo* Anterior = nullptr;
	bool tempBorrado = false;

	if (Borrar == nullptr) {
		tempBorrado = false;
		return tempBorrado;
	}
	//ACÁ PETA
	if (Borrar->getDatoRest()->getCedulaJuridica() == id) {
		cabeza = Borrar->getSig();
		delete Borrar;
		tempBorrado = true;
	}
	else {
		while ((Borrar != nullptr) && (Borrar->getDatoRest()->getCedulaJuridica() != id)) {
			Anterior = Borrar;
			Borrar = Borrar->getSig();
		}
		if (Borrar == nullptr) {
			std::cout << "Valor no encontrado" << std::endl;
			tempBorrado = false;
		}
		else {
			Anterior->setSig(Borrar->getSig());
			delete Borrar;
			tempBorrado = true;
		}
	}
	return tempBorrado;
}

void ListaRestaurante::mostrarParaAdmin()
{
	Nodo* aux = cabeza;

	while (aux != nullptr) {
		std::cout << aux->getDatoRest()->toString() << " ";
		aux = aux->getSig();
	}
}

void ListaRestaurante::mostrar()
{
	Nodo* aux = cabeza;

	while (aux != nullptr) {
		//std::cout << aux->getDatoRest()->toStringParaCliente() << " ";
		std::cout << aux->getDatoRest()->toString();
		//std::cout << aux->getDatoRest()->mostarCombos();
		aux = aux->getSig();
	}
}

std::string ListaRestaurante::buscarEspecifico(ListaRestaurante* lista, std::string n)
{
	std::stringstream x;

	Nodo* actual = cabeza;

	while (actual != nullptr) {
		if (actual->getDatoRest()->getNombre() == n) {
			x << actual->getDatoRest()->toStringParaCliente();
			return x.str();
		}
		actual = actual->getSig();
	}
	return x.str();
}

Nodo* ListaRestaurante::getCabeza()
{
	return cabeza;
}


