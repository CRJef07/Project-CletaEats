#include "Control.h"

void Control::MenuPrincipal(ListaCliente* nuevaListaCliente,Archivo* txt, ListaRepartidor* repa,ListaPedidos* nuevaListaPedidos) {
	setlocale(LC_ALL, "spanish");
	setlocale(LC_ALL, "es_ES");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);


	ListaRestaurante* nuevaListaRestaurante = new ListaRestaurante;
	//ListaPedidos* nuevaListaPedidos = new ListaPedidos;
	ListaCalificacion* nuevaListaCalificacion = new ListaCalificacion;
	crearRestaurantes(nuevaListaRestaurante);


	std::string opcion = " ";

	do {
		try {
			system("cls");
			std::cout << "\t\tBienvenido a CletaEats" << std::endl;
			std::cout << "Por favor digite una opcion" << std::endl;
			std::cout << "1 - Ingresar como cliente " << std::endl;
			std::cout << "2 - Ingresar como repartidor " << std::endl;
			std::cout << "3 - Ingresar como restaurante " << std::endl;
			std::cout << "4 - Ingresar como admin " << std::endl;
			std::cout << "5 - Sub-Menu reportes " << std::endl;
			std::cout << "6 - SALIR " << std::endl << std::endl;
			std::cout << "Opcion digitada:  ";
			std::getline(std::cin, opcion);
			
			if (opcion != "1" && opcion != "2" && opcion != "3" && opcion != "4" && opcion != "5" && opcion != "6") {
				throw opcion;
			}
			switch (std::stoi(opcion)) {

			case 1:
				system("cls");
				subMenuCliente(nuevaListaCliente, repa, nuevaListaRestaurante, nuevaListaPedidos, nuevaListaCalificacion);
				break;

			case 2:
				system("cls");
				subMenuRepartidor(repa, nuevaListaPedidos, nuevaListaCliente, nuevaListaCalificacion);
				system("pause");
				break;

			case 3:
				system("cls");
				subMenuRestaurante(nuevaListaRestaurante);
				system("pause");
				break;

			case 4:
				system("cls");
				subMenuAdmin(nuevaListaCliente, repa, nuevaListaRestaurante, nuevaListaPedidos, txt);
				//system("pause");
				break;

			case 5:
				SubMenuReportes(nuevaListaCliente,repa,nuevaListaRestaurante,nuevaListaPedidos,nuevaListaCalificacion);
				break;

			case 6:
				txt->escribirCliente(nuevaListaCliente);
				txt->escribirRepartidor(repa);
				txt->escribirPedido(nuevaListaPedidos);
				delete nuevaListaCliente;//ACÁ YA SE BORRAN TODOS LOS CLIENTES QUE HAYA EN LA LISTA
				delete repa;
				delete nuevaListaRestaurante;
				delete nuevaListaPedidos;
				exit(0);
			}
		}
		catch (std::string opcion) {}
	} while (opcion != "6");
}

/*CLIENTE*/
void Control::subMenuCliente(ListaCliente* nuevaListaCliente, ListaRepartidor* nuevaListaRepartidor, ListaRestaurante* nuevaListaRestaurante, ListaPedidos* nuevaListaPedidos, ListaCalificacion* nuevaListaCalificacion) {
	std::string opc = " ";
	std::string toStringPedido = "";
	std::string cedulaUsuario = iniciarSesion(nuevaListaCliente);

	if (cedulaUsuario == "false") {
		return;
	}

	do {

		system("cls");
		std::cout << "\tBienvenido al subMen� del cliente" << std::endl;
		std::cout << "Digite alguna de las siguientes opciones " << std::endl;
		std::cout << "1 - Realizar pedido" << std::endl;
		std::cout << "2 - Ver estado del pedido" << std::endl;
		std::cout << "3 - calificar repartidor" << std::endl;
		std::cout << "4 - Salir" << std::endl;
		std::cout << "Opci�n digitada: ";
		std::getline(std::cin, opc);

		try {
			if (opc != "1" && opc != "2" && opc != "3") {
				throw opc;
			}
			switch (std::stoi(opc)) {
			case 1:
				system("cls");
				realizarPedido(nuevaListaCliente, nuevaListaRepartidor, nuevaListaRestaurante, nuevaListaPedidos, cedulaUsuario);
				break;

			case 2:

				system("cls");
				toStringPedido = mostrarPedido(nuevaListaCliente, nuevaListaPedidos, cedulaUsuario);
				if (toStringPedido == "") {
					std::cout << "\t\tEl usuario no ha realizado ning�n pedido" << std::endl;
				}
				else {
					std::cout << toStringPedido << std::endl;
				}
				system("pause");
				break;

			case 3:
				system("cls");
				calificarRepartidor(nuevaListaRepartidor);
				aumentarAmonestaciones(nuevaListaRepartidor, nuevaListaCalificacion);
				break;
			}
		}
		catch (std::string opc) {}

	} while (opc != "4");
	
}
void Control::agregarCliente(ListaCliente* nuevaLista, std::string cedulaCliente) {
	Cliente* nuevoCliente = new Cliente;

	std::string nombreCliente = "";
	std::string correoCliente = "";
	std::string direccionCliente = "";
	std::string tarjeta = "";
	std::string telefono = "";
	int tarjetaCliente = 0;
	int telefonoCliente = 0;

	nuevoCliente->setCedula(cedulaCliente);

	std::cout << "Nombre del cliente:  ";
	std::getline(std::cin, nombreCliente);
	nuevoCliente->setNombre(nombreCliente);

	std::cout << "Correo del cliente:  ";
	std::getline(std::cin, correoCliente);
	nuevoCliente->setCorreo(correoCliente);

	std::cout << "Direcci�n exacto del cliente:  ";
	std::getline(std::cin, direccionCliente);
	nuevoCliente->setDireccion(direccionCliente);

	std::cout << "N�mero de tarjeta del cliente:  ";//VERIFICAR QUE NO SE CAIGA
	//std::getline(std::cin,tarjeta);//std::cin >> tarjetaCliente;
	tarjetaCliente = retornarNumero();
	nuevoCliente->setTarjeta(tarjetaCliente);

	std::cout << "Tel�fono del cliente:  ";//VERIFICAR QUE NO SE CAIGA
	//std::getline(std::cin,telefono); //std::cin >> telefonoCliente;
	telefonoCliente = retornarNumero();

	nuevoCliente->setTelefono(telefonoCliente);

	nuevoCliente->setEstado(true);

	nuevaLista->agregar(nuevoCliente);
}
void Control::eliminarCliente(ListaCliente* nuevaLista, std::string ID) {

	if (nuevaLista->eliminar(ID)) {
		std::cout << std::endl << "\tEl cliente fue eliminado de la lista exitosamente" << std::endl;
	}
	else {
		std::cout << std::endl << "\tEl cliente no fue eliminado de la lista" << std::endl;
	}

}
void Control::verListaCliente(ListaCliente* nuevaLista) {
	std::cout << nuevaLista->mostrar() << std::endl;
}
/*CLIENTE*/


//REPARTIDOR
//------------------------------------------------------------------------------------------
void Control::subMenuRepartidor(ListaRepartidor* nuevaListaR, ListaPedidos* nuevaListaPedidos, ListaCliente* lc, ListaCalificacion* nuevaListaCalificacion)
{
	std::string ced;
	Pedido pRepartidor;
	//Archivo txtRepartidor;
	std::string opc = " ";
	//std::string cedulaRepartidor = " ";
	std::string cedulaUsuario = iniciarSesionRepa(nuevaListaR, nuevaListaPedidos);

	if (cedulaUsuario == "false") {
		return;
	}
	system("cls");
	std::cout << "\tBienvenido al subMen� del repartidor" << std::endl;
	std::cout << "Digite alguna de las siguientes opciones " << std::endl;
	std::cout << "1 - Realizar entrega de pedido" << std::endl;
	std::cout << "2 - Recoger pedido" << std::endl;
	std::cout << "3 - Salir" << std::endl;
	std::cout << "Opci�n digitada: ";
	std::getline(std::cin, opc);

	try {
		if (opc != "1" && opc != "2") {
			throw opc;
		}
		switch (std::stoi(opc)) {
		case 1:
			system("cls");
			std::cout << "Digite el nombre del pedido que desea entregar" << std::endl;
			std::getline(std::cin, ced);
			cambiarEstadoPedido(nuevaListaPedidos, nuevaListaR, lc, ced);

			break;

		case 2:

			system("cls");
			std::cout << "Digite el nombre del pedido que desea recoger" << std::endl;
			std::getline(std::cin, ced);
			cambiarEstadoPedidoRest(nuevaListaPedidos, nuevaListaR, lc, ced);
			break;
		}
	}
	catch (std::string opc) {}
}
void Control::agregarRepartidor(ListaRepartidor* lr, std::string cedulaRepartidor)
{
	Repartidor* nuevoRepa = new Repartidor;
	//Variables
	std::string nombre, correo, direccion, tarjeta, telefono;



	std::cout << "\nDigite su nombre: ";
	std::getline(std::cin, nombre);

	std::cout << "\nDigite el correo: ";
	std::getline(std::cin, correo);

	std::cout << "\nDigite la direcci�n: ";
	std::getline(std::cin, direccion);

	std::cout << "\nDigite su n�mero de tarjeta: ";
	std::getline(std::cin, tarjeta);

	std::cout << "\nDigite su n�mero de tel�fono: ";
	std::getline(std::cin, telefono);

	int telefono2 = lr->convertirInt(telefono);
	int tarjeta2 = lr->convertirInt(tarjeta);

	nuevoRepa->setNombre(nombre);
	nuevoRepa->setCedula(cedulaRepartidor);
	nuevoRepa->setCorreo(correo);
	nuevoRepa->setDireccion(direccion);
	nuevoRepa->setTarjeta(tarjeta2);
	nuevoRepa->setTelefono(telefono2);
	nuevoRepa->setEstado(true);

	lr->agregar(nuevoRepa);


}
void Control::eliminarRepartidor(ListaRepartidor* lr, std::string id) {

	if (lr->eliminar(id)) {
		std::cout << std::endl << "\tEl repatidor fue eliminado de la lista exitosamente" << std::endl;
	}
	else {
		std::cout << std::endl << "\tEl repartidor no fue eliminado de la lista" << std::endl;
	}
}
void Control::verListaReparidor(ListaRepartidor* lr)
{
	std::cout << lr->mostrar();
}

