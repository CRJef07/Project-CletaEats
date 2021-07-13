#ifndef NODO_H
#define NODO_H

#include "Repartidor.h"
#include "Cliente.h"
#include "Restaurante.h"
#include "Pedido.h"

#include <fstream>

class Nodo{
public:
	void setSig(Nodo* sig);
	Nodo* getSig();

	Nodo(Repartidor*);
	void setDatoRepa(Repartidor*);
	Repartidor* getDatoRepa();

	Nodo(Cliente*);
	void setDatoC(Cliente *);
	Cliente* getDatoC();

	Nodo(Restaurante*);
	void setDatoRest(Restaurante*);
	Restaurante* getDatoRest();

	Nodo(Pedido*);
	void setDatoPedido(Pedido*);
	Pedido* getDatoPedido();
	
private:
	Nodo* sig;

	Repartidor* datoRepa;
	Cliente* datoC;
	Restaurante* datoRest;
	Pedido* datoPedido;
	
};
#endif

