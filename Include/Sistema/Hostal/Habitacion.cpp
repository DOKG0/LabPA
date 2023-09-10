#include "Habitacion.h"


Habitacion::Habitacion(){};
Habitacion::Habitacion(int numerohab, float precio, int capacidad){
	this->NumeroHab = numerohab;
	this->Precio = precio;
	this->Capacidad = capacidad;
};
Habitacion::~Habitacion(){};

void Habitacion::setNumeroHab(int numerohab){
	this->NumeroHab = numerohab;
};
void Habitacion::setCapacidad(int capacidad){
	this->Capacidad = capacidad;
};
void Habitacion::setPrecio(float precio){
	this->Precio = precio;
};

int Habitacion::getNumeroHab(){
	return this->NumeroHab;
};
int Habitacion::getCapacidad(){
	return this->Capacidad;
};
float Habitacion::getPrecio(){
	return this->Precio;
};

DataHabitacion* Habitacion::getDataHabitacion(){
	return new DataHabitacion(this->NumeroHab, this->Precio, this->Capacidad);
};

