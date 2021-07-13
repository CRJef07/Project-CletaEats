#include "Persona.h"

Persona::Persona(){
//	std::cout << "Se ha construido una persona" << std::endl;
	nombre = "";
	cedula = "";
	correo = "";
	direccion = "";
	tarjeta = 0;
	telefono = 0;
	estado = false;
}
Persona::Persona(std::string nombre, std::string cedula, std::string correo, std::string direccion, int tarjeta, int telefono,bool estado ) {
	//std::cout << "Se ha construido una persona con parámetros" << std::endl;
	this->nombre = nombre;
	this->cedula = cedula;
	this->correo = correo;
	this->direccion = direccion;
	this->tarjeta = tarjeta;
	this->telefono = telefono;
	this->estado = estado;
}
Persona::~Persona(){
//	std::cout << "Se ha destruido una persona" << std::endl;
}
const std::string &Persona::getNombre()const {
	return nombre;
}
void Persona::setNombre(const std::string &nombre) {
	this->nombre = nombre;
}

const std::string &Persona::getCedula()const {
	return cedula;
}
void Persona::setCedula(const std::string &cedula) {
	this->cedula = cedula;
}

const std::string &Persona::getCorreo()const {
	return correo;
}
void Persona::setCorreo(const std::string &correo) {
	this->correo = correo;
}

const std::string &Persona::getDireccion()const {
	return direccion;
}
void Persona::setDireccion(const std::string &direccion) {
	this->direccion = direccion;
}

const int &Persona::getTarjeta()const {
	return tarjeta;
}
void Persona::setTarjeta(const int &tarjeta) {
	this->tarjeta = tarjeta;
}

const int &Persona::getTelefono()const {
	return telefono;
}
void Persona::setTelefono(const int &telefono) {
	this->telefono = telefono;
}

const bool& Persona::getEstado() const{
	return estado;
}

void Persona::setEstado(const bool& estado){
	this->estado = estado;
}

std::string Persona::toString(){
	std::stringstream s;

	s << "El nombre es: " << nombre << std::endl;
	s << "La cedula es: " << cedula << std::endl;
	s << "El correo electronico es: " << correo << std::endl;
	s << "La direccion exacta es: " << direccion << std::endl;
	s << "El numero de la tarjeta es: " << tarjeta << std::endl;
	s << "El numero de telefono es: " << telefono << std::endl;

	return s.str();
}

