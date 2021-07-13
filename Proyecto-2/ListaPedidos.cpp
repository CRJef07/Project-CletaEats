#include "ListaPedidos.h"

ListaPedidos::ListaPedidos(){
	cabeza = nullptr;
}

ListaPedidos::~ListaPedidos(){
	Nodo *nodoBorrar = nullptr;

	while (cabeza != nullptr) {
		nodoBorrar = cabeza;
		cabeza = cabeza->getSig();
		nodoBorrar->setSig(nullptr);
		delete nodoBorrar;
	}
}

Nodo* ListaPedidos::getCabeza(){
	return cabeza;
}

void ListaPedidos::setCabeza(Nodo* nuevo){
	this->cabeza = nuevo;
}


void ListaPedidos::agregarPedido(Pedido* dato) {
	Nodo* nuevoNodo = new Nodo(dato);

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
	}else {
		Nodo* aux = cabeza;
		while (aux->getSig() != nullptr) {
			aux = aux->getSig();
		}
		aux->setSig(nuevoNodo);//LO AGREGA AL FINAL
	}
}

bool ListaPedidos::eliminarPedido(std::string ced){
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
	}
	else {
		while ((Borrar != nullptr) && (Borrar->getDatoC()->getCedula() != ced)) {
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


std::string ListaPedidos::mostrarLista(){

	std::stringstream x;

	Nodo* tempAux = cabeza;

	if (tempAux == nullptr) {
		x << "\t\tNo hay pedidos registrados" << std::endl;
	}

	while (tempAux != nullptr) {
		x << tempAux->getDatoPedido()->toStringPedido();
		tempAux = tempAux->getSig();
	}

	return x.str();
}

void ListaPedidos::realizarPedido(ListaCliente* lcli, ListaRepartidor* lrepa, ListaRestaurante* lresta, std::string cedulaCliente) {
	std::string opcResta = " ";
	std::string opcCombo = " ";

	std::cout << "\t\tREALIZANDO PEDIDO" << std::endl;
	std::cout << "Para realizar su pedido escoja un restaurante" << std::endl;
	std::cout << "1 - McDonald's " << std::endl;
	std::cout << "Tipo de comida: Comida rápida" << std::endl << std::endl;

	std::cout << "2 - Pizza Hut" << std::endl;
	std::cout << "Tipo de comida: Pizzería" << std::endl << std::endl;

	std::cout << "3 - La Princesa Marina" << std::endl;
	std::cout << "Tipo de comida: Marisquería" << std::endl << std::endl;

	std::cout << "4 - KFC" << std::endl;
	std::cout << "Tipo de comida: Comida rápida" << std::endl << std::endl;

	std::cout << "5 - Burger King" << std::endl;
	std::cout << "Tipo de comida: Comida rápida" << std::endl << std::endl;

	std::cout << "6 - Las Cañitas" << std::endl;
	std::cout << "Tipo de comida: Bar y restaurante" << std::endl << std::endl;

	std::cout << "7 - POPS" << std::endl;
	std::cout << "Tipo de comida: Heladería" << std::endl << std::endl;

	std::cout << "Opción:  ";

	std::getline(std::cin, opcResta);

	system("cls");
	try {

		if (opcResta != "1" && opcResta != "2" && opcResta != "3" && opcResta != "4" && opcResta != "5" && opcResta != "6" && opcResta != "7") {
			throw opcResta;
		}

		switch (std::stoi(opcResta)) {
		case 1://std::cout << "1 - McDonald's " << std::endl;
			system("cls");
			std::cout << lresta->buscarEspecifico(lresta, "McDonald's");
			std::cout << "Digite el combo que desea:  ";
			std::getline(std::cin, opcCombo);

			try {
				if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
					throw opcCombo;
				}
				switch (std::stoi(opcCombo)) {
				case 1:

					system("cls");

					if (asignarRepartidor(lrepa) == true) {//true porque si se asignó un repartidor
						std::cout << "\tRepartidor asignado correctamente " << std::endl;
						Pedido* nuevo = new Pedido;
						agregarPedido(nuevo);
						settearPedido(lcli, cedulaCliente,4000,cedulaCliente);
					}
					else {
						system("cls");
						std::cout << "\tNO SE ASIGNÓ NINGÚN REPARTIDOR" << std::endl;
						std::cout << "No hay repartidores disponibles en este momento" << std::endl;
						std::cout << "Vuelva a intentar hacer el pedido más tarde" << std::endl;
					}

					break;

				case 2:
					std::cout << "COMBO 2 " << std::endl;
					break;

				case 3:
					std::cout << "COMBO 3 " << std::endl;
					break;

				case 4:
					std::cout << "COMBO 4 " << std::endl;
					break;

				case 5:
					std::cout << "COMBO 5 " << std::endl;
					break;

				case 6:
					std::cout << "COMBO 6 " << std::endl;
					break;

				case 7:
					std::cout << "COMBO 7 " << std::endl;
					break;

				case 8:
					std::cout << "COMBO 8 " << std::endl;
					break;

				case 9:
					std::cout << "COMBO 9 " << std::endl;
					break;
				}
			}
			catch (std::string opcCombo) {}
			break;

		case 2://std::cout << "2 - Pizza Hut" << std::endl;
			std::cout << "\t\tUsted eligió Pizza Hut" << std::endl;
			std::cout << "Le vamos a mostrar los combos del restaurante" << std::endl << std::endl;
			system("pause");
			system("cls");
			std::cout << lresta->buscarEspecifico(lresta, "Pizza Hut");
			std::cout << "Digite el combo que desea:  ";
			std::getline(std::cin, opcCombo);

			try {
				if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
					throw opcCombo;
				}
				switch (std::stoi(opcCombo)) {
				case 1:
					std::cout << "COMBO 1 " << std::endl;
					break;

				case 2:
					std::cout << "COMBO 2 " << std::endl;
					break;

				case 3:
					std::cout << "COMBO 3 " << std::endl;
					break;

				case 4:
					std::cout << "COMBO 4 " << std::endl;
					break;

				case 5:
					std::cout << "COMBO 5 " << std::endl;
					break;

				case 6:
					std::cout << "COMBO 6 " << std::endl;
					break;

				case 7:
					std::cout << "COMBO 7 " << std::endl;
					break;

				case 8:
					std::cout << "COMBO 8 " << std::endl;
					break;

				case 9:
					std::cout << "COMBO 9 " << std::endl;
					break;
				}
			}
			catch (std::string opcCombo) {}
			break;

		case 3://std::cout << "3 - La Princesa Marina" << std::endl;
			std::cout << "\t\tUsted eligió La Princesa Marina" << std::endl;
			std::cout << "Le vamos a mostrar los combos del restaurante" << std::endl << std::endl;
			system("pause");
			system("cls");
			std::cout << lresta->buscarEspecifico(lresta, "La Princesa Marina");
			std::cout << "Digite el combo que desea:  ";
			std::getline(std::cin, opcCombo);

			try {
				if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
					throw opcCombo;
				}
				switch (std::stoi(opcCombo)) {
				case 1:
					std::cout << "COMBO 1 " << std::endl;
					break;

				case 2:
					std::cout << "COMBO 2 " << std::endl;
					break;

				case 3:
					std::cout << "COMBO 3 " << std::endl;
					break;

				case 4:
					std::cout << "COMBO 4 " << std::endl;
					break;

				case 5:
					std::cout << "COMBO 5 " << std::endl;
					break;

				case 6:
					std::cout << "COMBO 6 " << std::endl;
					break;

				case 7:
					std::cout << "COMBO 7 " << std::endl;
					break;

				case 8:
					std::cout << "COMBO 8 " << std::endl;
					break;

				case 9:
					std::cout << "COMBO 9 " << std::endl;
					break;
				}
			}
			catch (std::string opcCombo) {}
			break;

		case 4://std::cout << "4 - KFC" << std::endl;
			std::cout << "\t\tUsted eligió KFC" << std::endl;
			std::cout << "Le vamos a mostrar los combos del restaurante" << std::endl << std::endl;
			system("pause");
			system("cls");
			std::cout << lresta->buscarEspecifico(lresta, "KFC");
			std::cout << "Digite el combo que desea:  ";
			std::getline(std::cin, opcCombo);

			try {
				if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
					throw opcCombo;
				}
				switch (std::stoi(opcCombo)) {
				case 1:
					std::cout << "COMBO 1 " << std::endl;
					break;

				case 2:
					std::cout << "COMBO 2 " << std::endl;
					break;

				case 3:
					std::cout << "COMBO 3 " << std::endl;
					break;

				case 4:
					std::cout << "COMBO 4 " << std::endl;
					break;

				case 5:
					std::cout << "COMBO 5 " << std::endl;
					break;

				case 6:
					std::cout << "COMBO 6 " << std::endl;
					break;

				case 7:
					std::cout << "COMBO 7 " << std::endl;
					break;

				case 8:
					std::cout << "COMBO 8 " << std::endl;
					break;

				case 9:
					std::cout << "COMBO 9 " << std::endl;
					break;
				}
			}
			catch (std::string opcCombo) {}
			break;

		case 5://std::cout << "5 - Burger King" << std::endl;
			std::cout << "\t\tUsted eligió Burger King" << std::endl;
			std::cout << "Le vamos a mostrar los combos del restaurante" << std::endl << std::endl;
			system("pause");
			system("cls");
			std::cout << lresta->buscarEspecifico(lresta, "Burger King");
			std::cout << "Digite el combo que desea:  ";
			std::getline(std::cin, opcCombo);

			try {
				if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
					throw opcCombo;
				}
				switch (std::stoi(opcCombo)) {
				case 1:
					std::cout << "COMBO 1 " << std::endl;
					break;

				case 2:
					std::cout << "COMBO 2 " << std::endl;
					break;

				case 3:
					std::cout << "COMBO 3 " << std::endl;
					break;

				case 4:
					std::cout << "COMBO 4 " << std::endl;
					break;

				case 5:
					std::cout << "COMBO 5 " << std::endl;
					break;

				case 6:
					std::cout << "COMBO 6 " << std::endl;
					break;

				case 7:
					std::cout << "COMBO 7 " << std::endl;
					break;

				case 8:
					std::cout << "COMBO 8 " << std::endl;
					break;

				case 9:
					std::cout << "COMBO 9 " << std::endl;
					break;
				}
			}
			catch (std::string opcCombo) {}
			break;

		case 6://std::cout << "6 - Las Cañitas" << std::endl;
			std::cout << "\t\tUsted eligió Las Cañitas" << std::endl;
			std::cout << "Le vamos a mostrar los combos del restaurante" << std::endl << std::endl;
			system("pause");
			system("cls");
			std::cout << lresta->buscarEspecifico(lresta, "Las Cañitas");
			std::cout << "Digite el combo que desea:  ";
			std::getline(std::cin, opcCombo);

			try {
				if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
					throw opcCombo;
				}
				switch (std::stoi(opcCombo)) {
				case 1:
					std::cout << "COMBO 1 " << std::endl;
					break;

				case 2:
					std::cout << "COMBO 2 " << std::endl;
					break;

				case 3:
					std::cout << "COMBO 3 " << std::endl;
					break;

				case 4:
					std::cout << "COMBO 4 " << std::endl;
					break;

				case 5:
					std::cout << "COMBO 5 " << std::endl;
					break;

				case 6:
					std::cout << "COMBO 6 " << std::endl;
					break;

				case 7:
					std::cout << "COMBO 7 " << std::endl;
					break;

				case 8:
					std::cout << "COMBO 8 " << std::endl;
					break;

				case 9:
					std::cout << "COMBO 9 " << std::endl;
					break;
				}
			}
			catch (std::string opcCombo) {}
			break;

		case 7://std::cout << "7 - POPS" << std::endl;
			std::cout << "\t\tUsted eligió POPS" << std::endl;
			std::cout << "Le vamos a mostrar los combos del restaurante" << std::endl << std::endl;
			system("pause");
			system("cls");
			std::cout << lresta->buscarEspecifico(lresta, "POPS");
			std::cout << "Digite el combo que desea:  ";
			std::getline(std::cin, opcCombo);

			try {
				if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
					throw opcCombo;
				}
				switch (std::stoi(opcCombo)) {
				case 1:
					std::cout << "COMBO 1 " << std::endl;
					break;

				case 2:
					std::cout << "COMBO 2 " << std::endl;
					break;

				case 3:
					std::cout << "COMBO 3 " << std::endl;
					break;

				case 4:
					std::cout << "COMBO 4 " << std::endl;
					break;

				case 5:
					std::cout << "COMBO 5 " << std::endl;
					break;

				case 6:
					std::cout << "COMBO 6 " << std::endl;
					break;

				case 7:
					std::cout << "COMBO 7 " << std::endl;
					break;

				case 8:
					std::cout << "COMBO 8 " << std::endl;
					break;

				case 9:
					std::cout << "COMBO 9 " << std::endl;
					break;
				}
			}
			catch (std::string opcCombo) {}
			break;
		}
	}
	catch (std::string opcResta) {}
}


