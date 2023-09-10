#ifndef DATAESTADIA_H
#define DATAESTADIA_H

#include <string>
#include "DTFecha.h"
#include "../ico.h"


class DataEstadia : public ICollectible{
protected:
	int CodigoEstadia;
	DTFecha *FechaEntrada;
	DTFecha *FechaSalida;
	std::string Promo;
	int CodigoReserva;
	

public:
	DataEstadia(int codigoEstadia, DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo);
	DataEstadia(int codigoEstadia, DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo, int CodigoReserva);
	~DataEstadia();
	DataEstadia();

	int getCodigoEstadia();
	DTFecha *getFechaEntrada();
	DTFecha *getFechaSalida();
	std::string getPromo();
	void setCodigoReserva(int codigoreserva);
	
};

class DataEstadiaExtra: public DataEstadia{
private:
	std::string EmailHuesped;
	std::string Hostal;
	int NumeroHabitacion;
	int CodigoReserva;

public:
	DataEstadiaExtra();
	DataEstadiaExtra(int codigoEstadia, DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo, std::string emailHuesped, std::string nombreHostal, 
						int numeroHabitacion, int codigoReserva);
	DataEstadiaExtra(int codigoEstadia,DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo, std::string emailHuesped);
	DataEstadiaExtra(int codigoEstadia,DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo, std::string emailHuesped, int numeroHabitacion, int codigoReserva);
	~DataEstadiaExtra();

	std::string getEmailHuesped();
	std::string getNombreHostal();
	int getNumeroHabitacion();
	int getCodigoReserva();
};


#endif
