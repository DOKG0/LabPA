#include "DataReserva.h"
#include "../Sistema/Usuario/Huesped.h"
#include "../ICollection/String.h"

//Metodos DataReservaLight
DataReservaLight::DataReservaLight(){};
DataReservaLight::DataReservaLight(int codigo, DTFecha *checkIn, DTFecha *checkOut, Estado estadoReserva){
    this->CodigoReserva = codigo;
    this->FechaCheckIn = checkIn;
    this->FechaCheckOut = checkOut;
    this->EstadoReserva = estadoReserva;
};
DataReservaLight::~DataReservaLight(){};


int DataReservaLight::getCodigo(){
    return this->CodigoReserva;
};
DTFecha *DataReservaLight::getCheckIn(){
    return this->FechaCheckIn;
};
DTFecha *DataReservaLight::getCheckOut(){
    return this->FechaCheckOut;
};
Estado DataReservaLight::getEstadoReserva(){
    return this->EstadoReserva;
};


//Metodos DataReserva
DataReserva::DataReserva(){};

DataReserva::DataReserva(int codigo, DTFecha *checkIn, DTFecha *checkOut, Estado estadoReserva, int habitacion, IDictionary* huespedes, float costo, bool descuento){
    
    this->CodigoReserva = codigo;
    this->FechaCheckIn = checkIn;
    this->FechaCheckOut = checkOut;
    this->EstadoReserva = estadoReserva;
    this->NumeroHabitacion = habitacion;
    this->Costo = costo;
    this->Descuento = descuento;

    this->Huespedes = new OrderedDictionary();
    this->Huespedes = huespedes;

    //Preguntar Copia de la coleccion ?
    /*for (IIterator* it = huespedes->getIterator(); it->hasCurrent(); it->next()){
        std::string email = ((Huesped*)it->getCurrent())->getEmail();
    };*/
};

DataReserva::~DataReserva(){
    for (IIterator* it = this->Huespedes->getIterator(); it->hasCurrent(); it->next()){
        Huesped* hped = ((Huesped*)it->getCurrent());
        std::string email = hped->getEmail();
        String* llave = new String(email.c_str());

        Huespedes->remove(llave);

        delete hped;
    };
};

int DataReserva::getCodigo(){
    return this->CodigoReserva;
};
DTFecha *DataReserva::getCheckIn(){
    return this->FechaCheckIn;
};
DTFecha *DataReserva::getCheckOut(){
    return this->FechaCheckOut;
};
Estado DataReserva::getEstadoReserva(){
    return this->EstadoReserva;
};

int DataReserva::getHabitacion(){
    return this->NumeroHabitacion;
};

float DataReserva::getCosto(){
    return this->Costo;
};
bool DataReserva::getDescuento(){
    return this->Descuento;
};

IDictionary* DataReserva::getHuespedes(){
    return this->Huespedes;
}
