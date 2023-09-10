#include "ReservaIndividual.h"
#include <iostream>
#include <string>
#include "../../Menu/Functions.h"
#include <string.h>

ReservaIndividual::ReservaIndividual(){

};

ReservaIndividual::~ReservaIndividual(){

};

ReservaIndividual::ReservaIndividual(float Costo){
    this->Costo = Costo;
}

float ReservaIndividual::getCostoRI(){
    return this->Costo;
}

void ReservaIndividual::setCostoRI(float Costo){
    this->Costo = Costo;
}


//Existe huesped con reserva individual¿
bool ReservaIndividual::ExisteEmailReservaI(std::string EmailHuesped){
    if(strcmp(EmailHuesped.c_str(),huesped->getEmail().c_str()) ==0 ){
        return true;
    }else{
        return false;
    }
}
//Calcular costo reserva individual

//RegistrarEstadiaI
void ReservaIndividual::CrearEstadiaRI(DTFecha *FechaCheckIn, std::string Promo){
    this->estadia = new Estadia(1,FechaCheckIn,Promo);
};

//FinalizarEstadia - Obtener
//ReservaIndividual
DataEstadia * ReservaIndividual::ObtenerEstadiaAbAccRes(std::string EmailHuesped){
    if(strcmp(EmailHuesped.c_str(),estadia->getEmailHuespedEstadia().c_str()) == 0){
        return new DataEstadia(1,estadia->getFechaEntrada(),nullptr,estadia->getPromo());
    }
    return nullptr;
};

//fin - estadia - fin
DataEstadia * ReservaIndividual::FinEstadiaI(int CodigoEstadia, DTFecha * FechaCheckOut){
    if(CodigoEstadia == estadia->getCodigoEstadia()){
        estadia->setFechaSalida(FechaCheckOut);
    }
    return nullptr;

};

//eliminar reserva

void ReservaIndividual::EliminarReservaAccres(){
    estadia->eliminarCalificacion();
    delete estadia;
}

//consulta estadia
DataEstadia * ReservaIndividual::ConseguirDataEstadiaBasicaReserva(){
    return this->estadia->getDataEstadia();
}

DataEstadiaExtra * ReservaIndividual::ConseguirDataEstadiaExtraReservaIn(int CodigoEstadia){
    DataEstadiaExtra * dtei;
    if(CodigoEstadia == estadia->getCodigoEstadia()){
        dtei = new DataEstadiaExtra(estadia->getCodigoEstadia(),estadia->getFechaEntrada(),estadia->getFechaSalida(),estadia->getPromo(),estadia->getEmailHuespedEstadia());
    }
    return dtei;
}

DataCalificacion * ReservaIndividual::ObtenerCalificacionAccResI(int CodigoEstadia){
    if(CodigoEstadia == this->estadia->getCodigoEstadia()){
        return this->estadia->getCalificacionEst();
    }
    return nullptr;
}

DataCalificacionExtra * ReservaIndividual::ObtenerCalificacionSinRAccResI(){
    return new DataCalificacionExtra(estadia->getCalificacionEst()->getCalifificacion(),estadia->getCalificacionEst()->getComentarios(),estadia->getCodigoEstadia());
}

void ReservaIndividual::AgregarComentarioAccResI(int CodigoEstadia, std::string Comentario){
    if(this->estadia->getCodigoEstadia() == CodigoEstadia){
        this->estadia->AgregarComentarioCalificacionAccEst(Comentario);
    } 
}