void Control::verListaRepartidor(ListaRepartidor* lr,ListaPedidos * lp){
	Nodo* auxRepa = lr->getCabeza();
	Nodo* auxPedi = lp->getCabeza();

	while (auxRepa != nullptr) {

		while (auxPedi != nullptr) {

			if (auxRepa->getDatoRepa()->getNombre() == auxPedi->getDatoPedido()->getNombreRepartidor()) {

				std::cout << "El repartidor "<< auxRepa->getDatoRepa()->getNombre()  << " fue asignado al pedido número " << auxPedi->getDatoPedido()->getIDPedido() << std::endl;
			}
			auxPedi = auxPedi->getSig();
		}
		auxRepa = auxRepa->getSig();
	}
}

void Control::aumentarPedidosRepa(ListaRepartidor* repa, std::string id)
{
	Nodo* temp = repa->getCabeza();

	while (temp != nullptr) {
		if (temp->getDatoRepa()->getCedula() == id) {
			int cant = (temp->getDatoRepa()->getPedidos() + 1);
			temp->getDatoRepa()->setPedidos(cant);
		}
		temp = temp->getSig();
	}
}



//------------------------------------------------------------------------------------------

//RESTAURANTE
//------------------------------------------------------------------------------------------
void Control::subMenuRestaurante(ListaRestaurante* lr) {
	std::string opc = " ";
	std::string IDRest = " ";

	std::cout << "\tBienvenido al subMen� del restaurante" << std::endl;
	std::cout << "Digite alguna de las siguientes opciones " << std::endl;
	std::cout << "1 - Agregar un restaurante" << std::endl;
	std::cout << "2 - Eliminar un restaurante" << std::endl;
	std::cout << "3 - Ver la lista de restaurante" << std::endl;
	std::cout << "4 - Para cargar la lista de restaurante" << std::endl;
	std::cout << "5 - Para guardar la lista de restaurante" << std::endl;
	std::cout << "Opci�n digitada: ";
	std::getline(std::cin, opc);

	try {
		if (opc != "1" && opc != "2" && opc != "3" && opc != "4" && opc != "5") {
			throw opc;
		}
		switch (std::stoi(opc)) {
		case 1:
			system("cls");
			std::cout << "Agregando restaurante nuevo" << std::endl;
			agregarRestaurante(lr);
			system("pause");
			break;
		case 2:
			system("cls");
			std::cout << "Eliminando restaurante" << std::endl;
			std::cout << "Digite el ID del restaurante que desea eliminar" << std::endl;
			std::getline(std::cin, IDRest);
			eliminarRestaurante(lr, IDRest);
			system("pause");
			break;
		case 3:
			system("cls");
			verListaRestaurante(lr);
			system("pause");
			break;

		}

	}
	catch (std::string opc) {}
}
void Control::agregarRestaurante(ListaRestaurante* lr)
{
	Restaurante* nuevoRest = new Restaurante;
	//Variables
	std::string nombre, cedula, tipo, direccion;


	std::cin.ignore();
	std::cout << "\nDigite su nombre: ";
	std::getline(std::cin, nombre);
	std::cout << "\nDigite la c�dula juridica del restaurante: ";
	std::getline(std::cin, cedula);
	std::cout << "\nDigite la direcc�n del restaurante: ";
	std::getline(std::cin, direccion);
	std::cout << "\nDigite el tipo de comida que ofrece su establecimiento: ";
	std::getline(std::cin, tipo);
	std::cout << "\nDatos de los combos del restaurante: ";

	nuevoRest->setNombre("ema2");
	nuevoRest->setCedulaJuridica("12341265");
	nuevoRest->setDireccion("Virilla24");
	nuevoRest->setTipoDeComida("si");
	nuevoRest->setResenna(0);

	lr->agregar(nuevoRest);
}
void Control::eliminarRestaurante(ListaRestaurante* lr, std::string id)
{
	if (lr->eliminar(id)) {
		std::cout << std::endl << "\tEl repartidor fue eliminado de la lista exitosamente" << std::endl;
	}
	else {
		std::cout << std::endl << "\tEl repartidor no fue eliminado de la lista" << std::endl;
	}
}
void Control::verListaRestaurante(ListaRestaurante* lr)
{
	lr->mostrar();
}

