#include "DataEstadia.h"
#include "DTFecha.h"

//DataEstadia
DataEstadia::DataEstadia(){};

DataEstadia::DataEstadia(int codigoEstadia, DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo){
    this->CodigoEstadia = codigoEstadia;
    this->FechaEntrada = fechaEntrada;
    this->FechaSalida = fechaSalida;
    this->Promo = promo;
};

DataEstadia::DataEstadia(int codigoEstadia, DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo, int CodigoReserva){
    this->CodigoEstadia = codigoEstadia;
    this->FechaEntrada = fechaEntrada;
    this->FechaSalida = fechaSalida;
    this->Promo = promo;
    this->CodigoReserva = CodigoReserva;
}

DataEstadia::~DataEstadia(){};

int DataEstadia::getCodigoEstadia(){
    return this->CodigoEstadia;
};

DTFecha *DataEstadia::getFechaEntrada(){
    return this->FechaEntrada;
};

DTFecha *DataEstadia::getFechaSalida(){
    return this->FechaSalida;
};

std::string DataEstadia::getPromo(){
    return this->Promo;
};

void DataEstadia::setCodigoReserva(int codigoReserva){
    this->CodigoReserva = codigoReserva;
}


//DataEstadiaExtra
DataEstadiaExtra::DataEstadiaExtra(){};

DataEstadiaExtra::DataEstadiaExtra(int codigoEstadia, DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo, std::string emailHuesped, std::string nombreHostal, 
						int numeroHabitacion, int codigoReserva){
    
    this->CodigoEstadia    = codigoEstadia;
    this->FechaEntrada     = fechaEntrada;
    this->FechaSalida      = fechaSalida;
    this->Promo            = promo;
    this->EmailHuesped     = emailHuesped;
    this->Hostal           = nombreHostal;
    this->NumeroHabitacion = numeroHabitacion;
    this->CodigoReserva    = codigoReserva;

};

DataEstadiaExtra::~DataEstadiaExtra(){};
                                
std::string DataEstadiaExtra::getEmailHuesped(){
    return this->EmailHuesped;
};
 
std::string DataEstadiaExtra::getNombreHostal(){
    return this->Hostal;
};

int DataEstadiaExtra::getNumeroHabitacion(){
    return this->NumeroHabitacion;
};

int DataEstadiaExtra::getCodigoReserva(){
    return this->CodigoReserva;
};

//DataEstadiaExtra2

DataEstadiaExtra::DataEstadiaExtra(int codigoEstadia,DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo, std::string emailHuesped){
    this->CodigoEstadia    = codigoEstadia;
    this->FechaEntrada     = fechaEntrada;
    this->FechaSalida      = fechaSalida;
    this->Promo            = promo;
    this->EmailHuesped     = emailHuesped;
}

DataEstadiaExtra::DataEstadiaExtra(int codigoEstadia,DTFecha *fechaEntrada, DTFecha *fechaSalida, std::string promo, std::string emailHuesped, int numeroHabitacion, int CodigoReserva){
    this->CodigoEstadia    = codigoEstadia;
    this->FechaEntrada     = fechaEntrada;
    this->FechaSalida      = fechaSalida;
    this->Promo            = promo;
    this->EmailHuesped     = emailHuesped;
    this->NumeroHabitacion = numeroHabitacion;
    this->CodigoReserva    = CodigoReserva;
}