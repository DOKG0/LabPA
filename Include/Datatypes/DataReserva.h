#ifndef DATARESERVA_H
#define DATARESERVA_H

#include <string>
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "DTFecha.h"
#include "Enum.h"
#include "../ico.h"


class DataReservaLight : public ICollectible{
private:
	int CodigoReserva;
	DTFecha *FechaCheckIn;
	DTFecha *FechaCheckOut;
	Estado EstadoReserva;
	
public:
	DataReservaLight();
	DataReservaLight(int codigo, DTFecha *checkIn, DTFecha *checkOut, Estado estadoReserva);
	~DataReservaLight();

	int getCodigo();
	DTFecha *getCheckIn();
	DTFecha *getCheckOut();
	Estado getEstadoReserva();
};

class DataReserva{
private:
	int CodigoReserva;
	DTFecha *FechaCheckIn;
	DTFecha *FechaCheckOut;
	Estado EstadoReserva;
	int NumeroHabitacion;
	IDictionary* Huespedes = nullptr;
	float Costo;
	bool Descuento;
	
public:
	DataReserva();
	DataReserva(int codigo, DTFecha *checkIn, DTFecha *checkOut, Estado estadoReserva, int habitacion, IDictionary* huespedes, float costo, bool descuento);
	~DataReserva();
	
	int getCodigo();
	DTFecha *getCheckIn();
	DTFecha *getCheckOut();
	Estado getEstadoReserva();
	int getHabitacion();
	float getCosto();
	bool getDescuento();
	IDictionary* getHuespedes();
	
};

#endif