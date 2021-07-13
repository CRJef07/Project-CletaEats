#ifndef NODOCALIF_H
#define NODOCALIF_H
#include "Calificacion.h"
class NodoCalif
{
public:
	NodoCalif(Calificacion*);
	void setDatoCalif(Calificacion*);
	Calificacion* getDatoCalif();

	void setSig(NodoCalif* sig);
	NodoCalif* getSig();
private:
	NodoCalif* sig;
	Calificacion* datoCalif;
};
#endif