void Control::crearRestaurantes(ListaRestaurante* nuevaListaRestaurante) {
	Restaurante* res1 = new Restaurante;
	Restaurante* res2 = new Restaurante;
	Restaurante* res3 = new Restaurante;
	Restaurante* res4 = new Restaurante;
	Restaurante* res5 = new Restaurante;
	Restaurante* res6 = new Restaurante;
	Restaurante* res7 = new Restaurante;

	res1->setNombre("McDonald's");
	res1->setCedulaJuridica("3-101-14194");
	res1->setDireccion("Alajuela, Oeste Contiguo a Pali");
	res1->setTipoDeComida("Comida r�pida");
	res1->enviarACombo("CheeseBurger", "Papas peque�as", "CocaCola light 350ml", 4000, 0);
	res1->enviarACombo("CheeseBurger", "Papas grandes", "CocaCola 350ml", 5000, 1);
	res1->enviarACombo("Hamburguesa doble", "10 McNuggets", "Pepsi 350ml", 6000, 2);
	res1->enviarACombo("4 piezas de Pollo", "McNuggets", "CocaCola light", 7000, 3);
	res1->enviarACombo("8 piezas de Pollo", "2 Papas medianas", "Pepsi 1.5L", 8000, 4);
	res1->enviarACombo("5 McPollo", "5 Papas peque�as", "CocaCola 2.5L", 9000, 5);
	res1->enviarACombo("4 BigMac", "4 Papas medianas", "Pepsi 2.5L", 10000, 6);
	res1->enviarACombo("4 BigMac", "4 piezas de Pollo", "Pepsi 2L", 11000, 7);
	res1->enviarACombo("10 BigMac", "10 Papas grandes y 20 McNuggets", "CocaCoca 250ml", 12000, 8);

	res2->setNombre("Pizza Hut");
	res2->setCedulaJuridica("3-101-16470");
	res2->setDireccion("Alajuela, digonal al cementerio Central");
	res2->setTipoDeComida("Pizzer�a");
	res2->enviarACombo("Pizza personal", "1 orden de Breadsticks", "CocaCola 350ml", 4000, 0);
	res2->enviarACombo("Pizza personal", "1 orden de Cheese Poppers", "CocaCola 350ml", 5000, 1);
	res2->enviarACombo("2 Pizza personales", "2 �rdenes de Breadsticks", "CocaCola 650ml", 6000, 2);
	res2->enviarACombo("2 Pizza personales", "2 �rdenes de Cheese Poppers", "CocaCola 650ml", 7000, 3);
	res2->enviarACombo("Pizza Mediana", "1 orden de Pan de ajo", "CocaCola 1.5L", 8000, 4);
	res2->enviarACombo("Pizza Mediana", "1 orden de Pepperoni Sticks", "CocaCola 1.5L", 9000, 5);
	res2->enviarACombo("Pizza grande", "1 orden de Pepperoni Sticks", "CocaCola 1.5L", 10000, 6);
	res2->enviarACombo("Pizza grande con bordes de queso", "1 orden de Pan de ajo", "CocaCola 2.5L", 11000, 7);
	res2->enviarACombo("2 Pizzas grandes", "1 orden de Pan de ajo", "Pepsi 2.5L", 12000, 8);

	res3->setNombre("La Princesa Marina");
	res3->setCedulaJuridica("3-101-106958");
	res3->setDireccion("Alajuela, Costado norte de la Iglesia de Barrio San Jose");
	res3->setTipoDeComida("Marisquer�a");
	res3->enviarACombo("Patacones", "Frijoles y Guacamole", "Fresco natural de Cas", 4000, 0);
	res3->enviarACombo("Arroz blanco", "Frijoles", "Fresco natural de Frutas", 5000, 1);
	res3->enviarACombo("Arroz con camar�n", "Ensalada rusa", "Fresco natural de Cas", 6000, 2);
	res3->enviarACombo("Arroz y Frijoles", "Pescado empanizado", "Fresco natural de Zanahoria", 7000, 3);
	res3->enviarACombo("Spaguetti con camarones", "Ensalada verde", "Fresco natural de Guanabana", 8000, 4);
	res3->enviarACombo("Pescado relleno", "Arroz y frijoles", "Fresco natural de Piña", 9000, 5);
	res3->enviarACombo("Pescado entero", "Ensalada verde, arroz y frijoles", "Fresco natural de Cas", 10000, 6);
	res3->enviarACombo("Salm�n al ajillo", "Ensalada verde, arroz y frijoles", "Fresco natural de Frutas", 11000, 7);
	res3->enviarACombo("Rib Eye", "Ensalada verde, arroz y frijoles", "Fresco natural de frutas", 12000, 8);

	res4->setNombre("KFC");
	res4->setCedulaJuridica("3-101-12984");
	res4->setDireccion("Alajuela, calle 2 avenida 10");
	res4->setTipoDeComida("Comida r�pida");
	res4->enviarACombo("popcorn", "1 orden de papas", "vaso peque�o de coca-cola", 4000, 0);
	res4->enviarACombo("2 piezas de pollo", "1 orden de papas", "vaso mediano de coca-cola", 5000, 1);
	res4->enviarACombo("3 piezas de pollo", "1 orden de papas", "vaso mediano de coca-cola", 6000, 2);
	res4->enviarACombo("4 crispy strips", "1 orden de papas", "vaso mediano de coca-cola", 7000, 3);
	res4->enviarACombo("5 piezas de pollo", "1 orden de papas", "vaso mediano de coca-cola", 8000, 4);
	res4->enviarACombo("6 piezas de pollo", "1 orden de papas", "vaso mediano de coca-cola", 9000, 5);
	res4->enviarACombo("combo twisters", "1 orden de papas", "vaso mediano de coca-cola", 10000, 6);
	res4->enviarACombo("7 piezas de pollo", "3 �rdenes de papas", "1.5 lt de coca-cola", 11000, 7);
	res4->enviarACombo("14 piezas de pollo", "4 �rdenes de papas", "2 lt de coca-cola", 12000, 8);

	res5->setNombre("Burger King");
	res5->setCedulaJuridica("3-101-706562");
	res5->setDireccion("Alajuela, Radial Francisco J. Orlich");
	res5->setTipoDeComida("Comida r�pida");
	res5->enviarACombo("BK Pinto", "Tostadas", "Caf�", 4000, 0);
	res5->enviarACombo("BK Pinto deluxe", "Salchich�n", "Caf�", 5000, 1);
	res5->enviarACombo("Chicken Crispy", "Papas peque�as", "Pepsi 250ml", 6000, 2);
	res5->enviarACombo("Chicken Crispy", "Papas grandes", "Pepsi 350ml", 7000, 3);
	res5->enviarACombo("Whopper cl�sico", "Papas peque�as", "Pepsi 250ml", 8000, 4);
	res5->enviarACombo("Whopper deluxe", "Papas grandes", "Pepsi 350ml", 9000, 5);
	res5->enviarACombo("Whopper tejano", "Papas peque�as", "Pepsi 350ml", 10000, 6);
	res5->enviarACombo("2 Whopper deluxe", "Papas grandes", "2 Pepsi 250ml", 11000, 7);
	res5->enviarACombo("4 Whopper tejano", "Papas peque�as", "Pepsi 2.5L", 12000, 8);

	res6->setNombre("Las Canitas");
	res6->setCedulaJuridica("3-101-25181");
	res6->setDireccion("Alajuela, el Coyol");
	res6->setTipoDeComida("Bar y restaurante");
	res6->enviarACombo("Orden de Dados de queso", "Salsa de queso", "CocaCola 250ml", 4000, 0);
	res6->enviarACombo("Orden de Palos de queso", "Salsa de queso", "CocaCola 250ml", 5000, 1);
	res6->enviarACombo("Orden de tacos de pollo", "Frijoles molidos", "Pilsen", 6000, 2);
	res6->enviarACombo("Orden de tacos de pescado", "Frijoles molidos", "Pilsen", 7000, 3);
	res6->enviarACombo("Hamburguesa casera", "Papas peque�as", "Imperial", 8000, 4);
	res6->enviarACombo("Chalupas", "Salsa de queso", "Imperial", 9000, 5);
	res6->enviarACombo("Nachos grandes", "Salsa de queso y pico de gallo", "Imperial", 10000, 6);
	res6->enviarACombo("Vigor�n", "Ensalada verde", "Corona", 11000, 7);
	res6->enviarACombo("Chifrijo", "Tortilla con salsa de queso", "Corona", 12000, 8);

	res7->setNombre("POPS");
	res7->setCedulaJuridica("3-101-481987");
	res7->setDireccion("Alajuela Plaza del Este");
	res7->setTipoDeComida("Helader�a");
	res7->enviarACombo("Churchill grande", "Topping a escoger", "Sin bebida", 4000, 0);
	res7->enviarACombo("Sundae", "Topping a escoger", "Sin bebida", 5000, 1);
	res7->enviarACombo("Canasta Sundae", "Topping a escoger", "Sin bebida", 6000, 2);
	res7->enviarACombo("Banana Splip peque�a", "Topping a escoger", "Sin bebida", 7000, 3);
	res7->enviarACombo("Banana Hawaiana peque�a", "Topping a escoger", "Fresco natural a elegir", 8000, 4);
	res7->enviarACombo("Banana Splip", "Topping a escoger", "Sin bebida", 9000, 5);
	res7->enviarACombo("Banana Hawaiana grande", "Topping a escoger", "Fresco natural a elegir", 10000, 6);
	res7->enviarACombo("Helado tama�o familiar", "5 conos", "Fresco natural a elegir", 11000, 7);
	res7->enviarACombo("Helado tama�o familiar", "10 conos", "Fresco natural a elegir", 12000, 8);

	nuevaListaRestaurante->agregar(res1);
	nuevaListaRestaurante->agregar(res2);
	nuevaListaRestaurante->agregar(res3);
	nuevaListaRestaurante->agregar(res4);
	nuevaListaRestaurante->agregar(res5);
	nuevaListaRestaurante->agregar(res6);
	nuevaListaRestaurante->agregar(res7);
}

void Control::aumentarPedidosRest(ListaRestaurante* rest, std::string id)
{
	Nodo* temp = rest->getCabeza();

	while (temp != nullptr) {
		if (temp->getDatoRest()->getCedulaJuridica() == id) {
			int cant = (temp->getDatoRest()->getPedidos() + 1);
			temp->getDatoRest()->setPedidos(cant);
		}
		temp = temp->getSig();
	}
}



std::string Control::iniciarSesion(ListaCliente* nuevaListaCliente) {
	setlocale(LC_ALL, "spanish");
	setlocale(LC_ALL, "es_ES");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	std::string cedulaCliente = "";

	std::cout << "\tBienvenido al subMen� del cliente" << std::endl;
	std::cout << "Para iniciar digite su c�dula" << std::endl;
	std::cout << "C�dula:  ";
	std::getline(std::cin, cedulaCliente);

	if (validarIDCliente(nuevaListaCliente, cedulaCliente) == false) {//VALIDA SI NO EXISTE EL CLIENTE PARA AGREGARLO
		system("cls");
		std::cout << "\tNo se encuentra inscrito en la aplicaci�n" << std::endl;
		std::cout << "\t\tDebe crear un usuario" << std::endl << std::endl;

		agregarCliente(nuevaListaCliente, cedulaCliente);

		system("cls");
		std::cout << "\t\tIniciando sesi�n " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << std::endl;
		//system("pause");
		//std::cin.ignore();
	}
	else {//SI EXISTE EL USUARIO
		if (validarEstadoCliente(nuevaListaCliente, cedulaCliente) == false) {//SE ENCUENTRA SUSPENDIDO
			system("cls");
			std::cout << "\t\tERROR" << std::endl;
			std::cout << "Usted se encuentra suspendido por la aplicaci�n" << std::endl;
			system("pause");
			return "false";
		}
		system("cls");
		std::cout << "\t\tIniciando sesion " << std::endl;//NO SE ENCUENTRA SUSPENDIDO
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		//std::cout << std::endl;
		//system("pause");
	}
	//std::cin.ignore();
	std::cout << std::endl;
	system("pause");
	return cedulaCliente;
}

std::string Control::iniciarSesionRepa(ListaRepartidor* lr, ListaPedidos* lp)
{
	setlocale(LC_ALL, "spanish");
	setlocale(LC_ALL, "es_ES");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	std::string cedula = "";

	std::cout << "\tBienvenido al subMen� del repartidor" << std::endl;
	std::cout << "Para iniciar digite su c�dula" << std::endl;
	std::cout << "C�dula:  ";

	std::getline(std::cin, cedula);
	if (validarIDRepartidor(lr, cedula) == false) {
		system("cls");
		std::cout << "\tNo se encuentra inscrito en la aplicaci�n" << std::endl;
		std::cout << "\t\tDebe crear un usuario" << std::endl << std::endl;

		agregarRepartidor(lr, cedula);

		std::cout << "Iniciando sesi�n " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << std::endl;
		//system("pause");
		//std::cin.ignore();
	}
	else {//SI EXISTE EL USUARIO
		if (validarEstadoRepartidor(lr, cedula) == false && validarAmonestaciones(lr, cedula) == false) {//SE ENCUENTRA SUSPENDIDO
			system("cls");
			std::cout << "\t\tERROR" << std::endl;
			std::cout << "Usted se encuentra suspendido por la aplicaci�n" << std::endl;
			return "false";
		}
		std::cout << "Iniciando sesion " << std::endl;//NO SE ENCUENTRA SUSPENDIDO
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		//std::cout << std::endl;
		//system("pause");
	}
	//std::cin.ignore();
	std::cout << std::endl;
	system("pause");
	return cedula;
}

