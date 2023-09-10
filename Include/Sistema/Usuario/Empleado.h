#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Usuario.h"
#include "../../Datatypes/Datatypes.h"
#include "../../ico.h"
#include "../Hostal/Hostal.h"
#include "../Hostal/Calificacion.h"


class Empleado: public Usuario{
private:
	tipoCargo CargoEmpleado;
	Hostal * hostalTrabaja = nullptr;
	Calificacion * comentaCal;
	
public:

   	//AsignarEmpleado(std::string Email, tipoCargo Cargo);

	//Set(DataCalificacion) ObtenerCalificacionAccederEmpleado()
	Empleado(std::string Nombre, std::string Email, std::string Password, tipoCargo Cargo);
	
	//Operaciones padre
	void setNombre(std::string);
	void setEmail(std::string);
	void setPassword(std::string);
	std::string getNombre();
	std::string getEmail();
	std::string getPassword();
	//setters y getters
	std::string getHostalTrabaja();
	void setCargo(tipoCargo Cargo);
	bool trabajaEmp(std::string nombreHostal);
	tipoCargo getCargo();
	DataEmpleado* getdata();
	void AsignarEmpleado(Hostal *h, tipoCargo Cargo);

};




#endif