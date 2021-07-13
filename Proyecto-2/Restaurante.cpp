#include "Restaurante.h"

Restaurante::Restaurante(){
	nombre="";
	cedulaJuridica="";
	direccion="";
	tipoDeComida="";
	resenna = 0;
	for (int i = 0; i < 9; i++) {
		vector[i] = new Combo("","","",0,0);
	}
	cant = 0;
	contador = 0;
}
Restaurante::Restaurante(std::string nombre, std::string cedulaJuridica, std::string direccion, std::string tipoDeComida,float resenna, std::string principal, std::string acompannamiento, std::string bebida, int precio, int cant, int contador) {
	this->nombre=nombre;
	this->cedulaJuridica=cedulaJuridica;
	this->direccion=direccion;
	this->tipoDeComida=tipoDeComida;
	this->resenna = resenna;
	for (int i = 0; i < 9; i++) {
		vector[i] = new Combo(principal,acompannamiento,bebida,precio,cant);
	}
	this->contador = contador;
}
Restaurante::~Restaurante(){
	for (int i = 0; i < 9; i++) {
		delete vector[i];
	}
}
const std::string &Restaurante::getNombre()const {
	return nombre;
}
void Restaurante::setNombre(const std::string &nombre) {
	this->nombre = nombre;
}

const std::string &Restaurante::getCedulaJuridica() const {
	return cedulaJuridica;
}

void Restaurante::setCedulaJuridica(const std::string &cedulaJuridica) {
	this->cedulaJuridica = cedulaJuridica;
}

const std::string &Restaurante::getDireccion() const {
	return direccion;
}
void Restaurante::setDireccion(const std::string &direccion) {
	this->direccion = direccion;
}

const std::string &Restaurante::getTipoDeComida() const {
	return tipoDeComida;
}
void Restaurante::setTipoDeComida(const std::string &tipoDeComida) {
	this->tipoDeComida = tipoDeComida;
}

const float & Restaurante::getResenna() const
{
	return resenna;
}

void Restaurante::setResenna(const float & resenna)
{
	this->resenna = resenna;
}

const int& Restaurante::getPedidos() const
{
	return contador;
}

void Restaurante::setPedidos(const int& c)
{
	this->contador = c;
}





std::string Restaurante::toString()
{
	std::stringstream x;

	x << "El nombre del restaurante es: " << nombre << std::endl;
	x << "La cedula juridica del restaurante es: " << cedulaJuridica << std::endl;
	x << "La direccion del restaurante es: " << direccion << std::endl;
	x << "El tipo de comida que ofrese el restaurante es: " << tipoDeComida << std::endl;
	x << "Las reseñas del restaurante son de: " << resenna << std::endl;
	x << "\n\n";
	
	return x.str();
}

std::string Restaurante::toStringParaCliente(){

	std::stringstream x;
	x << "El nombre del restaurante es: " << nombre << std::endl;
	x << "La direccion del restaurante es: " << direccion << std::endl;
	x << "El tipo de comida que ofrese el restaurante es: " << tipoDeComida << std::endl;
	x << "Combos:\n";
	x << mostarCombos();

	return x.str();
}

Combo* Restaurante::getPtCombo()
{
	return ptCombo;
}

void Restaurante::setPtCombo(Combo* pt)
{
	this->ptCombo=pt;
}

void Restaurante::enviarACombo(std::string prin, std::string acom, std::string bebi, int precio, int cant){
	vector[cant]->setPrincipal(prin);
	vector[cant]->setAcompannamiento(acom);
	vector[cant]->setBebida(bebi);
	vector[cant]->setPrecio(precio);
		
	
}

std::string Restaurante::mostarCombos()
{
	std::stringstream x;
	for (int i = 0; i < 9; i++) {
		
		x << "\t\tCOMBO " << i+1 << "\n";
		x << vector[i]->toString() << std::endl;
		//x <<  "------------------------------------------------------\n";
		
	}
	return x.str();
}

std::string Restaurante::archivoCombo()
{
	std::stringstream x;
	for (int i = 0; i < 9; i++) {
		x << vector[i]->toStringArchivo();
		
	}
	x << "\n";
	return x.str();
}

std::string Restaurante::escogerCombo(int num)
{std::stringstream x;
	for (int i = 0; i < 9; i++) {
		if (i == num) {
			
			x<<vector[i]->toString();
			
		}
	}
	return x.str();
}
