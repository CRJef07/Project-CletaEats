#ifndef REPARTIDOR_H
#define REPARTIDOR_H

#include "Persona.h"

#include "ListaCalificacion.h"

//ES UNA CLASE HIJA DE LA CLASE PERSONA
class Repartidor: public Persona {
public:
	Repartidor();
	Repartidor(std::string , std::string , std::string , std::string , int , int , bool , float , float , bool , int , float,int);
	~Repartidor();

	const float & getDistanciaPedido()const;
	void setDistanciaPedido(const float & );

	const float & getKmRecorridos()const;
	void setKmRecorridos(const float & );

	const bool & getDisponibilidad()const;
	void setDisponibilidad(const bool & );

	const int & getAmonestaciones()const;
	void setAmonestaciones(const int & );

	const float & getResenna()const;
	void setResenna(const float & );

	const int& getPedidos()const;
	void setPedidos(const int&);

	ListaCalificacion* getLCalif();

	
	std::string toStringRepa();
	std::string toStringParaCliente();


	void autoGuardar(std::ofstream&);
	Repartidor& autoCargar(std::ifstream& );
	float convertirFloat(std::string);
	int convertirInt(std::string);
private:
	
	float distanciaPedido;
	float kmRecorridos;
	bool disponibilidad;
	int amonestaciones;
	float resenna;
	ListaCalificacion* lCalif;
	int pedidos;
};
#endif