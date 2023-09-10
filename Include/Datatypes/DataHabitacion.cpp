#include "DataHabitacion.h"

DataHabitacion::DataHabitacion(){};
DataHabitacion::DataHabitacion(int numeroHabitacion, int precio, int capacidad){
    this->NumeroHabitacion = numeroHabitacion;
    this->Precio = precio;
    this->Capacidad = capacidad;
};

DataHabitacion::~DataHabitacion(){};

int DataHabitacion::getNumero(){
    return this->NumeroHabitacion;
};

int DataHabitacion::getPrecio(){
    return this->Precio;
};

int DataHabitacion::getCapacidad(){
    return this->Capacidad;
};