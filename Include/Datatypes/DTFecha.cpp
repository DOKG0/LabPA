#include "DTFecha.h"

DTFecha::DTFecha(){};
DTFecha::DTFecha(int ano, int mes, int dia, int horas, int minutos){
    this->Ano = ano;
    this->Mes = mes;
    this->Dia = dia;
    this->Horas = horas;
    this->Minutos = minutos;
};



DTFecha::~DTFecha(){};

int DTFecha::getAno(){
    return this->Ano;
};

int DTFecha::getMes(){
    return this->Mes;
};
int DTFecha::getDia(){
    return this->Dia;
};
int DTFecha::getHoras(){
    return this->Horas;
};
int DTFecha::getMinutos(){
    return this->Minutos;
};
