#ifndef LISTAPEDIDOS_H
#define LISTAPEDIDOS_H
#define _CRT_SECURE_NO_WARNINGS
#include "Nodo.h"
#include "ListaCliente.h"
#include "ListaRepartidor.h"
#include "ListaRestaurante.h"

class ListaPedidos{
public:
	ListaPedidos();//
	~ListaPedidos();//

	Nodo * getCabeza();//
	void setCabeza(Nodo*);//

	void agregarPedido(Pedido*);//
	bool eliminarPedido(std::string);//
	
	std::string mostrarLista();//

	void realizarPedido(ListaCliente*, ListaRepartidor*, ListaRestaurante*, std::string);
	bool asignarRepartidor(ListaRepartidor*);//primero disponible de la lista
	bool validarIDCliente(ListaCliente*, std::string);
	bool validarEstadoCliente(ListaCliente*, std::string);

	bool settearPedido(ListaCliente* liCli, std::string id, float precio, std::string Cedula);
	std::string mostrarPedido(ListaCliente*, std::string);
private:
	Nodo* cabeza;
};
#endif // !LISTAPEDIDOS_H