#ifndef HUESPED_H
#define HUESPED_H

#include "Usuario.h"
class Estadia;
class Huesped: public Usuario{
private:
	bool esFinger;
	
public:
	//DataHuesped getData();
	
	Huesped(std::string Nombre, std::string Email, std::string Password, bool esFinger);
	//Operaciones del padre /sett & gett
	void setNombre(std::string);
	void setEmail(std::string);
	void setPassword(std::string);
	std::string getNombre();
	std::string getEmail();
	std::string getPassword();

	//setters y getters
	void setEsFinger(bool esFinger);
	bool getEsFinger();
};

#endif