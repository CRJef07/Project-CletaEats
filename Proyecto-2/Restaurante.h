#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include "Combo.h"
class Restaurante{
public:

	Restaurante();
	Restaurante(std::string , std::string , std::string , std::string , float , std::string , std::string , std::string , int , int, int );
	~Restaurante();
	const std::string &getNombre()const;
	void setNombre(const std::string &);

	const std::string &getCedulaJuridica()const;
	void setCedulaJuridica(const std::string &);

	const std::string &getDireccion()const;
	void setDireccion(const std::string &);

	const std::string &getTipoDeComida()const;
	void setTipoDeComida(const std::string &);

	const float& getResenna() const;
	void setResenna(const float & );

	const int& getPedidos() const;
	void setPedidos(const int&);

	std::string toString();
	std::string toStringParaCliente();
	Combo* getPtCombo();
	void setPtCombo(Combo*);
	void enviarACombo(std::string,std::string,std::string,int,int);
	std::string mostarCombos();
	std::string archivoCombo();
	std::string escogerCombo(int );
private:
	std::string nombre;
	std::string cedulaJuridica;
	std::string direccion;
	std::string tipoDeComida;
	float resenna;
	int contador;
	Combo* ptCombo;
	Combo* vector[9];
	int cant;
	
};
#endif