#ifndef HABITACION_H
#define HABITACION_H

#include "../../ico.h"
#include "../../Datatypes/DataHabitacion.h"
#include "../../Datatypes/Datatypes.h" 


class Habitacion: public ICollectible{
private:
	int NumeroHab;
	float Precio;
	int Capacidad;
	
public:
	Habitacion();
	Habitacion(int numerohab, float precio, int capacidad);
	~Habitacion();

	void setNumeroHab(int numerohab);
	void setCapacidad(int capacidad);
	void setPrecio(float precio);

	int getNumeroHab();
	int getCapacidad();
	float getPrecio();

	DataHabitacion* getDataHabitacion();
	
};

#endif