#include "Calificacion.h"
#include <iostream>
Calificacion::Calificacion()
{
	amabilidad="";
	tiempoDeRespuesta="";
	presentacion="";
	quejas="";

}

Calificacion::Calificacion(std::string amabilidad, std::string tiempoDeRespuesta, std::string presentacion, std::string quejas)
{
	this->amabilidad = amabilidad;
	this->tiempoDeRespuesta = tiempoDeRespuesta;
	this->presentacion = presentacion;
	this->quejas = quejas;
}

Calificacion::~Calificacion()
{
}

std::string Calificacion::getAmabilidad() {
	return amabilidad;
}
void Calificacion::setAmabilidad(std::string amabilidad) {
	this->amabilidad = amabilidad;
}

std::string Calificacion::getTiempoDeRespuesta() {
	return tiempoDeRespuesta;
}
void Calificacion::setTiempoDeRespuesta(std::string tiempoDeRespuesta) {
	this->tiempoDeRespuesta = tiempoDeRespuesta;
}

std::string Calificacion::getPresentacion() {
	return presentacion;
}
void Calificacion::setPresentacion(std::string presentacion) {
	this->presentacion = presentacion;
}

std::string Calificacion::getQuejas() {
	return quejas;
}
void Calificacion::setQuejas(std::string quejas) {
	this->quejas = quejas;
}

std::string Calificacion::toString()
{
	std::stringstream x;
	x << "Amabilidad: " << amabilidad << "\n";
	x << "Tiempo de respuesta: " << tiempoDeRespuesta << "\n";
	x << "Presentacion: " << presentacion << "\n";
	x << "Quejas: " << quejas << "\n";
	return x.str();
}


Calificacion& Calificacion::autoCargarC(std::ifstream& calif)
{

	std::string amabilidad, tiempo, presentacion, quejas;


	std::getline(calif, amabilidad, '*');
	std::getline(calif, tiempo, '*');
	std::getline(calif, presentacion, '*');
	std::getline(calif, quejas, '.');
	

	return (*new Calificacion(amabilidad, tiempo, presentacion, quejas));
	
}

void Calificacion::autoGuardarC(std::ofstream& archivoGuardar)
{
	
		archivoGuardar << amabilidad << '*';
		archivoGuardar << tiempoDeRespuesta << '*';
		archivoGuardar << presentacion << '*';
		archivoGuardar << quejas << '.';
		
	//archivoGuardar << "\n";
}
