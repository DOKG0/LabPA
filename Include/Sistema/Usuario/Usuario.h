#ifndef Usuario_H
#define Usuario_H

#include <string>
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../Datatypes/Enum.h"

class Usuario : public ICollectible {
//Clase abstracta de Usuario, debe tener todos los procesos como virtual. Se implementan en Empleado y Huesped por separado
protected:
	std::string Nombre;
	std::string Email;
	std::string Password;
	
public:
	virtual void setNombre(std::string Nombre) = 0;
	virtual void setEmail(std::string Email) = 0;
	virtual void setPassword(std::string Password) = 0;
	//virtual void setEsFinger(bool esFinger) = 0;
	//virtual void setCargo(tipoCargo Cargo) = 0;

	Usuario();
	//Usuario(std::string Nombre, std::string Email, std::string Password);
	Usuario(Usuario &User);
	~Usuario();

	virtual std::string getNombre() = 0;
	virtual std::string getEmail() = 0;
	virtual std::string getPassword() = 0;
	//virtual bool getEsFinger() = 0;
	//virtual tipoCargo getCargo() = 0;
	
	
};

#endif