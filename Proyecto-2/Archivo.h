#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "ListaCliente.h"
#include "ListaRepartidor.h"
#include "ListaRestaurante.h"
#include "ListaPedidos.h"
#include "ListaCalificacion.h"

class Archivo{
public:
	//CLIENTE
	int convertirInt(std::string);
	bool convertirBolean(std::string);
	void escribirCliente(ListaCliente*);//GUARDAR EN UN TXT
	ListaCliente * leerCliente();//LEER UN TXT
	//CLIENTE

	//REPARTIDOR
	void escribirRepartidor(ListaRepartidor*);
	ListaRepartidor* leerRepartidor();
	
	void escribirPedido(ListaPedidos*);//GUARDAR EN UN TXT
	ListaPedidos* leerPedido();//LEER UN TXT

};
#endif // !ARCHIVO_H