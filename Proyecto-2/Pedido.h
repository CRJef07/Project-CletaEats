#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <sstream>
#include<ctime>
#include <fstream>

class Pedido{
public:
	Pedido();
	Pedido(std::string idPedido, float precioPedido, int horaRealizado, int horaEntregado, std::string estadoPedido, std::string nombreCliente, std::string nombreRestaurante,	std::string nombreRepartidor);
	~Pedido();

	void setIDPedido(const std::string & idPedido);
	const std::string & getIDPedido()const;
	
	void setPrecioPedido(const float & precioPedido);
	const float & getPrecioPedido()const;

	void setHoraRealizado(const int & horaRealizado);
	const int & getHoraRealizado()const;

	void setHoraEntregado(const int & horaEntregado);
	const int & getHoraEntregado()const;

	void setEstadoPedido(const std::string& estadoPedido);
	const std::string & getEstadoPedido()const;


	void setNombreCliente(const  std::string & nombreCliente);
	const std::string& getNombreCliente();

	void setNombreRestaurante(const std::string & nombreRestaurante);
	const std::string& getNombreRestaurante();

	void setNombreRepartidor(const std::string & nombreRepartidor);
	const std::string& getNombreRepartidor();

	std::string toStringPedido();

	void autoGuardarPedido(std::ofstream&);//out file
	Pedido & autoCargarPedido(std::ifstream&);//imput file

	int convertirIntPedido(std::string);
	float convertirFloatPedido(std::string);

private:
	std::string idPedido;
	float precioPedido;
	int horaRealizado;
	int horaEntregado;
	std::string estadoPedido;

	std::string nombreCliente;//ASIGNADO PARA DICHO PEDIDO
	std::string nombreRestaurante;//ASIGNADO PARA DICHO PEDIDO
	std::string nombreRepartidor;//ASIGNADO PARA DICHO PEDIDO
};
#endif // !PEDIDO_H