#include "Control.h"
int main() {
    Control c1;
	
	Archivo* nuevoArchivo = new Archivo;//archivo din�mico

	ListaCliente* listaC = nuevoArchivo->leerCliente();//le�mos un txt
	
    ListaRepartidor* listaR = nuevoArchivo->leerRepartidor();
	
	ListaPedidos* listaP = nuevoArchivo->leerPedido();

    c1.MenuPrincipal(listaC,nuevoArchivo, listaR, listaP);
	
    return 0;
}