void Control::subMenuAdmin(ListaCliente* nuevaLC, ListaRepartidor* nuevaLRep, ListaRestaurante* nuevaLRes, ListaPedidos* nuevaListaPedidos, Archivo* txtCliente) {
	Archivo txtRepartidor2;
	std::string opcion = "";

	do {
		system("cls");
		std::string IDCLiente, IDRepartidor, IDRestaurante;
		std::cout << "\t\tBienvenido al subMen� del administrador" << std::endl;
		std::cout << "Digite alguna de las siguientes opciones" << std::endl << std::endl;
		std::cout << "1 - Ver la lista de clientes" << std::endl;
		std::cout << "2 - Eliminar un cliente" << std::endl << std::endl;

		std::cout << "3 - Ver la lista de repartidores" << std::endl;
		std::cout << "4 - Eliminar un repartidor" << std::endl;
		std::cout << "5 - Cargar la lista de repartidores" << std::endl;
		std::cout << "6 - Guardar la lista de restaurantes" << std::endl << std::endl;

		std::cout << "7 - Ver la lista de restaurantes" << std::endl;
		std::cout << "8 - Eliminar un restaurante" << std::endl << std::endl;

		std::cout << "9 - Ver todos los pedidos" << std::endl << std::endl;

		std::cout << "10 - SALIR" << std::endl << std::endl;
		std::cout << "Opcion digitada: ";

		std::getline(std::cin, opcion);

		try {
			if (opcion != "1" && opcion != "2" && opcion != "3" && opcion != "4" && opcion != "5" && opcion != "6" && opcion != "7" && opcion != "8" && opcion != "9") {
				throw opcion;
			}
			switch (std::stoi(opcion)) {
			case 1:
				system("cls");
				verListaCliente(nuevaLC);
				system("pause");
				break;

			case 2:
				system("cls");
				std::cout << "Digite el ID del cliente que desea eliminar" << std::endl;
				std::getline(std::cin, IDCLiente);
				eliminarCliente(nuevaLC, IDCLiente);
				system("pause");
				break;

			case 3:
				system("cls");
				verListaReparidor(nuevaLRep);
				//verListaRepartidor(nuevaLRep, nuevaListaPedidos);
				system("pause");
				break;

			case 4:
				system("cls");
				std::cout << "Digite el ID del repartidor que desea eliminar" << std::endl;
				std::getline(std::cin, IDRepartidor);
				eliminarRepartidor(nuevaLRep, IDRepartidor);
				system("pause");
				break;

			case 5:
				system("cls");
				txtRepartidor2.leerRepartidor();
				system("pause");
				break;

			case 6:
				system("cls");
				txtRepartidor2.escribirRepartidor(nuevaLRep);
				system("pause");
				break;

			case 7:
				system("cls");
				verListaRestaurante(nuevaLRes);
				system("pause");
				break;

			case 8:
				system("cls");
				std::cout << "Digite el ID del restaurante que desea eliminar" << std::endl;
				std::getline(std::cin, IDRestaurante);
				eliminarRestaurante(nuevaLRes, IDRestaurante);
				system("pause");
				break;

			case 9:
				system("cls");
				std::cout << nuevaListaPedidos->mostrarLista() << std::endl;
				system("pause");
				break;
			}
		}
		catch (std::string opcion) {}
	} while (opcion != "10");
}

void Control::SubMenuReportes(ListaCliente* nuevaListaCliente, ListaRepartidor* nuevaListaRepartidor, ListaRestaurante* nuevaListaReataurante, ListaPedidos* nuevaListaPedido, ListaCalificacion* nuevaListaCalificacion){
	std::string cedulaUsuario;
	std::string cedulaUsuarioRepa;

	std::string opc = "";

	do {
		system("cls");
		std::cout << "\t\tBienvenido a CletaEats" << std::endl;
		std::cout << "Por favor digite una opci�n" << std::endl;
		std::cout << " 1 - Ingresar como cliente " << std::endl;
		std::cout << " 2 - Ingresar como restaurante " << std::endl;
		std::cout << " 3 - Ingresar como repartidor " << std::endl;
		std::cout << " 4 - **Realizar un pedido " << std::endl;
		std::cout << " 5 - Listado de clientes activos" << std::endl;
		std::cout << " 6 - Listado de clientes suspendidos " << std::endl;
		std::cout << " 7 - Listado de repartidores " << std::endl;
		std::cout << " 8 - Listado de restaurantes " << std::endl;
		std::cout << " 9 - Restaurante con mayor numero de pedidos " << std::endl;
		std::cout << "10 - Monto total vendido por restaurante " << std::endl;
		std::cout << "11 - Monto total vendido por los restaurantes " << std::endl;
		std::cout << "12 - Restaurante con menor numero de pedidos " << std::endl;
		std::cout << "13 - Listado de pedidos por repartidor " << std::endl;
		std::cout << "14 - Listado de pedidos por cliente" << std::endl;
		std::cout << "15 - Cliente con mayor numero de pedidos " << std::endl;
		std::cout << "16 - Hora concurrida " << std::endl;
		std::cout << "17 - SALIR " << std::endl;
		std::cout << "Opci�n digitada:  ";
		std::getline(std::cin, opc);

		try {

			if (opc != "1" && opc != "2" && opc != "3" && opc != "4" && opc != "5" && opc != "6" && opc != "7" && opc != "8" && opc != "9" && opc != "10" && opc != "11" && opc != "12" && opc != "13" && opc != "14" && opc != "15" && opc != "16") {
				throw opc;
			}
			switch (std::stoi(opc)) {
			case 1:
				system("cls");
				cedulaUsuario = iniciarSesion(nuevaListaCliente);
				agregarCliente(nuevaListaCliente, cedulaUsuario);
				system("pause");
				break;
			case 2:
				system("cls");
				agregarRestaurante(nuevaListaReataurante);
				system("pause");
				break;
			case 3:
				system("cls");
				cedulaUsuarioRepa = iniciarSesionRepa(nuevaListaRepartidor, nuevaListaPedido);
				agregarRepartidor(nuevaListaRepartidor, cedulaUsuarioRepa);
				system("pause");
				break;
			case 4:
				system("cls");

				system("pause");
				break;
			case 5:
				system("cls");
				mostarClientesActivos(nuevaListaCliente);
				system("pause");
				break;
			case 6:
				system("cls");
				mostarClientesSuspendidos(nuevaListaCliente);
				system("pause");
				break;
			case 7:
				system("cls");
				//verListaReparidor(nuevaListaRepartidor);
				system("pause");
				break;
			case 8:
				system("cls");
				verListaRestaurante(nuevaListaReataurante);
				system("pause");
				break;
			case 9:
				system("cls");
				ventasMayores(nuevaListaReataurante, nuevaListaPedido);
				system("pause");
				break;
			case 10:
				system("cls");

				system("pause");
				break;
			case 11:
				system("cls");

				system("pause");
				break;
			case 12:
				system("cls");

				system("pause");
				break;
			case 13:
				system("cls");

				system("pause");
				break;
			case 14:
				system("cls");

				system("pause");
				break;
			case 15:
				system("cls");

				system("pause");
				break;
			case 16:
				system("cls");

				system("pause");
				break;
			}
		}
		catch (std::string opc) {}
	} while (opc != "17");
}

std::string  Control::asignarRepartidor(ListaRepartidor* lrepa, ListaPedidos* lp) {
	Nodo* actual = lrepa->getCabeza();
	std::string nombre = "";

	while (actual != nullptr) {//verifica si hay al menos un repartidor

		while (actual->getDatoRepa()->getEstado() == true && actual->getDatoRepa()->getAmonestaciones() < 4) {//VERIFICA EL ESTADO Y LAS AMONESTACIONES

			nombre = actual->getDatoRepa()->getNombre();
			actual->getDatoRepa()->setEstado(false);
			return nombre;

		}
		actual = actual->getSig();
	}
	return "false";
}

bool Control::validarIDCliente(ListaCliente* liCli, std::string id) {//VALIDA QUE EXISTA EL CLIENTE EN LA LISTA, SINO PARA AGREGARLO

	Nodo* aux = liCli->getCabeza();

	while (aux != nullptr) {

		if (aux->getDatoC()->getCedula() == id) {
			return true;//ENCUENTRA LA CÉDULA
		}
		aux = aux->getSig();
	}

	return false;//NO ENCUENTRA LA CÉDULA
}

void Control::diasHabiles(ListaRepartidor* repa, std::string id) {
	Nodo* aux = repa->getCabeza();
	while (aux != nullptr) {
		if (aux->getDatoRepa()->getNombre() == id) {
			aux->getDatoRepa()->setDisponibilidad(true);
		}
		aux = aux->getSig();
	}
}
void Control::diasFeriados(ListaRepartidor* repa, std::string id) {
	Nodo* aux = repa->getCabeza();
	while (aux != nullptr) {
		if (aux->getDatoRepa()->getNombre() == id) {
			aux->getDatoRepa()->setDisponibilidad(false);
		}
		aux = aux->getSig();
	}
}
void Control::extraPorDiasFeriados(ListaRepartidor* repa, ListaPedidos* lp, std::string id) {
	Nodo* auxR = repa->getCabeza();
	Nodo* auxP = lp->getCabeza();
	while (auxR != nullptr) {
		while (auxP != nullptr) {
			if (auxP->getDatoPedido()->getNombreRepartidor() == id && auxR->getDatoRepa()->getDisponibilidad() == true) {

				float num = auxP->getDatoPedido()->getPrecioPedido() + 1000;
				auxP->getDatoPedido()->setPrecioPedido(num);
			}
			else if (auxP->getDatoPedido()->getNombreRepartidor() == id && auxR->getDatoRepa()->getDisponibilidad() == false) {

				float num = auxP->getDatoPedido()->getPrecioPedido() + 1500;
				auxP->getDatoPedido()->setPrecioPedido(num);
			}
			auxP = auxP->getSig();
		}
		auxR = auxR->getSig();
	}
}

