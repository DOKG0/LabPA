#include "FechaSistema.h"
#include "../Datatypes/Datatypes.h"
#include <iostream>
using namespace std;
//#include <iomanip>

FechaSistema::FechaSistema(int diaN, int mesN, int anioN, int horaN, int minutoN)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
};

FechaSistema *FechaSistema::instancia = NULL;

FechaSistema *FechaSistema::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new FechaSistema(3, 7, 2023, 20, 30);
    };
    return instancia;
};

void FechaSistema::releaseInstancia()
{
    if (instancia != NULL)
    {
        delete instancia;
        instancia = NULL;
    };
}

FechaSistema::~FechaSistema(){};

int FechaSistema::getDia()
{
    return this->dia;
};

int FechaSistema::getMes()
{
    return this->mes;
};

int FechaSistema::getAnio()
{
    return this->anio;
};

int FechaSistema::getHora()
{
    return this->hora;
};

int FechaSistema::getMinuto()
{
    return this->minuto;
};

void FechaSistema::setFechaSistema(int dia, int mes, int anio, int hora, int minuto)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
};

DTFecha *FechaSistema::getFechaSistema()
{
    DTFecha *res = new DTFecha(this->dia, this->mes, this->anio, this->hora, this->minuto);
    return res;
};