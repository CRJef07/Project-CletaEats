#include "Nodo.h"

void Nodo::setSig(Nodo* sig) {
	this->sig = sig;
}

Nodo* Nodo::getSig() {
	return sig;
}

Nodo::Nodo(Repartidor* repartidor){
	this->datoC = nullptr;
	this->datoRest = nullptr;
	this->datoPedido = nullptr;
	//this->datoRepa = nullptr;

	this->datoRepa = repartidor;
	this->sig = NULL;
}

void Nodo::setDatoRepa(Repartidor* datoRepartidor){
	this->datoRepa = datoRepartidor;
}

Repartidor* Nodo::getDatoRepa(){
	return datoRepa;
}

Nodo::Nodo(Cliente* c){
	//this->datoC = nullptr;
	this->datoRest = nullptr;
	this->datoRepa = nullptr;
	this->datoPedido = nullptr;

	this->datoC = c;
	this->sig = NULL;
}

void Nodo::setDatoC(Cliente* datoCliente){
	this->datoC = datoCliente;
}

Cliente* Nodo::getDatoC(){
	return datoC;
}

Nodo::Nodo(Restaurante* r){
	this->datoC = nullptr;
	//this->datoRest = nullptr;
	this->datoRepa = nullptr;
	this->datoPedido = nullptr;

	this->datoRest = r;
	this->sig = NULL;
}

void Nodo::setDatoRest(Restaurante* datoRestaurante){
	this->datoRest = datoRestaurante;
}

Restaurante* Nodo::getDatoRest(){
	return datoRest;
}

Nodo::Nodo(Pedido* p){
	this->sig = nullptr;
	this->datoC = nullptr;
	this->datoRepa = nullptr;
	this->datoRest = nullptr;
	this->datoPedido = p;

}

void Nodo::setDatoPedido(Pedido* p){
	this->datoPedido = p;
}

Pedido* Nodo::getDatoPedido(){
	return datoPedido;
}