void Control::aumentarAmonestaciones(ListaRepartidor* repa, ListaCalificacion* lCalif) {
	Nodo* auxR = repa->getCabeza();
	NodoCalif* auxCA = lCalif->getCabeza();
	while (auxR != nullptr) {
		while (auxCA != nullptr) {
			if (auxCA->getDatoCalif()->getQuejas() != "") {
				int num = auxR->getDatoRepa()->getAmonestaciones() + 1;
				auxR->getDatoRepa()->setAmonestaciones(num);
			}
			auxCA = auxCA->getSig();
		}
		auxR = auxR->getSig();
	}
}

void Control::cambiarEstadoPedido(ListaPedidos* lp, ListaRepartidor* repa, ListaCliente* lc, std::string id) {
	using namespace std::literals::chrono_literals;

	Nodo* auxRepa = repa->getCabeza();
	Nodo* auxPedido = lp->getCabeza();
	Nodo* auxCliente = lc->getCabeza();

	time_t now = time(0);//SETTEAR HORA
	tm* time = localtime(&now);//SETTEAR HORA
	int hora = time->tm_hour;//SETTEAR HORA
	
	
	while (auxPedido != nullptr) {

		while (auxCliente != nullptr) {

			while (auxRepa != nullptr) {

				if (auxPedido->getDatoPedido()->getNombreCliente() == id && auxRepa->getDatoRepa()->getNombre() == auxPedido->getDatoPedido()->getNombreRepartidor()) {
					std::thread contando(Control, void* cargando);

					auxRepa->getDatoRepa()->setKmRecorridos(randearDistancia());
					auxRepa->getDatoRepa()->setEstado(true);

					auxPedido->getDatoPedido()->setHoraEntregado(hora);
					
					auxPedido->getDatoPedido()->setEstadoPedido("Entregado");
				}
				auxRepa = auxRepa->getSig();
			}
			auxCliente = auxCliente->getSig();
		}
		auxPedido = auxPedido->getSig();
	}
}

float Control::randearDistancia() {
	using namespace std::literals::chrono_literals;

	int i;
	srand(time(NULL));

	i = rand() % 10;


	if (i == 1) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);
	}
	if (i == 2) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);

	}
	if (i == 3) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);

	}if (i == 4) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);
	}
	if (i == 5) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);
	}
	if (i == 6) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);
	}
	if (i == 7) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);
	}
	if (i == 8) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);
	}
	if (i == 9) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);
	}
	if (i == 10) {
		std::cout << "Llegando al destino " << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << ".";
			Sleep(150);
		}
		std::cout << "\n";
		std::this_thread::sleep_for(1s);
	}

	return i;

}

void Control::Cargando() {
	using namespace std::literals::chrono_literals;
	std::cout << "Preparando el pedido " << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << ".";
		Sleep(300);
	}
	std::cout << "\n";
	std::this_thread::sleep_for(1s);
}

void Control::cambiarEstadoPedidoRest(ListaPedidos* lp, ListaRepartidor* repa, ListaCliente* lc, std::string id) {


	Nodo* auxR = repa->getCabeza();
	Nodo* auxP = lp->getCabeza();
	Nodo* auxC = lc->getCabeza();


	while (auxP != nullptr) {

		while (auxC != nullptr) {

			while (auxR != nullptr) {

				if (auxP->getDatoPedido()->getNombreCliente() == id && auxR->getDatoRepa()->getNombre() == auxP->getDatoPedido()->getNombreRepartidor()) {
					std::thread contando(Control, void* Cargando);


					auxP->getDatoPedido()->setEstadoPedido("En camino");
				}
				auxR = auxR->getSig();
			}
			auxC = auxC->getSig();
		}
		auxP = auxP->getSig();
	}

}

void Control::calificarRepartidor(ListaRepartidor* lr)
{

	Nodo* aux = lr->getCabeza();
	std::string Amabilidad, tiempo, presentacion, quejas, var;


	//std::cin.ignore();
	std::cout << "\nDe 1 a 10 qué tan amable fue el repartidor?  ";
	std::getline(std::cin, Amabilidad);
	std::cout << "\nCuanto tiempo duro su entrega?  ";
	std::getline(std::cin, tiempo);
	std::cout << "\nQué tal la presentacion del pedido?  ";
	std::getline(std::cin, presentacion);
	std::cout << "\nTiene alguna queja del repartidor?\n  ";
	std::cout<<"1.SI\n" <<"2.NO\n";
	std::cout << "Opción: ";
	std::getline(std::cin, var);
	if (var == "1") {
		std::cout << "\nDigite sus quejas: ";
		std::getline(std::cin, quejas);

	}

	while (aux != nullptr) {
		Calificacion* nuevoCali = new Calificacion(Amabilidad, tiempo, presentacion, quejas);
		aux->getDatoRepa()->getLCalif()->agregar(nuevoCali);
	}

	return;

}


bool Control::validarEstadoCliente(ListaCliente* liCli, std::string id) {
	Nodo* aux = liCli->getCabeza();

	while (aux != nullptr) {

		if (aux->getDatoC()->getCedula() == id && aux->getDatoC()->getEstado() == true) {
			return true;
		}
		aux = aux->getSig();
	}

	return false;
}

void Control::aumentarPedidos(ListaCliente* liCli, std::string id) {
	Nodo* temp = liCli->getCabeza();

	while (temp != nullptr) {
		if (temp->getDatoC()->getCedula() == id) {
			int cant = (temp->getDatoC()->getPedidosRealizados() + 1);
			temp->getDatoC()->setPedidosRealizados(cant);
		}
		temp = temp->getSig();
	}
}

void Control::aumentarRepartidor(ListaRepartidor* liCli, std::string id) {
	Nodo* temp = liCli->getCabeza();

	while (temp != nullptr) {
		if (temp->getDatoRepa()->getCedula() == id) {
			int cant = (temp->getDatoRepa()->getPedidos() + 1);
			temp->getDatoRepa()->setPedidos(cant);
		}
		temp = temp->getSig();
	}
}

void Control::aumentarRestaurante(ListaRestaurante* liCli, std::string id) {
	Nodo* temp = liCli->getCabeza();

	while (temp != nullptr) {
		if (temp->getDatoRest()->getCedulaJuridica() == id) {
			int cant = (temp->getDatoRest()->getPedidos() + 1);
			temp->getDatoRest()->setPedidos(cant);
		}
		temp = temp->getSig();
	}
}

