#ifndef CONTROL_H
#define CONTROL_H

#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <Windows.h>
#include "Archivo.h"
#include <thread>

class Control {
public:
	void MenuPrincipal(ListaCliente*,Archivo*,ListaRepartidor*, ListaPedidos* listaP);
	void subMenuCliente(ListaCliente*, ListaRepartidor*, ListaRestaurante*, ListaPedidos*,ListaCalificacion*);
	void subMenuRepartidor(ListaRepartidor*, ListaPedidos*, ListaCliente*, ListaCalificacion*);
	void subMenuRestaurante(ListaRestaurante*);
	void subMenuAdmin(ListaCliente*, ListaRepartidor*, ListaRestaurante*, ListaPedidos*, Archivo*);
	void SubMenuReportes(ListaCliente*, ListaRepartidor*, ListaRestaurante*, ListaPedidos*, ListaCalificacion*);

	void agregarCliente(ListaCliente*, std::string);
	void eliminarCliente(ListaCliente*, std::string);
	void verListaCliente(ListaCliente*);

	void agregarRepartidor(ListaRepartidor*, std::string);
	void eliminarRepartidor(ListaRepartidor*, std::string);

	void verListaReparidor(ListaRepartidor*);
	void verListaRepartidor(ListaRepartidor*,ListaPedidos*);//-----------

	void aumentarPedidosRepa(ListaRepartidor*, std::string);

	void agregarRestaurante(ListaRestaurante*);
	void eliminarRestaurante(ListaRestaurante*, std::string);
	void verListaRestaurante(ListaRestaurante*);
	void crearRestaurantes(ListaRestaurante*);
	void aumentarPedidosRest(ListaRestaurante*, std::string);

	std::string iniciarSesion(ListaCliente*);
	std::string iniciarSesionRepa(ListaRepartidor*, ListaPedidos*);

	void realizarPedido(ListaCliente*, ListaRepartidor*, ListaRestaurante*, ListaPedidos*, std::string);
	std::string asignarRepartidor(ListaRepartidor*, ListaPedidos*);//primero disponible de la lista
	bool validarIDCliente(ListaCliente*, std::string);

	void diasHabiles(ListaRepartidor*, std::string);
	void diasFeriados(ListaRepartidor*, std::string);
	void extraPorDiasFeriados(ListaRepartidor*, ListaPedidos*, std::string);

	void aumentarAmonestaciones(ListaRepartidor*, ListaCalificacion*);

	void cambiarEstadoPedido(ListaPedidos*, ListaRepartidor*, ListaCliente*, std::string);
	float randearDistancia();
	void Cargando();

	void cambiarEstadoPedidoRest(ListaPedidos* lp, ListaRepartidor* repa, ListaCliente* lc, std::string id);

	void calificarRepartidor(ListaRepartidor*);

	//bool validarIDRepartidor(ListaRepartidor*, std::string);
	bool validarEstadoCliente(ListaCliente*, std::string);
	void aumentarPedidos(ListaCliente*, std::string);
	void aumentarRepartidor(ListaRepartidor* liCli, std::string id);
	void aumentarRestaurante(ListaRestaurante* liCli, std::string id);
	void agregarPedido(ListaPedidos*, float, std::string, std::string, std::string, std::string);

	std::string mostrarPedidoEspecifico(ListaCliente*, ListaPedidos*, std::string Cedula, std::string);
	std::string mostrarPedido(ListaCliente*, ListaPedidos*, std::string Cedula);
	std::string mostrarPedidoRepartidor(ListaRepartidor*, ListaPedidos*, std::string Cedula);

	bool verificarNumero(std::string linea);
	int retornarNumero();
	std::string idRandom();
	bool validarEstadoRepartidor(ListaRepartidor*, std::string);
	bool validarAmonestaciones(ListaRepartidor*, std::string);
	bool validarIDRepartidor(ListaRepartidor*, std::string);

	std::string mostarClientesActivos(ListaCliente*);
	std::string mostarClientesSuspendidos(ListaCliente* lc);
	std::string enviarCedulaJud(ListaRestaurante* lr, ListaPedidos*);

	void ventasMayores(ListaRestaurante* lr, ListaPedidos* lp);

	void numMayor(int,int,int,int,int,int,int);

};

#endif // !CONTROL_H
