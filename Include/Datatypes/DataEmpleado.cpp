#include "DataEmpleado.h"
#include <iostream>
#include "Enum.h"
#include "../Sistema/Usuario/Empleado.h"


DataEmpleado::DataEmpleado(){};

DataEmpleado::DataEmpleado(std::string _nombre, std::string _email, tipoCargo _TipoCargo){
    this->Nombre = _nombre;
    this->Email = _email;
    this->TipoCargo = _TipoCargo;
};

DataEmpleado::DataEmpleado(std::string _nombre, std::string _email, tipoCargo _TipoCargo, std::string nameht){
    this->Nombre = _nombre;
    this->Email = _email;
    this->TipoCargo = _TipoCargo;
    this->HostalTrabajaData() = nameht;
}
DataEmpleado::~DataEmpleado(){};

std::string DataEmpleado::getNombreEmp(){
    return this->Nombre;
}

std::string DataEmpleado::getEmailEmp(){
    return this->Email;
};

tipoCargo DataEmpleado::getTipoCargo(){
    return this->TipoCargo;
};

std::string DataEmpleado::HostalTrabajaData(){
    Empleado *e;
    std::string var = "No Esta Asociado A Ningun Hostal(dte)";
    if(e->getHostalTrabaja() == "nullptr"){
        var;
    }
    return e->getHostalTrabaja();
} 
