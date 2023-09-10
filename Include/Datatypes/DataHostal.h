#ifndef DATAHOSTAL_H
#define DATAHOSTAL_H

#include <string>
#include "../ico.h"

class DataHostalLight : public ICollectible{
private:
	std::string Nombre;
	std::string Direccion;
	std::string Telefono;
	float CalificacionPromedio;
	
public:
	DataHostalLight();
	DataHostalLight(std::string nombre, std::string direccion, std::string telefono);
	
	~DataHostalLight();

	std::string getNombre();
	std::string getDireccion();
	std::string getTelefono();
	float getCalPromedio();

};

class DataHostal: public ICollectible{
private:
	std::string Nombre;
	std::string Direccion;
	std::string Telefono;
	IDictionary* Habitaciones;
	IDictionary* Calificaciones;
	
public:
	DataHostal();
	DataHostal(std::string nombre);
	DataHostal(std::string nombre, std::string direccion, std::string telefono, IDictionary* habitaciones, IDictionary* calificaciones);
	~DataHostal();

	std::string getNombre();
	std::string getDireccion();
	std::string getTelefono();
	IDictionary* getHabitaciones();
	IDictionary* getCalificaciones();
};

#endif