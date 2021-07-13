#include "Combo.h"

Combo::Combo(std::string principal, std::string acompannamiento, std::string bebida, int precio, int cant)
{
	this->principal = principal;
	this->acompannamiento = acompannamiento;
	this->bebida = bebida;
	this->precio = precio;
	this->cant = cant;
}

Combo::~Combo()
{
}

std::string Combo::getPrincipal() {
	return principal;
}
void Combo::setPrincipal(std::string principal) {
	this->principal = principal;
}

std::string Combo::getAcompannamiento() {
	return acompannamiento;
}
void Combo::setAcompannamiento(std::string acompannamiento) {
	this->acompannamiento = acompannamiento;
}

std::string Combo::getBebida() {
	return bebida;
}
void Combo::setBebida(std::string bebida) {
	this->bebida = bebida;
}

int Combo::getPrecio() {
	return precio;
}
void Combo::setPrecio(int precio) {
	this->precio = precio;
}

std::string Combo::toString()
{
	std::stringstream x;
	x << "El plato principal es: " << principal << std::endl;
	x << "El acompannamiento es: " << acompannamiento << std::endl;
	x << "La bebida es: " << bebida << std::endl;
	x << "El precio es: " << precio << " colones" << std::endl;
	x << "------------------------------------------\n";
	return x.str();
}

std::string Combo::toStringArchivo()
{
	std::stringstream x;
	x << principal << " - ";
	x << acompannamiento << " - ";
	x << bebida << " - ";
	x << precio << "*";

	return x.str();
}
