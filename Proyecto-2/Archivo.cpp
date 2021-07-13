#include "Archivo.h"


/*CLIENTE*/
int Archivo::convertirInt(std::string entero) {

	std::stringstream x(entero);

	int variableInt = -1;

	x >> variableInt;

	return variableInt;
}

bool Archivo::convertirBolean(std::string bolean) {

	std::stringstream x(bolean);

	bool variableBool = 0;

	x >> variableBool;

	return variableBool;
}
void Archivo::escribirCliente(ListaCliente* lisCli){
	std::ofstream archivoEscribir;
	archivoEscribir.open("Clientes.txt");

	Nodo* temp = lisCli->getCabeza();

	while (temp != nullptr) {
		Cliente* nuevoCliente = temp->getDatoC();
		nuevoCliente->autoGuardar(archivoEscribir);
		temp = temp->getSig();
	}

	archivoEscribir.close();
}
ListaCliente* Archivo::leerCliente(){
	Cliente* auxCliente;//ESTÁTICA
	Cliente* nuevoCliente = new Cliente;//DINÁMICO
	ListaCliente* nuevaLista = new ListaCliente;//LISTA DINÁMICA
	std::ifstream infile;

	infile.open("Clientes.txt");
	if (!infile || infile.good() == false) {// archivoLeer.fail() == true
		infile.close();
		return nuevaLista;
	}	

	while (infile.eof()==false) {// archivoLeer.eof()==false
		auxCliente = &nuevoCliente->autoCargar(infile);
		if (auxCliente->getNombre() != "") {
			nuevaLista->agregar(auxCliente);
		}
	}	
	infile.close();
	return nuevaLista;
}
/*CLIENTE*/



//REPARTIDOR
//-----------------------------------------------------------------------------------------------------
void Archivo::escribirRepartidor(ListaRepartidor* lr){
	std::ofstream archivoEscribir;
	archivoEscribir.open("Repartidor.txt");

	Nodo* temp = lr->getCabeza();

	while (temp != nullptr) {
		Repartidor* repa = temp->getDatoRepa();
		Calificacion* calif = new Calificacion;
		repa->autoGuardar(archivoEscribir);
		calif->autoGuardarC(archivoEscribir);
		temp = temp->getSig();
	}

	archivoEscribir.close();
}
ListaRepartidor* Archivo::leerRepartidor() {
	Repartidor* aux;
	Repartidor* repa = new Repartidor;

	Calificacion* aux2;
	Calificacion* calif = new Calificacion;

	ListaRepartidor* nuevaLista = new ListaRepartidor;
	std::ifstream infile;

	infile.open("Repartidor.txt");
	if (!infile || infile.good() == false) {
		infile.close();
		return nuevaLista;
	}

	while (infile.eof() == false) {

		aux = &repa->autoCargar(infile);
		aux2 = &calif->autoCargarC(infile);





		if (aux->getNombre() != "") {
			aux->getLCalif()->agregar(aux2);
			nuevaLista->agregar(aux);

		}
	}
	infile.close();
	return nuevaLista;
}

void Archivo::escribirPedido(ListaPedidos* lp){
	std::ofstream archivoEscribir;
	archivoEscribir.open("Pedidos.txt");

	Nodo* temp = lp->getCabeza();

	while (temp != nullptr){
		Pedido* nuevoPedido = temp->getDatoPedido();
		nuevoPedido->autoGuardarPedido(archivoEscribir);
		temp = temp->getSig();
	}
	archivoEscribir.close();
}

ListaPedidos* Archivo::leerPedido(){
	Pedido* auxPedido;
	Pedido* nuevoPedido = new Pedido;
	ListaPedidos* nuevaListaPedido = new ListaPedidos;
	std::ifstream archivoLeer;
	
	archivoLeer.open("Pedidos.txt");

	if (!archivoLeer || archivoLeer.fail()) {
		archivoLeer.close();
		return nuevaListaPedido;
	}
	while (!archivoLeer.eof()) {
		auxPedido = &nuevoPedido->autoCargarPedido(archivoLeer);
		if (auxPedido->getIDPedido() != "") {
			nuevaListaPedido->agregarPedido(auxPedido);
		}
	}

	archivoLeer.close();

	return nuevaListaPedido;
}



