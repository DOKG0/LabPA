#ifndef FechaSistema_H
#define FechaSistema_H
#include "../Datatypes/DTFecha.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class FechaSistema
{
private:
    static FechaSistema *instancia;
    ~FechaSistema();
    FechaSistema(int dia, int mes, int anio, int hora, int minuto);

    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

public:
    static FechaSistema *getInstancia();
    static void releaseInstancia();

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    void setFechaSistema(int dia, int mes, int anio, int hora, int minuto);
    DTFecha *getFechaSistema();
};

#endif