#include "DataHuesped.h"
#include <iostream>

DataHuesped::DataHuesped(){};

DataHuesped::DataHuesped(std::string _nombre, std::string _email, bool _esFinger){
    this->Nombre = _nombre;
    this->Email = _email;
    this->esFinger = _esFinger;
};


DataHuesped::~DataHuesped(){};

std::string DataHuesped::getNombreHuesped(){
    return this->Nombre;
};

std::string DataHuesped::getEmailHuesped(){
    return this->Email;
};

bool DataHuesped::getesFinger(){
    return this->esFinger;
};