//HACER VARIOS PEDIDOS DE DIFERENTES COMBOS, PERO DEL MISMO RESTAURANTE
void Control::realizarPedido(ListaCliente* lcli, ListaRepartidor* lrepa, ListaRestaurante* lresta, ListaPedidos* nuevaListaPedidos, std::string cedulaCliente) {
	std::string opcResta = "";
	std::string opcCombo = "";
	std::string restaElegido = "";
	std::string nombreRepa = "";// asignarRepartidor(lrepa);
	std::string cedJud = "";
	std::string idPedido = "";

	do {
		int montoTotal = 0;
		//fflush(stdin);  // limpiera el buffer
		system("cls");
		std::cout << "\t\tREALIZANDO PEDIDO" << std::endl;
		std::cout << "Para realizar su pedido escoja un restaurante" << std::endl;
		std::cout << "1 - McDonald's" << std::endl;
		std::cout << "2 - Pizza Hut" << std::endl;
		std::cout << "3 - La Princesa Marina" << std::endl;
		std::cout << "4 - KFC" << std::endl;
		std::cout << "5 - Burger King" << std::endl;
		std::cout << "6 - Las Canitas" << std::endl;
		std::cout << "7 - POPS" << std::endl;
		std::cout << "8 - SALIR" << std::endl;
		std::cout << "Opci�n:  ";

		std::getline(std::cin, opcResta);
		system("cls");

		try {
			if (opcResta != "1" && opcResta != "2" && opcResta != "3" && opcResta != "4" && opcResta != "5" && opcResta != "6" && opcResta != "7") {
				throw opcResta;
			}
			switch (std::stoi(opcResta)) {
			case 1://RESTAURANTE #1
				system("cls");

				nombreRepa = asignarRepartidor(lrepa, nuevaListaPedidos);
				restaElegido = "McDonald's";

				if (nombreRepa == "false") {//true porque si se asign� un repartidor
					std::cout << "\tNO SE ASIGN� NING�N REPARTIDOR" << std::endl;
					std::cout << "No hay repartidores disponibles en este momento" << std::endl;
					std::cout << "Vuelva a intentar hacer el pedido m�s tarde" << std::endl;
					system("pause");
					return;
				}

				do {

					std::cout << lresta->buscarEspecifico(lresta, "McDonald's");

					std::cout << "Digite el combo que desea agregar al carrito:  " << std::endl;
					std::cout << "Si no desea agregar ning�n combo digite 0 " << std::endl;
					std::cout << "Opci�n:  ";
					std::getline(std::cin, opcCombo);

					try {
						if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
							throw opcCombo;
						}
						switch (std::stoi(opcCombo)) {
						case 1://COMBO #1
							system("cls");
							montoTotal = montoTotal + 4000;
							break;

						case 2://COMBO #2
							system("cls");
							montoTotal = montoTotal + 5000;
							break;

						case 3://COMBO #3
							system("cls");
							montoTotal = montoTotal + 6000;
							break;

						case 4://COMBO #4
							system("cls");
							montoTotal = montoTotal + 7000;
							break;

						case 5://COMBO #5
							system("cls");
							montoTotal = montoTotal + 8000;
							break;

						case 6://COMBO #6
							system("cls");
							montoTotal = montoTotal + 9000;
							break;

						case 7://COMBO #7
							system("cls");
							montoTotal = montoTotal + 10000;
							break;

						case 8://COMBO #8
							system("cls");
							montoTotal = montoTotal + 11000;
							break;

						case 9://COMBO #9
							system("cls");
							montoTotal = montoTotal + 12000;
							break;
						}
					}
					catch (std::string opcCombo) {}

				} while (opcCombo != "0");

				if (montoTotal == 0) {
					return;
				}

				system("cls");
				idPedido = idRandom();

				agregarPedido(nuevaListaPedidos, montoTotal, cedulaCliente, nombreRepa, restaElegido, idPedido);
				aumentarPedidos(lcli, cedulaCliente);

				cedJud = enviarCedulaJud(lresta, nuevaListaPedidos);
				aumentarPedidosRepa(lrepa, nombreRepa);
				aumentarPedidosRest(lresta, cedJud);

				std::cout << mostrarPedidoEspecifico(lcli, nuevaListaPedidos, cedulaCliente, idPedido);
				system("pause");
				//std::cout << mostrarPedido(lcli, nuevaListaPedidos, cedulaCliente);

				break;

			case 2://RESTAURANTE #2

				system("cls");

				nombreRepa = asignarRepartidor(lrepa, nuevaListaPedidos);
				restaElegido = "Pizza Hut";

				if (nombreRepa == "false") {//true porque si se asign� un repartidor
					std::cout << "\tNO SE ASIGN� NING�N REPARTIDOR" << std::endl;
					std::cout << "No hay repartidores disponibles en este momento" << std::endl;
					std::cout << "Vuelva a intentar hacer el pedido m�s tarde" << std::endl;
					system("pause");
					return;
				}
				do {
					std::cout << lresta->buscarEspecifico(lresta, "Pizza Hut");
					std::cout << "Digite el combo que desea:  " << std::endl;
					std::cout << "Si no desea ning�n combo digite 0 " << std::endl;
					std::cout << "Opci�n:  ";
					std::getline(std::cin, opcCombo);

					try {
						if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
							throw opcCombo;
						}
						switch (std::stoi(opcCombo)) {
						case 1://COMBO #1
							system("cls");
							montoTotal = montoTotal + 4000;
							break;

						case 2://COMBO #2
							system("cls");
							montoTotal = montoTotal + 5000;
							break;

						case 3://COMBO #3
							system("cls");
							montoTotal = montoTotal + 6000;
							break;

						case 4://COMBO #4
							system("cls");
							montoTotal = montoTotal + 7000;
							break;

						case 5://COMBO #5
							system("cls");
							montoTotal = montoTotal + 8000;
							break;

						case 6://COMBO #6
							system("cls");
							montoTotal = montoTotal + 9000;
							break;

						case 7://COMBO #7
							system("cls");
							montoTotal = montoTotal + 10000;
							break;

						case 8://COMBO #8
							system("cls");
							montoTotal = montoTotal + 11000;
							break;

						case 9://COMBO #9
							system("cls");
							montoTotal = montoTotal + 12000;
							break;
						}
					}
					catch (std::string opcCombo) {}

				} while (opcCombo != "0");

				if (montoTotal == 0) {
					return;
				}

				system("cls");
				idPedido = idRandom();
				agregarPedido(nuevaListaPedidos, montoTotal, cedulaCliente, nombreRepa, restaElegido, idPedido);
				aumentarPedidos(lcli, cedulaCliente);
				cedJud = enviarCedulaJud(lresta, nuevaListaPedidos);
				aumentarPedidosRepa(lrepa, nombreRepa);
				aumentarPedidosRest(lresta, cedJud);
				std::cout << mostrarPedidoEspecifico(lcli, nuevaListaPedidos, cedulaCliente, idPedido);
				system("pause");
				//std::cout << mostrarPedido(lcli, nuevaListaPedidos, cedulaCliente);
				break;

			case 3://RESTAURANTE #3
				system("cls");

				nombreRepa = asignarRepartidor(lrepa, nuevaListaPedidos);
				restaElegido = "La Princesa Marina";

				if (nombreRepa == "false") {//true porque si se asign� un repartidor
					std::cout << "\tNO SE ASIGN� NING�N REPARTIDOR" << std::endl;
					std::cout << "No hay repartidores disponibles en este momento" << std::endl;
					std::cout << "Vuelva a intentar hacer el pedido m�s tarde" << std::endl;
					system("pause");
					return;
				}

				do {
					std::cout << lresta->buscarEspecifico(lresta, "La Princesa Marina");
					std::cout << "Digite el combo que desea:  " << std::endl;
					std::cout << "Si no desea ning�n combo digite 0 " << std::endl;
					std::cout << "Opci�n:  ";
					std::getline(std::cin, opcCombo);

					try {
						if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
							throw opcCombo;
						}
						switch (std::stoi(opcCombo)) {
						case 1://COMBO #1
							system("cls");
							montoTotal = montoTotal + 4000;
							break;

						case 2://COMBO #2
							system("cls");
							montoTotal = montoTotal + 5000;
							break;

						case 3://COMBO #3
							system("cls");
							montoTotal = montoTotal + 6000;
							break;

						case 4://COMBO #4
							system("cls");
							montoTotal = montoTotal + 7000;
							break;

						case 5://COMBO #5
							system("cls");
							montoTotal = montoTotal + 8000;
							break;

						case 6://COMBO #6
							system("cls");
							montoTotal = montoTotal + 9000;
							break;

						case 7://COMBO #7
							system("cls");
							montoTotal = montoTotal + 10000;
							break;

						case 8://COMBO #8
							system("cls");
							montoTotal = montoTotal + 11000;
							break;

						case 9://COMBO #9
							system("cls");
							montoTotal = montoTotal + 12000;
							break;
						}
					}
					catch (std::string opcCombo) {}

				} while (opcCombo != "0");

				if (montoTotal == 0) {
					return;
				}

				system("cls");
				idPedido = idRandom();
				agregarPedido(nuevaListaPedidos, montoTotal, cedulaCliente, nombreRepa, restaElegido, idPedido);
				aumentarPedidos(lcli, cedulaCliente);
				cedJud = enviarCedulaJud(lresta, nuevaListaPedidos);
				aumentarPedidosRepa(lrepa, nombreRepa);
				aumentarPedidosRest(lresta, cedJud);
				std::cout << mostrarPedidoEspecifico(lcli, nuevaListaPedidos, cedulaCliente, idPedido);
				system("pause");
				//std::cout << mostrarPedido(lcli, nuevaListaPedidos, cedulaCliente);
				break;

			case 4://RESTAURANTE #4
				system("cls");

				nombreRepa = asignarRepartidor(lrepa, nuevaListaPedidos);
				restaElegido = "KFC";

				if (nombreRepa == "false") {//true porque si se asign� un repartidor
					std::cout << "\tNO SE ASIGN� NING�N REPARTIDOR" << std::endl;
					std::cout << "No hay repartidores disponibles en este momento" << std::endl;
					std::cout << "Vuelva a intentar hacer el pedido m�s tarde" << std::endl;
					system("pause");
					return;
				}
				do {
					std::cout << lresta->buscarEspecifico(lresta, "KFC");
					std::cout << "Digite el combo que desea:  " << std::endl;
					std::cout << "Si no desea ning�n combo digite 0 " << std::endl;
					std::cout << "Opci�n:  ";
					std::getline(std::cin, opcCombo);

					try {
						if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
							throw opcCombo;
						}
						switch (std::stoi(opcCombo)) {
						case 1://COMBO #1
							system("cls");
							montoTotal = montoTotal + 4000;
							break;

						case 2://COMBO #2
							system("cls");
							montoTotal = montoTotal + 5000;
							break;

						case 3://COMBO #3
							system("cls");
							montoTotal = montoTotal + 6000;
							break;

						case 4://COMBO #4
							system("cls");
							montoTotal = montoTotal + 7000;
							break;

						case 5://COMBO #5
							system("cls");
							montoTotal = montoTotal + 8000;
							break;

						case 6://COMBO #6
							system("cls");
							montoTotal = montoTotal + 9000;
							break;

						case 7://COMBO #7
							system("cls");
							montoTotal = montoTotal + 10000;
							break;

						case 8://COMBO #8
							system("cls");
							montoTotal = montoTotal + 11000;
							break;

						case 9://COMBO #9
							system("cls");
							montoTotal = montoTotal + 12000;
							break;
						}
					}
					catch (std::string opcCombo) {}

				} while (opcCombo != "0");

				if (montoTotal == 0) {
					return;
				}

				system("cls");
				idPedido = idRandom();
				agregarPedido(nuevaListaPedidos, montoTotal, cedulaCliente, nombreRepa, restaElegido, idPedido);
				aumentarPedidos(lcli, cedulaCliente);
				cedJud = enviarCedulaJud(lresta, nuevaListaPedidos);
				aumentarPedidosRepa(lrepa, nombreRepa);
				aumentarPedidosRest(lresta, cedJud);
				std::cout << mostrarPedidoEspecifico(lcli, nuevaListaPedidos, cedulaCliente, idPedido);
				system("pause");
				//std::cout << mostrarPedido(lcli, nuevaListaPedidos, cedulaCliente);
				break;

			case 5://RESTAURANTE #5
				system("cls");

				nombreRepa = asignarRepartidor(lrepa, nuevaListaPedidos);
				restaElegido = "Burger King";

				if (nombreRepa == "false") {//true porque si se asign� un repartidor
					std::cout << "\tNO SE ASIGN� NING�N REPARTIDOR" << std::endl;
					std::cout << "No hay repartidores disponibles en este momento" << std::endl;
					std::cout << "Vuelva a intentar hacer el pedido m�s tarde" << std::endl;
					system("pause");
					return;
				}

				do {
					std::cout << lresta->buscarEspecifico(lresta, "Burger King");
					std::cout << "Digite el combo que desea:  " << std::endl;
					std::cout << "Si no desea ning�n combo digite 0 " << std::endl;
					std::cout << "Opci�n:  ";
					std::getline(std::cin, opcCombo);

					try {
						if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
							throw opcCombo;
						}
						switch (std::stoi(opcCombo)) {
						case 1://COMBO #1
							system("cls");
							montoTotal = montoTotal + 4000;
							break;

						case 2://COMBO #2
							system("cls");
							montoTotal = montoTotal + 5000;
							break;

						case 3://COMBO #3
							system("cls");
							montoTotal = montoTotal + 6000;
							break;

						case 4://COMBO #4
							system("cls");
							montoTotal = montoTotal + 7000;
							break;

						case 5://COMBO #5
							system("cls");
							montoTotal = montoTotal + 8000;
							break;

						case 6://COMBO #6
							system("cls");
							montoTotal = montoTotal + 9000;
							break;

						case 7://COMBO #7
							system("cls");
							montoTotal = montoTotal + 10000;
							break;

						case 8://COMBO #8
							system("cls");
							montoTotal = montoTotal + 11000;
							break;

						case 9://COMBO #9
							system("cls");
							montoTotal = montoTotal + 12000;
							break;
						}
					}
					catch (std::string opcCombo) {}
				} while (opcCombo != "0");

				if (montoTotal == 0) {
					return;
				}

				system("cls");
				idPedido = idRandom();
				agregarPedido(nuevaListaPedidos, montoTotal, cedulaCliente, nombreRepa, restaElegido, idPedido);
				aumentarPedidos(lcli, cedulaCliente);
				cedJud = enviarCedulaJud(lresta, nuevaListaPedidos);
				aumentarPedidosRepa(lrepa, nombreRepa);
				aumentarPedidosRest(lresta, cedJud);
				std::cout << mostrarPedidoEspecifico(lcli, nuevaListaPedidos, cedulaCliente, idPedido);
				system("pause");
				//std::cout << mostrarPedido(lcli, nuevaListaPedidos, cedulaCliente);
				break;

			case 6://RESTAURANTE #6
				system("cls");

				nombreRepa = asignarRepartidor(lrepa, nuevaListaPedidos);
				restaElegido = "Las Canitas";

				if (nombreRepa == "false") {//true porque si se asign� un repartidor
					std::cout << "\tNO SE ASIGN� NING�N REPARTIDOR" << std::endl;
					std::cout << "No hay repartidores disponibles en este momento" << std::endl;
					std::cout << "Vuelva a intentar hacer el pedido m�s tarde" << std::endl;
					system("pause");
					return;
				}
				do {
					std::cout << lresta->buscarEspecifico(lresta, "Las Canitas");
					std::cout << "Digite el combo que desea:  " << std::endl;
					std::cout << "Si no desea ning�n combo digite 0 " << std::endl;
					std::cout << "Opci�n:  ";
					std::getline(std::cin, opcCombo);

					try {
						if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
							throw opcCombo;
						}
						switch (std::stoi(opcCombo)) {
						case 1://COMBO #1
							system("cls");
							montoTotal = montoTotal + 4000;
							break;

						case 2://COMBO #2
							system("cls");
							montoTotal = montoTotal + 5000;
							break;

						case 3://COMBO #3
							system("cls");
							montoTotal = montoTotal + 6000;
							break;

						case 4://COMBO #4
							system("cls");
							montoTotal = montoTotal + 7000;
							break;

						case 5://COMBO #5
							system("cls");
							montoTotal = montoTotal + 8000;
							break;

						case 6://COMBO #6
							system("cls");
							montoTotal = montoTotal + 9000;
							break;

						case 7://COMBO #7
							system("cls");
							montoTotal = montoTotal + 10000;
							break;

						case 8://COMBO #8
							system("cls");
							montoTotal = montoTotal + 11000;
							break;

						case 9://COMBO #9
							system("cls");
							montoTotal = montoTotal + 12000;
							break;
						}
					}
					catch (std::string opcCombo) {}
				} while (opcCombo != "0");

				if (montoTotal == 0) {
					return;
				}

				system("cls");
				idPedido = idRandom();
				agregarPedido(nuevaListaPedidos, montoTotal, cedulaCliente, nombreRepa, restaElegido, idPedido);
				aumentarPedidos(lcli, cedulaCliente);
				cedJud = enviarCedulaJud(lresta, nuevaListaPedidos);
				aumentarPedidosRepa(lrepa, nombreRepa);
				aumentarPedidosRest(lresta, cedJud);
				std::cout << mostrarPedidoEspecifico(lcli, nuevaListaPedidos, cedulaCliente, idPedido);
				system("pause");
				//std::cout << mostrarPedido(lcli, nuevaListaPedidos, cedulaCliente);
				break;

			case 7://RESTAURANTE #7
				system("cls");

				nombreRepa = asignarRepartidor(lrepa, nuevaListaPedidos);
				restaElegido = "POPS";

				if (nombreRepa == "false") {//true porque si se asign� un repartidor
					std::cout << "\tNO SE ASIGN� NING�N REPARTIDOR" << std::endl;
					std::cout << "No hay repartidores disponibles en este momento" << std::endl;
					std::cout << "Vuelva a intentar hacer el pedido m�s tarde" << std::endl;
					system("pause");
					return;
				}

				do {
					std::cout << lresta->buscarEspecifico(lresta, "POPS");
					std::cout << "Digite el combo que desea:  " << std::endl;
					std::cout << "Si no desea ning�n combo digite 0 " << std::endl;
					std::cout << "Opci�n:  ";
					std::getline(std::cin, opcCombo);

					try {
						if (opcCombo != "1" && opcCombo != "2" && opcCombo != "3" && opcCombo != "4" && opcCombo != "5" && opcCombo != "6" && opcCombo != "7" && opcCombo != "8" && opcCombo != "9") {
							throw opcCombo;
						}
						switch (std::stoi(opcCombo)) {
						case 1://COMBO #1
							system("cls");
							montoTotal = montoTotal + 4000;
							break;

						case 2://COMBO #2
							system("cls");
							montoTotal = montoTotal + 5000;
							break;

						case 3://COMBO #3
							system("cls");
							montoTotal = montoTotal + 6000;
							break;

						case 4://COMBO #4
							system("cls");
							montoTotal = montoTotal + 7000;
							break;

						case 5://COMBO #5
							system("cls");
							montoTotal = montoTotal + 8000;
							break;

						case 6://COMBO #6
							system("cls");
							montoTotal = montoTotal + 9000;
							break;

						case 7://COMBO #7
							system("cls");
							montoTotal = montoTotal + 10000;
							break;

						case 8://COMBO #8
							system("cls");
							montoTotal = montoTotal + 11000;
							break;

						case 9://COMBO #9
							system("cls");
							montoTotal = montoTotal + 12000;
							break;
						}
					}
					catch (std::string opcCombo) {}
				} while (opcCombo != "0");

				if (montoTotal == 0) {
					return;
				}

				system("cls");
				idPedido = idRandom();
				agregarPedido(nuevaListaPedidos, montoTotal, cedulaCliente, nombreRepa, restaElegido, idPedido);
				aumentarPedidos(lcli, cedulaCliente);
				cedJud = enviarCedulaJud(lresta, nuevaListaPedidos);
				aumentarPedidosRepa(lrepa, nombreRepa);
				aumentarPedidosRest(lresta, cedJud);
				std::cout << mostrarPedidoEspecifico(lcli, nuevaListaPedidos, cedulaCliente, idPedido);
				system("pause");
				//std::cout << mostrarPedido(lcli, nuevaListaPedidos, cedulaCliente);
				break;
			}
		}
		catch (std::string opcResta) {}

	} while (opcResta != "8");
}

