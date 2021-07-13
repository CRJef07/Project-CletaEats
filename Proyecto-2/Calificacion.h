#ifndef CALIFICACION_H
#define CALIFICACION_H
#include <fstream>
#include <sstream>
#include <iostream>
class Calificacion
{
public:
	Calificacion();
	Calificacion(std::string amabilidad, std::string tiempoDeRespuesta, std::string presentacion, std::string quejas);
	~Calificacion();

	std::string getAmabilidad();
	void setAmabilidad(std::string amabilidad);

	std::string getTiempoDeRespuesta();
	void setTiempoDeRespuesta(std::string tiempoDeRespuesta);

	std::string getPresentacion();
	void setPresentacion(std::string presentacion);

	std::string getQuejas();
	void setQuejas(std::string quejas);

	std::string toString();

	Calificacion& autoCargarC(std::ifstream&);
	void autoGuardarC(std::ofstream& archivoGuardar);
private:
	std::string amabilidad;
	std::string tiempoDeRespuesta;
	std::string presentacion; 
	std::string quejas;
};
#endif // !
