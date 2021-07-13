#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <sstream>
#include <fstream>
//ES UNA CLASE PADRE
class Persona{
public:
	Persona();
	Persona(std::string nombre, std::string cedula, std::string correo, std::string direccion, int tarjeta, int telefono, bool estado);
	virtual ~Persona();

	const std::string &getNombre()const;
	void setNombre(const std::string &nombre);

	const std::string &getCedula()const;
	void setCedula(const std::string &cedula);

	const std::string &getCorreo()const;
	void setCorreo(const std::string &correo);

	const std::string &getDireccion()const;
	void setDireccion(const std::string &direccion);

	const int &getTarjeta()const;
	void setTarjeta(const int &tarjeta);

	const int &getTelefono()const;
	void setTelefono(const int &telefono);

	const bool& getEstado()const;
	void setEstado(const bool& estado);
	 std::string toString();

protected:
	std::string nombre;
	std::string cedula;
	std::string correo;
	std::string direccion;
	int tarjeta;
	int telefono;
	bool estado;
};
#endif