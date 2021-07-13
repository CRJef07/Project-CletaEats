#include "NodoCalif.h"

NodoCalif::NodoCalif(Calificacion* D)
{
	sig = NULL;
	datoCalif = D;
}

void NodoCalif::setDatoCalif(Calificacion* d)
{
	datoCalif = d;
}

Calificacion* NodoCalif::getDatoCalif()
{
	return datoCalif;
}

void NodoCalif::setSig(NodoCalif* sig)
{
	this->sig = sig;
}

NodoCalif* NodoCalif::getSig()
{
	return sig;
}
