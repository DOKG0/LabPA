#include "Huesped.h"

//DataHuesped getData()

Huesped::Huesped(std::string Nombre, std::string Email, std::string Password, bool esFinger){
    this->Nombre = Nombre;
    this->Email = Email;
    this->Password = Password;
    setEsFinger(esFinger);
}

void Huesped::setEsFinger(bool _esFinger){
    this->esFinger = _esFinger;
}

bool Huesped::getEsFinger(){
    return this->esFinger;
}

//Operacion padre
void Huesped::setNombre(std::string Nombre){
    this->Nombre = Nombre;

}
void Huesped::setEmail(std::string Email){
    this->Email = Email;
}

void Huesped::setPassword(std::string Password){
    this->Password = Password;
}

std::string Huesped::getNombre(){
    return this->Nombre;
}

std::string Huesped::getEmail(){
    return this->Email;
}

std::string Huesped::getPassword(){
    return this->Password;
}

