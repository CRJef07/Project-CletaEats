#include "Control.h"
int main() {
    Control c1;
	
	Archivo* nuevoArchivo = new Archivo;//archivo dinámico

	ListaCliente* listaC = nuevoArchivo->leerCliente();//leémos un txt
	
    ListaRepartidor* listaR = nuevoArchivo->leerRepartidor();
	
	ListaPedidos* listaP = nuevoArchivo->leerPedido();

    c1.MenuPrincipal(listaC,nuevoArchivo, listaR, listaP);
	
    return 0;
}