void Control::agregarPedido(ListaPedidos* nuevaListaPedidos, float precio, std::string Cedula, std::string nombreRepa, std::string nombreResta, std::string aleatorioNuevo) {//settear pedido
	Pedido* nPedido = new Pedido;

	time_t now = time(0);//SETTEAR HORA
	tm* time = localtime(&now);//SETTEAR HORA
	int hora = time->tm_hour;//SETTEAR HORA

	nPedido->setIDPedido(aleatorioNuevo);
	nPedido->setPrecioPedido(precio);
	nPedido->setHoraRealizado(hora);
	nPedido->setEstadoPedido("En preparación");
	nPedido->setNombreCliente(Cedula);// NO ES EL NOMBRE DEL CLIENTE SINO LA CEDULA DEL CLIENTE
	nPedido->setNombreRepartidor(nombreRepa);
	nPedido->setNombreRestaurante(nombreResta);

	nuevaListaPedidos->agregarPedido(nPedido);
}

std::string Control::mostrarPedidoEspecifico(ListaCliente* nuevaListaCliente, ListaPedidos* nuevaListaPedidos, std::string Cedula, std::string idRandom) {
	std::stringstream x;

	Nodo* auxPedido = nuevaListaPedidos->getCabeza();
	Nodo* auxCliente = nuevaListaCliente->getCabeza();

	while (auxCliente != nullptr) {
		while (auxPedido != nullptr) {
			if (auxPedido->getDatoPedido()->getNombreCliente() == Cedula) {
				if (auxPedido->getDatoPedido()->getIDPedido() == idRandom) {
					x << auxPedido->getDatoPedido()->toStringPedido();
				}
			}
			auxPedido = auxPedido->getSig();
		}
		auxCliente = auxCliente->getSig();
	}
	return x.str();
}

