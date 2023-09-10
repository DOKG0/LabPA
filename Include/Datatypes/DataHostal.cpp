#include <string>
#include "DataHostal.h"
#include "../ico.h"

//DataHostalLight
DataHostalLight::DataHostalLight(){};
DataHostalLight::DataHostalLight(std::string nombre, std::string direccion, std::string telefono){
    this->Nombre    = nombre;
    this->Direccion = direccion;
    this->Telefono  = telefono;

    //hacer calculo de promedio
};


DataHostalLight::~DataHostalLight(){};

std::string DataHostalLight::getNombre(){
    return this->Nombre;
};
std::string DataHostalLight::getDireccion(){
    return this->Direccion;
};
std::string DataHostalLight::getTelefono(){
    return this->Telefono;
};
float DataHostalLight::getCalPromedio(){
    return this->CalificacionPromedio;
};

//DataHostal

DataHostal::DataHostal(){}; 


DataHostal::DataHostal(std::string nombre, std::string direccion, std::string telefono, IDictionary* habitaciones, IDictionary* calificaciones){
    this->Nombre = nombre;
    this->Direccion = direccion;
    this->Telefono = telefono;
    this->Habitaciones = habitaciones;
    this->Calificaciones = calificaciones;
};

DataHostal::DataHostal(std::string nombre){
    this->Nombre = nombre;
}

DataHostal::~DataHostal(){
    for (IIterator* it = this->Habitaciones->getIterator(); it->hasCurrent(); it->next()){
        OrderedKey* llave = ((OrderedDictionaryEntry*)it->getCurrent())->getKey();
        Habitaciones->remove(llave);
    };

    for (IIterator* it = this->Calificaciones->getIterator(); it->hasCurrent(); it->next()){
        OrderedKey* llave = ((OrderedDictionaryEntry*)it->getCurrent())->getKey();
        Calificaciones->remove(llave);
    };
};

std::string DataHostal::getNombre(){
    return this->Nombre;
};
std::string DataHostal::getDireccion(){
    return this->Direccion;
};
std::string DataHostal::getTelefono(){
    return this->Telefono;
};
IDictionary* DataHostal::getHabitaciones(){
    return this->Habitaciones;
};
IDictionary* DataHostal::getCalificaciones(){
    return this->Calificaciones;
};