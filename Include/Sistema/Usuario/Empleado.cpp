#include "Empleado.h"
#include <iostream>
#include <string.h>
#include "../ManejadorUsuario.h"

Empleado::Empleado(std::string Nombre, std::string Email, std::string Password, tipoCargo Cargo){
    this->Nombre = Nombre;
    this->Email = Email;
    this->Password = Password;
    setCargo(Cargo);
}

//Set & get
void Empleado::setCargo(tipoCargo cargo){
    this->CargoEmpleado = cargo;
}

tipoCargo Empleado::getCargo(){
    return this->CargoEmpleado;
}

//Operacion padre
void Empleado::setNombre(std::string Nombre){
    this->Nombre = Nombre;

}
void Empleado::setEmail(std::string Email){
    this->Email = Email;
}

void Empleado::setPassword(std::string Password){
    this->Password = Password;
}

std::string Empleado::getNombre(){
    return this->Nombre;
}

std::string Empleado::getEmail(){
    return this->Email;
}

std::string Empleado::getPassword(){
    return this->Password;
}

// bool Empleado::trabajaEmp(std::string NombreHostal){
//     return (strcmp(NombreHostal.c_str(),this->hostalTrabaja->getNombre().c_str())==0) ;
// }

// bool Empleado::trabajaEmp(std::string NombreHostal){
//     std::cout << ("llega al IF EN TRABAJAEMP EMPLEADO")<< std::endl;
//     getchar();
//     if(this->hostalTrabaja != nullptr && NombreHostal == this->hostalTrabaja->getNombre()){
//         return true;// trabaja
//             std::cout << ("llega al IF TRUE EN TRABAJAEMP EMPLEADO")<< std::endl;
//     getchar();
//     }else if(this->hostalTrabaja != nullptr && NombreHostal != this->hostalTrabaja->getNombre()){
//         return false;//libre
//         std::cout << ("llega al IF  FALSE EN TRABAJAEMP EMPLEADO")<< std::endl;
//     }

//     getchar();
//     return false;
// }

bool Empleado::trabajaEmp(std::string NombreHostal){
    if(NombreHostal == this->getHostalTrabaja()){
        return true; //trabaja ahi
    }
    return false; // no trabaja ahi
}

std::string  Empleado::getHostalTrabaja(){
    std::string var = "No Esta Asociado A Ningun Hostal";
    if(hostalTrabaja == nullptr){
        return var;
    }
    return this->hostalTrabaja->getNombre();
}

DataEmpleado* Empleado::getdata(){
    return new DataEmpleado(this->Nombre, this->Email, this->CargoEmpleado);
};


//Asignar empleado Hostal

void Empleado::AsignarEmpleado(Hostal *h, tipoCargo Cargo){
    this->hostalTrabaja = h;
    this->CargoEmpleado = Cargo;
}
