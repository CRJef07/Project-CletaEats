#ifndef COMBO_H
#define COMBO_H
#include  <iostream>
#include <sstream>
class Combo
{
public:

	Combo(std::string principal, std::string acompannamiento, std::string bebida, int precio, int cant);
	~Combo();
	std::string getPrincipal();
	void setPrincipal(std::string principal);

	std::string getAcompannamiento();
	void setAcompannamiento(std::string acompannamiento);

	std::string getBebida();
	void setBebida(std::string bebida);

	int getPrecio();
	void setPrecio(int precio);

	const int& getCant() const;
	void setCant(const int& cant);


	std::string toString();
	std::string toStringArchivo();
private:
	int cant;
	std::string principal;
	std::string acompannamiento;
	std::string bebida;
	int precio;
	
};
#endif
