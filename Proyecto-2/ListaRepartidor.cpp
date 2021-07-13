#include "ListaRepartidor.h"

ListaRepartidor::ListaRepartidor(){
	cabeza = nullptr;
}

ListaRepartidor::~ListaRepartidor(){
	Nodo* nodoBorrar = nullptr;
	while (cabeza != nullptr) {
		nodoBorrar = cabeza;
		cabeza = cabeza->getSig();
		nodoBorrar->setSig(nullptr);
		delete nodoBorrar;
	}
}

//INSERTO LOS REPARTIDORES
void ListaRepartidor::agregar(Repartidor* id)
{
	Nodo* nuevo = new Nodo(id);

	if (cabeza == NULL) {
		cabeza = nuevo;

	}
	else {
		nuevo->setSig(cabeza);
		cabeza = nuevo;

	}
}
//BORRO UN NODO EN ESPECIFICO
bool ListaRepartidor::eliminar(std::string id)
{
	Nodo* Borrar = cabeza;
	Nodo* Anterior = nullptr;
	bool tempBorrado = false;

	if (Borrar == nullptr) {
		tempBorrado = false;
		return tempBorrado;
	}
	if (Borrar->getDatoRepa()->getCedula() == id) {
		cabeza = Borrar->getSig();
		delete Borrar;
		tempBorrado = true;

	}
	else {
		while ((Borrar != nullptr) && (Borrar->getDatoRepa()->getCedula() != id)) {
			Anterior = Borrar;
			Borrar = Borrar->getSig();
		}
		if (Borrar == nullptr) {
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
//MUESTRO TODA LA LISTA
std::string ListaRepartidor::mostrar()
{
	std::stringstream x;

	Nodo* tempAux = cabeza;

	if (tempAux == nullptr) {
		x << "No hay repartidores registrados" << std::endl;
	}

	while (tempAux != nullptr) {
		if (tempAux->getDatoRepa()->getEstado() == true) {
			x << "\nSe encuentra desocupado" << std::endl;
		}
		else {
			x << "Se encuentra entregando un pedido" << std::endl;
		}
		x << tempAux->getDatoRepa()->toStringRepa();
		
		

		x << "\n---------------------------------------------------------------\n";
		tempAux = tempAux->getSig();
	}

	return x.str();
}
std::string ListaRepartidor::mostrarParaCliente()
{
	std::stringstream x;

	Nodo* tempAux = cabeza;

	if (tempAux == nullptr) {
		x << "No hay repartidores registrados" << std::endl;
	}

	while (tempAux != nullptr) {


		x << tempAux->getDatoRepa()->toStringParaCliente() << " ";
		
		x << "---------------------------------------------------------------\n";
		tempAux = tempAux->getSig();
	}

	return x.str();
}
//BUSCA UN ELEMENTO ESPECIFICO EN LA LISTA
void ListaRepartidor::buscarEspecifico(Nodo* lista, Repartidor* n)
{
	std::stringstream x;
	bool band = false;

	Nodo* actual = new Nodo(n);
	actual = cabeza;

	while ((actual != nullptr) && (actual->getDatoRepa() <= n)) {
		if (actual->getDatoRepa() == n) {
			band = true;
		}
		actual = actual->getSig();
	}
	if (band == true) {
		x << n  <<" ha sido encontrado"<< std::endl;
	}
	else {
		x << n <<" No ha sido encontrado"<< std::endl;
	}

}



Nodo* ListaRepartidor::getCabeza()
{
	return cabeza;
}

int ListaRepartidor::convertirInt(std::string dato)
{
	std::stringstream x(dato);
	int entero = -1;
	x >> entero;
	return entero;
}

float ListaRepartidor::convertirFloat(std::string dato)
{
	std::stringstream x(dato);
	float flotante = -1;
	x >> flotante;
	return flotante;
}

