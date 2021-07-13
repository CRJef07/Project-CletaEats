#include "Repartidor.h"

Repartidor::Repartidor(){
	this->estado=false;
	this->distanciaPedido=0;
	this->kmRecorridos=0;
	this->disponibilidad=false;
	this->amonestaciones=0;
	this->resenna = 0;
	this->nombre = "";
	this->cedula = "";
	this->correo = "";
	this->direccion = "";
	this->tarjeta = 0;
	this->telefono = 0;
	this->lCalif = new ListaCalificacion;
	

}
Repartidor::Repartidor(std::string nombre, std::string cedula, std::string correo, std::string direccion, int tarjeta, int telefono, bool estado, float distanciaPedido, float kmRecorridos, bool disponibilidad, int amonestaciones, float resenna,int pedidos) : Persona(nombre, cedula, correo, direccion, tarjeta, telefono, estado) {
	
	this->distanciaPedido = distanciaPedido;
	this->kmRecorridos = kmRecorridos;
	this->disponibilidad = disponibilidad;
	this->amonestaciones = amonestaciones;
	this->resenna = resenna;
	this->pedidos = pedidos;
	this->lCalif = new ListaCalificacion;
	
	

}

Repartidor::~Repartidor(){
	
}


const float & Repartidor::getDistanciaPedido()const {
	return distanciaPedido;
}
void Repartidor::setDistanciaPedido(const float &distanciaPedido) {
	this->distanciaPedido = distanciaPedido;
}

const float & Repartidor::getKmRecorridos()const {
	return kmRecorridos;
}
void Repartidor::setKmRecorridos(const float & kmRecorridos) {
	this->kmRecorridos = kmRecorridos;
}

const bool & Repartidor::getDisponibilidad() const {
	return disponibilidad;
}
void Repartidor::setDisponibilidad(const bool & disponibilidad) {
	this->disponibilidad = disponibilidad;
}

const int & Repartidor::getAmonestaciones() const {
	return amonestaciones;
}
void Repartidor::setAmonestaciones(const int & amonestaciones) {
	this->amonestaciones = amonestaciones;
}

const float& Repartidor::getResenna() const
{
	return resenna;
}
void Repartidor::setResenna(const float& resenna)
{
	this->resenna = resenna;
}

const int& Repartidor::getPedidos() const
{
	return pedidos;
}

void Repartidor::setPedidos(const int&)
{
	this->pedidos = pedidos;
}

ListaCalificacion* Repartidor::getLCalif()
{
	return lCalif;
}




std::string Repartidor::toStringRepa() {
	std::stringstream s;
	s << toString() << std::endl;
	s<<"La distancia del pedido es de: "<<distanciaPedido<<std::endl;
	s << "El total de kilometros recorridos por el repartidos son: " << kmRecorridos << std::endl;
	if (disponibilidad==true) {
		s << "Es dia normal" << std::endl;
	}
	else {
		s<<"Es dia feriado"<<std::endl;
	}
	s<<"El numero de amonestaciones del repartidor es de: "<<amonestaciones<<std::endl;
	s<<"La calificacion del repartidor es de: "<<resenna<<std::endl;
	s << "La cantidad de reparticiones que ha hecho es de: " << pedidos <<std::endl;
	s << "\n\nLos comentarios dejados para el cliente son: \n\n";
	s << "----------------------------------------------------------";
	return s.str();
}

std::string Repartidor::toStringParaCliente()
{
	std::stringstream x;
	x << toString() << "\n";

	x << "--------------------------------------------------------\n";
	return x.str();
}












void Repartidor::autoGuardar(std::ofstream& archivoGuardar){
	archivoGuardar << nombre << '+';
	archivoGuardar << cedula << '+';
	archivoGuardar << correo << '+';
	archivoGuardar << direccion << '+';
	archivoGuardar << tarjeta << '+';
	archivoGuardar << telefono << '+';
	archivoGuardar << estado << '+';
	archivoGuardar << distanciaPedido << '+';
	archivoGuardar << kmRecorridos << '+';
	archivoGuardar << disponibilidad << '+';
	archivoGuardar << amonestaciones << '+';
	archivoGuardar << resenna << '+';
	archivoGuardar << pedidos << '|';
}

Repartidor& Repartidor::autoCargar(std::ifstream& archivoCargarRepartidores){
	std::string nombre, cedula, correo, direccion, tarjeta, telefono, estado, distancia, km, disponibilidad, amonestaciones, resenna, pedidos;

		std::getline(archivoCargarRepartidores, nombre, '+');
		std::getline(archivoCargarRepartidores, cedula, '+');
		std::getline(archivoCargarRepartidores, correo, '+');
		std::getline(archivoCargarRepartidores, direccion, '+');
		std::getline(archivoCargarRepartidores, tarjeta, '+');
		std::getline(archivoCargarRepartidores, telefono, '+');
		std::getline(archivoCargarRepartidores, estado, '+');
		std::getline(archivoCargarRepartidores, distancia, '+');
		std::getline(archivoCargarRepartidores, km, '+');
		std::getline(archivoCargarRepartidores, disponibilidad, '+');
		std::getline(archivoCargarRepartidores, amonestaciones, '+');
		std::getline(archivoCargarRepartidores, resenna, '+');
		std::getline(archivoCargarRepartidores, pedidos, '|');

		int numeroI = convertirInt(estado);
		int numeroI2 = convertirInt(tarjeta);
		int numeroI3 = convertirInt(telefono);
		int numeroI4 = convertirInt(amonestaciones);
		int numeroI5 = convertirInt(disponibilidad);
		int numeroI6 = convertirInt(pedidos);
		float numeroF = convertirFloat(distancia);
		float numeoF2 = convertirFloat(km);
		float numeroF3 = convertirFloat(resenna);


	return ( *new Repartidor(nombre,cedula,correo,direccion, numeroI2, numeroI3, numeroI, numeroF,numeoF2,numeroI5, numeroI4, numeroF3, numeroI6) );
}

float Repartidor::convertirFloat(std::string dato)
{
	std::stringstream x(dato);

	float variableFloat = 0;

	x >> variableFloat;

	return variableFloat;
}

int Repartidor::convertirInt(std::string dato)
{
	std::stringstream x(dato);

	int variableint = 0;

	x >> variableint;

	return variableint;
}