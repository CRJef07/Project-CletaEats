#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

//ES UNA CLASE HIJA DE LA CLASE PERSONA
class Cliente: public Persona{
public:
	Cliente();
	Cliente(std::string nombre, std::string cedula, std::string correo, std::string direccion, int tarjeta, int telefono, bool estado, int pedidosRealizados);
	~Cliente();
	void setPedidosRealizados(const int&);
	const int & getPedidosRealizados()const;
	
	std::string toString();

	void autoGuardar(std::ofstream&);//out file
	Cliente& autoCargar(std::ifstream &);//imput file

	int convertirInt(std::string);
	bool convertirBolean(std::string);
private:
	int pedidosRealizados;
};
#endif