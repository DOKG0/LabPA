#ifndef DATAHABITACION_H
#define DATAHABITACION_H
#include "../ico.h"

class DataHabitacion: public ICollectible{
private:
    int NumeroHabitacion;
    int Precio;
    int Capacidad;

public:
    DataHabitacion();
    DataHabitacion(int numeroHabitacion, int precion, int capacidad);
    ~DataHabitacion();

    int getNumero();
    int getPrecio();
    int getCapacidad();
};

#endif