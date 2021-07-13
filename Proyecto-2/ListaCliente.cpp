#include "ListaCliente.h"

ListaCliente::ListaCliente(){
	cabeza = nullptr;
}

ListaCliente::~ListaCliente(){
	Nodo* nodoBorrar = nullptr;
	while (cabeza != nullptr) {
		nodoBorrar = cabeza;
		cabeza = cabeza->getSig();
		nodoBorrar->setSig(nullptr);
		delete nodoBorrar;
	}
}

Nodo* ListaCliente::getCabeza(){
	return cabeza;
}

void ListaCliente::setCabeza(Nodo* nuevo){
	this->cabeza = nuevo;
}

/*void ListaCliente::agregar(Cliente* dato){	//AGREGAR AL PRINCIPIO
	Nodo* nuevoNodo = new Nodo(dato);

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
		std::cout << "El dato se ha agregado a la lista" << std::endl;
	}else {
		nuevoNodo->setSig(cabeza);
		cabeza = nuevoNodo;
		std::cout << "El dato se ha agregado a la lista" << std::endl;
	}
}*/

void ListaCliente::agregar(Cliente* dato) { //AGREGAR AL FINAL
	Nodo* nuevoNodo = new Nodo(dato);

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
	}else {
		Nodo* aux = cabeza;

		while (aux->getSig() != nullptr) {
			aux = aux->getSig();
		}
		aux->setSig(nuevoNodo);
	}
}

bool ListaCliente::eliminar(std::string ced){
	Nodo* Borrar = cabeza;
	Nodo* Anterior = nullptr;

	bool tempBorrado = false;

	if (Borrar == nullptr) {
		tempBorrado = false;
		return tempBorrado;
	}
	if (Borrar->getDatoC()->getCedula() == ced) {
		cabeza = Borrar->getSig();
		delete Borrar;
		tempBorrado = true;
	}else {
		while ( (Borrar!= nullptr) && (Borrar->getDatoC()->getCedula() != ced) ) {
			Anterior = Borrar;
			Borrar = Borrar->getSig();
		}
		if (Borrar == nullptr) {
			tempBorrado = false;
		}else {
			Anterior->setSig( Borrar->getSig() );
			delete Borrar;
			tempBorrado = true;
		}
	}
	return tempBorrado;
}
/*bool ListaCliente::eliminar(std::string ced) {
	Nodo* actual = cabeza;

	while (actual != nullptr) {
		if (actual->getDatoC()->getCedula() == ced) {
			cabeza = actual->getSig();
			delete actual;
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}*/

std::string ListaCliente::mostrar(){
	std::stringstream x;
	
	Nodo* tempAux = cabeza;

	if (tempAux == nullptr) {
		x << "\t\tNo hay clientes registrados" << std::endl;
	}

	while (tempAux != nullptr) {

		x << tempAux->getDatoC()->toString();

		if (tempAux->getDatoC()->getEstado() == true) {
			x << "Se encuentra activo en la plataforma" << std::endl << std::endl;
		}else {
			x << "Se encuentra suspendido de la plataforma" << std::endl << std::endl;
		}

		tempAux = tempAux->getSig();

	}

	return x.str();
}