std::string Control::mostrarPedido(ListaCliente* nuevaListaCliente, ListaPedidos* nuevaListaPedidos, std::string Cedula) {
	std::stringstream x;

	Nodo* auxPedido = nuevaListaPedidos->getCabeza();
	Nodo* auxCliente = nuevaListaCliente->getCabeza();

	while (auxCliente != nullptr) {
		while (auxPedido != nullptr) {
			if (auxPedido->getDatoPedido()->getNombreCliente() == Cedula) {
				x << auxPedido->getDatoPedido()->toStringPedido();
			}
			auxPedido = auxPedido->getSig();
		}
		auxCliente = auxCliente->getSig();
	}
	return x.str();
}

std::string Control::mostrarPedidoRepartidor(ListaRepartidor* repa, ListaPedidos* lp, std::string Cedula)
{
	std::stringstream x;

	Nodo* auxPedido = lp->getCabeza();
	Nodo* auxCliente = repa->getCabeza();

	while (auxCliente != nullptr) {
		while (auxPedido != nullptr) {
			if (auxPedido->getDatoPedido()->getNombreRepartidor() == Cedula) {
				x << auxPedido->getDatoPedido()->toStringPedido();
			}
			auxPedido = auxPedido->getSig();
		}
		auxCliente = auxCliente->getSig();
	}

	return x.str();
}

bool Control::verificarNumero(std::string linea) {
	bool b = true;
	int longitud = linea.size();

	if (longitud == 0) { // Cuando el usuario pulsa ENTER
		b = false;
	}
	else if (longitud == 1 && !isdigit(linea[0])) {
		b = false;
	}
	else {
		int i;
		if (linea[0] == '+' || linea[0] == '-')
			i = 1;
		else
			i = 0;

		while (i < longitud) {
			if (!isdigit(linea[i])) {
				b = false;
				break;
			}
			i++;
		}
	}
	return b;
}

int Control::retornarNumero() {
	int numero = 0;
	bool repite = true;
	std::string linea;
	do {
		//std::cout << "\nDigite el dato: ";
		std::getline(std::cin, linea);
		if (verificarNumero(linea)) {
			repite = false;
		}
		else {
			std::cout << "\n\tERROR\nEl dato debe contener solo n�meros" << std::endl;
			std::cout << "Digite el dato nuevamente: ";
		}
	} while (repite);

	numero = atoi(linea.c_str());

	return numero;
}

std::string Control::idRandom() {
	int aleatorio1 = 0 + rand() % 100;//SETTEAR ID
	int aleatorio2 = (0 + rand() % 55) + 12;//SETTEAR ID
	std::string aleatorioNuevo = "A" + std::to_string(aleatorio1) + std::to_string(aleatorio2);//SETTEAR ID

	return aleatorioNuevo;
}


bool Control::validarEstadoRepartidor(ListaRepartidor* repa, std::string id) {

	Nodo* aux = repa->getCabeza();

	while (aux != nullptr) {

		if (aux->getDatoRepa()->getNombre() == id && aux->getDatoRepa()->getEstado() == true) {
			return true;
		}
		aux = aux->getSig();
	}

	return false;
}

bool Control::validarAmonestaciones(ListaRepartidor* repa, std::string id) {
	Nodo* aux = repa->getCabeza();
	while (aux != nullptr) {
		if (aux->getDatoRepa()->getAmonestaciones() == 4 && aux->getDatoRepa()->getNombre() == id) {
			return false;
		}
		aux = aux->getSig();
	}
	return true;
}

bool Control::validarIDRepartidor(ListaRepartidor* liRepa, std::string id) {

	Nodo* aux = liRepa->getCabeza();

	while (aux != nullptr) {
		if (aux->getDatoRepa()->getCedula() != id) {
			aux = aux->getSig();
		}
		else {
			return true;
		}
	}

	return false;
}

std::string Control::mostarClientesActivos(ListaCliente* lc)
{
	std::stringstream x;
	Nodo* aux = lc->getCabeza();
	while (aux != nullptr) {
		if (aux->getDatoC()->getEstado() == true) {
			x << lc->mostrar();
		}

		aux = aux->getSig();
	}
	return x.str();
}

std::string Control::mostarClientesSuspendidos(ListaCliente* lc)
{
	std::stringstream x;
	Nodo* aux = lc->getCabeza();
	while (aux != nullptr) {
		if (aux->getDatoC()->getEstado() == false) {
			x << lc->mostrar();
		}

		aux = aux->getSig();
	}
	return x.str();
}
std::string Control::enviarCedulaJud(ListaRestaurante* lr, ListaPedidos* lp) {
	Nodo* aux = lr->getCabeza();
	Nodo* aux2 = lp->getCabeza();
	std::string cedula;
	while (aux != nullptr) {
		while (aux2 != nullptr) {
			if (aux->getDatoRest()->getNombre() == aux2->getDatoPedido()->getNombreRestaurante()) {
				cedula = aux->getDatoRest()->getCedulaJuridica();
			}
			aux2 = aux2->getSig();
		}
		aux = aux->getSig();
	}return cedula;
}

void Control::ventasMayores(ListaRestaurante* lr, ListaPedidos* lp) {
	Nodo* auxPe = lp->getCabeza();
	Nodo* auxRe = lr->getCabeza();
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0;

	while (auxRe != nullptr) {

		while (auxPe != nullptr) {

			if (auxPe->getDatoPedido()->getNombreRestaurante() == "McDonald's") {

				num1 = num1+(auxPe->getDatoPedido()->getPrecioPedido());

			}else if (auxPe->getDatoPedido()->getNombreRestaurante() == "Pizza Hut") {
				num2 = num2 + (auxPe->getDatoPedido()->getPrecioPedido());

			}else if (auxPe->getDatoPedido()->getNombreRestaurante() == "La Princesa Marina") {
				num3 = num3 + (auxPe->getDatoPedido()->getPrecioPedido());

			}else if (auxPe->getDatoPedido()->getNombreRestaurante() == "KFC") {
				num4 = num4 + (auxPe->getDatoPedido()->getPrecioPedido());

			}else if (auxPe->getDatoPedido()->getNombreRestaurante() == "Burger King") {
				num5 = num5 + (auxPe->getDatoPedido()->getPrecioPedido());

			}else if (auxPe->getDatoPedido()->getNombreRestaurante() == "Las Canitas") {
				num6 = num6 + (auxPe->getDatoPedido()->getPrecioPedido());

			}else if (auxPe->getDatoPedido()->getNombreRestaurante() == "POPS"){
				num7 = num7 + (auxPe->getDatoPedido()->getPrecioPedido());

			}
			auxPe = auxPe->getSig();
		}

		auxRe = auxRe->getSig();
	}
	numMayor(num1, num2,  num3,  num4,  num5,  num6,  num7);
}

void Control::numMayor(int num1, int num2, int num3, int num4, int num5, int num6, int num7){
	if ( num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 > num6 && num1 > num7) {
		std::cout << "El restaurante con mayor número de ventas es McDonald's";
	}
	if (num2 > num1 && num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6 && num2 > num7) {
		std::cout << "El restaurante con mayor número de ventas es Pizza Hut";
	}
	if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5 && num3 > num6 && num3 > num7) {
		std::cout << "El restaurante con mayor número de ventas es La Princesa Marina";
	}
	if (num4 > num1 && num4 > num2 && num4 > num3 && num4 > num5 && num4 > num6 && num4 > num7) {
		std::cout << "El restaurante con mayor número de ventas es KFC";
	}
	if (num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4 && num5 > num6 && num5 > num7) {
		std::cout << "El restaurante con mayor número de ventas es Burger King";
	}
	if (num6 > num1 && num6 > num2 && num6 > num3 && num6 > num4 && num6 > num5 && num6 > num7) {
		std::cout << "El restaurante con mayor número de ventas es Las Canitas";
	}
	if (num7 > num1 && num7 > num2 && num7 > num3 && num7 > num4 && num7 > num5 && num7 > num6) {
		std::cout << "El restaurante con mayor número de ventas es POPS";
	}
}
