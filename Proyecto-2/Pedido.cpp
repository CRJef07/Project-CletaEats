#include "Pedido.h"

Pedido::Pedido(){
	idPedido = "*";
	precioPedido = 0;
	horaRealizado = 0;
	horaEntregado = 0;
	estadoPedido = "*";
	nombreCliente = "";
	nombreRestaurante = "";
	nombreRepartidor = "";
} 

Pedido::Pedido(std::string idPedido, float precioPedido, int horaRealizado, int horaEntregado, std::string estadoPedido, std::string nombreCliente, std::string nombreRestaurante, std::string nombreRepartidor){
	this->idPedido = idPedido;
	this->precioPedido = precioPedido;
	this->horaRealizado = horaRealizado;
	this->horaEntregado = horaEntregado;
	this->estadoPedido = estadoPedido;

	this->nombreCliente = nombreCliente;
	this->nombreRestaurante = nombreRestaurante;
	this->nombreRepartidor = nombreRepartidor;
}

Pedido::~Pedido(){}

void Pedido::setIDPedido(const std::string& idPedido) {
	this->idPedido = idPedido;
}

const std::string & Pedido::getIDPedido() const{
	return idPedido;
}

void Pedido::setPrecioPedido(const float& precioPedido){
	this->precioPedido = precioPedido;
}
const float& Pedido::getPrecioPedido() const{
	return precioPedido;
}

void Pedido::setHoraRealizado(const int& horaRealizado){
	this->horaRealizado = horaRealizado ;
}
const int& Pedido::getHoraRealizado() const{
	return horaRealizado;
}

void Pedido::setHoraEntregado(const int& horaEntregado){
	this->horaEntregado = horaEntregado;
}
const int& Pedido::getHoraEntregado() const{
	return horaEntregado;
}

void Pedido::setEstadoPedido(const std::string& estadoPedido){
	this->estadoPedido = estadoPedido;
}
const std::string& Pedido::getEstadoPedido() const{
	return estadoPedido;
}


void Pedido::setNombreCliente(const std::string& nombreCliente){
	this->nombreCliente = nombreCliente;
}

const std::string& Pedido::getNombreCliente(){
	return nombreCliente;
}

void Pedido::setNombreRestaurante(const std::string& nombreRestaurante){
	this->nombreRestaurante = nombreRestaurante;
}

const std::string& Pedido::getNombreRestaurante(){
	return nombreRestaurante;
}

void Pedido::setNombreRepartidor(const std::string& nombreRepartidor){
	this->nombreRepartidor = nombreRepartidor;
}

const std::string& Pedido::getNombreRepartidor(){
	return nombreRepartidor;
}

std::string Pedido::toStringPedido(){
	std::stringstream p2;


		p2 << "Pedidos del cliente: " << getNombreCliente() << std::endl;
		p2 << "El ID de su pedido es: " << getIDPedido() << std::endl;
		p2 << "El precio de su pedido es: " << getPrecioPedido() << std::endl;
		

		if (getHoraRealizado() < 12) {
			p2 << "Su pedido fue realizado a las: " << getHoraRealizado() << " AM" << std::endl;
		}else {
			p2 << "Su pedido fue realizado a las: " << (getHoraRealizado()-12) << " PM" << std::endl;
		}

		p2 << "El nombre del repartidor es: " << getNombreRepartidor() << std::endl;//NO DEVUELVE EL NOMBRE DEL REPARTIDOR
		p2 << "Pedido realizo al restaurante: " << getNombreRestaurante() << std::endl;
		p2 << "El estado de su pedido es: " << getEstadoPedido() << std::endl;

		if (getHoraEntregado() == 0) {
			p2 << "Su pedido a�n no ha sido entregado" << std::endl;
		}else {
			if (getHoraEntregado() < 12) {
				p2 << "Su pedido fue entregado a las: " << getHoraEntregado() << " AM" << std::endl;
			}else {
				p2 << "Su pedido fue entregado a las: " << ( getHoraEntregado() - 12) << " PM" << std::endl;
			}
			
		}


	
	p2 << "-------------------------------------------------------" << std::endl;

	return p2.str();
}

void Pedido::autoGuardarPedido(std::ofstream& archivoGuardar){
	archivoGuardar << idPedido << '|';//string
	archivoGuardar << precioPedido << '|';//float
	archivoGuardar << horaRealizado << '|';//int
	archivoGuardar << horaEntregado << '|';//int
	archivoGuardar << estadoPedido << '|';//string
	archivoGuardar << nombreCliente << '|';//string
	archivoGuardar << nombreRestaurante << '|';//string
	archivoGuardar << nombreRepartidor << std::endl;//string
}

Pedido& Pedido::autoCargarPedido(std::ifstream& archivoCargar){
	std::string id, precio, horaR, horaE, estado, nCliente, nResta, nRepa;

	std::getline(archivoCargar, id, '|');
	std::getline(archivoCargar, precio, '|');
	std::getline(archivoCargar, horaR, '|');
	std::getline(archivoCargar, horaE, '|');
	std::getline(archivoCargar, estado, '|');
	std::getline(archivoCargar, nCliente, '|');
	std::getline(archivoCargar, nResta, '|');
	std::getline(archivoCargar, nRepa, '\n');

	float precioFlotante = convertirFloatPedido(precio);
	int horaRe = convertirIntPedido(horaR);
	int horaEn = convertirIntPedido(horaE);

	return ( *new Pedido(id,precioFlotante,horaRe,horaEn,estado,nCliente,nResta,nRepa) );
}

int Pedido::convertirIntPedido(std::string entero){
	std::stringstream x(entero);

	int variableInt = -1;

	x >> variableInt;

	return variableInt;
}

float Pedido::convertirFloatPedido(std::string flotante){
	std::stringstream x(flotante);

	float variableInt = -1;

	x >> variableInt;

	return variableInt;
}
