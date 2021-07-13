#include "Cliente.h"

Cliente::Cliente(){
	//std::cout << "Se ha construido un cliente" << std::endl;
	Persona::setNombre("");
	Persona::setCedula("");
	Persona::setCorreo("");
	Persona::setDireccion("");
	Persona::setTarjeta(0);
	Persona::setTelefono(0);
	Persona::setEstado(false);
	this->pedidosRealizados = 0;
	
	//this->nombre = "";
	//this->cedula = "";
	//this->correo = "";
	//this->direccion = "";
	//this->tarjeta = 0;
	//this->telefono = 0;
	//this->estado = false;
}
Cliente::Cliente(std::string nombre, std::string cedula, std::string correo, std::string direccion, int tarjeta, int telefono, bool estado, int pedidosRealizados): Persona(nombre, cedula, correo, direccion, tarjeta,telefono, estado) {
	this->pedidosRealizados = pedidosRealizados;
}
Cliente::~Cliente(){}

void Cliente::setPedidosRealizados(const int& p){
	this->pedidosRealizados = p;
}

const int& Cliente::getPedidosRealizados() const{
	return pedidosRealizados;
}

std::string Cliente::toString() {
	std::stringstream c;

	c << Persona::toString();
	c << "Pedidos realizados: " <<pedidosRealizados << std::endl;
	
	return c.str();
}

void Cliente::autoGuardar(std::ofstream& archivoGuardar){//out file ESCRIBE
	archivoGuardar << nombre << '|';
	archivoGuardar << cedula << '|';
	archivoGuardar << correo << '|';
	archivoGuardar << direccion << '|';
	archivoGuardar << tarjeta << '|';
	archivoGuardar << telefono << '|';
	archivoGuardar << estado << '|';
	archivoGuardar << pedidosRealizados << std::endl;
}

Cliente& Cliente::autoCargar(std::ifstream& archivoCargar){//imput file LEER 
	std::string nombreC, cedulaC, correoC, direccionC, tarjetaC, telefonoC, pedidosRealizadosC,  estadoC;
	
	std::getline(archivoCargar, nombreC,'|');
	std::getline(archivoCargar, cedulaC, '|');
	std::getline(archivoCargar, correoC, '|');
	std::getline(archivoCargar, direccionC, '|');

	std::getline(archivoCargar, tarjetaC, '|');
	int numTarjeta = convertirInt(tarjetaC);

	std::getline(archivoCargar, telefonoC, '|');
	int numTelefono = convertirInt(telefonoC);

	std::getline(archivoCargar, estadoC, '|');
	bool estadoNuevo = convertirBolean(estadoC);

	std::getline(archivoCargar, pedidosRealizadosC, '\n');
	int numPedidos = convertirInt(pedidosRealizadosC);

	return ( *new Cliente(nombreC,cedulaC,correoC,direccionC, numTarjeta, numTelefono, estadoNuevo, numPedidos) );
}

int Cliente::convertirInt(std::string entero){

	std::stringstream x(entero);

	int variableInt = -1;

	x >> variableInt;

	return variableInt;
}

bool Cliente::convertirBolean(std::string bolean){

	std::stringstream x(bolean);

	bool variableBool = 0;

	x >> variableBool;

	return variableBool;
}


//archivoCargar >> tarjetaC;//convertirlo
//archivoCargar >> telefonoC;//convertirlo
//archivoCargar >> estadoC;//convertirlo
//archivoCargar >> pedidosRealizadosC;//convertirlo