bool ListaPedidos::asignarRepartidor(ListaRepartidor* lrepa) {

	Nodo* actual = lrepa->getCabeza();

	while (actual != nullptr) {//verifica si hay al menos un repartidor
		while (actual->getDatoRepa()->getEstado() == true && actual->getDatoRepa()->getAmonestaciones() < 4 && actual->getDatoRepa()->getDisponibilidad() == true) {//VERIFICA EL ESTADO Y LAS AMONESTACIONES
			
			actual->getDatoRepa()->setDisponibilidad(false);

			return true;
		}
		actual = actual->getSig();
	}
	return false;
}


bool ListaPedidos::validarIDCliente(ListaCliente* liCli, std::string id) {//VALIDA QUE EXISTA EL CLIENTE EN LA LISTA, SINO PARA AGREGARLO

	Nodo* aux = liCli->getCabeza();

	while (aux != nullptr) {

		if (aux->getDatoC()->getCedula() == id) {
			return true;
		}
		aux = aux->getSig();
	}

	return false;
}





bool ListaPedidos::validarEstadoCliente(ListaCliente* liCli, std::string id) {

	Nodo* aux = liCli->getCabeza();

	while (aux != nullptr) {

		if (aux->getDatoC()->getCedula() == id && aux->getDatoC()->getEstado() == true) {
			return true;
		}
		aux = aux->getSig();
	}

	return false;
}

bool ListaPedidos::settearPedido(ListaCliente* liCli, std::string id,float precio, std::string Cedula){
	int aleatorio1 = 0, aleatorio2 = 0;//SETTEAR ID
	std::string aleatorioNuevo = "";//SETTEAR ID

	time_t now = time(0);//SETTEAR HORA
	tm* time = localtime(&now);//SETTEAR HORA
	int hora = time->tm_hour;//SETTEAR HORA

	Nodo* temp = cabeza;

	while (temp != nullptr) {//VALIDA SI EXISTEN PEDIDOS
		if (temp->getDatoPedido()->getIDPedido() != "En camino") {
			temp->getDatoPedido()->setIDPedido(Cedula);
			temp->getDatoPedido()->setPrecioPedido(precio);
			temp->getDatoPedido()->setHoraRealizado(hora);//IF HORAEntregado = 0 
			temp->getDatoPedido()->setEstadoPedido("En camino");
			return true;
		}
		temp = temp->getSig();
	}
	return false;
}

std::string ListaPedidos::mostrarPedido(ListaCliente* lcli, std::string ced) {
	Nodo* tempCli = lcli->getCabeza();

	std::stringstream x;

	Nodo* tempPedido = cabeza;

	if (tempPedido == nullptr) {

		x << "\t\tEl cliente aún no tiene pedidos realizados" << std::endl;

		return x.str();

	}

	while (tempPedido != nullptr) {

		while (tempCli != nullptr){

			if (ced == tempPedido->getDatoPedido()->getIDPedido()) {

				x << tempPedido->getDatoPedido()->toStringPedido();

			}

			tempCli = tempCli->getSig();
		}
		tempPedido = tempPedido->getSig();
	}

	return x.str();
}