#include "Reserva.h"
#include "../../Datatypes/Datatypes.h"
#include <iostream>
#include <string>
#include "../../Menu/Functions.h"

Reserva::Reserva(){
};

Reserva::~Reserva(){

}

Reserva::Reserva(int CodigoReserva, DTFecha *FechaCheckIn,DTFecha *FechaCheckOut,Estado EstadoReserva){

     this->CodigoReserva = CodigoReserva;
     this->FechaCheckIn = FechaCheckIn;
     this->FechaCheckOut = FechaCheckOut;
     this->EstadoReserva = EstadoReserva;
     this->habitacion = habitacion;
};

int Reserva::getCodigo(){
     return this->CodigoReserva;
};

DTFecha *Reserva::getFechaCheckIn(){
     return this->FechaCheckIn;
};

DTFecha *Reserva::getFechaCheckOut(){
     return this->FechaCheckOut;
}

Estado Reserva::getEstadoReserva(){
     return this->EstadoReserva;
}

void Reserva::setCodigoReserva(int CodigoReserva){
     this->CodigoReserva = CodigoReserva;
}

void Reserva::setEstadoReserva(Estado EstadoReserva){
     this->EstadoReserva = EstadoReserva;
}

void Reserva::setFechaCheckIn(DTFecha *FechaCheckIn){
     this->FechaCheckIn = FechaCheckIn;
}

void Reserva::setFechaCheckOut(DTFecha *FechaCheckOut){
     this->FechaCheckOut = FechaCheckOut;
}

void Reserva::setHabitacion(Habitacion* h){
     this->habitacion = h;
}

int Reserva::getNumHabitacion(){
     //return this->habitacion->getNumeroHab();
     return 0;
}


float Reserva::CalcularCosto(float precioHab, DTFecha* fecha_Checkin, DTFecha* fecha_Checkout){
     //reserva individual
     
     int dias = DiferenciaEnDias(fecha_Checkin,fecha_Checkout);
     float costo = dias * precioHab;
     //falta mas logica pero no se si es mejor hacerlo en el menu
     return 0;
}

DataReservaLight * Reserva::getReserva(){
    return new DataReservaLight(this->getCodigo(),this->getFechaCheckIn(),this->getFechaCheckOut(),this->getEstadoReserva()); 
}





bool Reserva::hayReservasParaLaHab(DTFecha* FechaCheckIn, DTFecha* FechaCheckOut){ 

     bool tieneReserva = false;
     DTFecha *fechaReservaCheckIn = this->getFechaCheckIn();
     DTFecha *fechaReservaCheckOut = this->getFechaCheckOut();
 
     // Verificar los casos de las fechas de reserva
     // Caso: La reserva que estoy mirando y la enviada por parámetro son iguales
     /*
     if (fechaReservaCheckIn == FechaCheckIn && fechaReservaCheckOut == FechaCheckOut) {
          tieneReserva = true;

          // Caso: La reserva que estoy mirando está antes de la enviada por parámetro
          } else if (fechaReservaCheckOut < FechaCheckIn) {
               tieneReserva = true;

               // Caso: La reserva que estoy mirando está después de la enviada por parámetro
               } else if (fechaReservaCheckIn > FechaCheckOut) {
                    tieneReserva = true;
                    }
     */
     return tieneReserva;
}

/*
	Data Reserva getData() 
     LinkearHabitacion(Numero Int)
     bool noHayReservasParaLaHab (FechaCheckIn DTFecha, FechaCheckOut DTFecha)
     AgregarComentarioAccederReserva(CodigoCalficacion int, Respuesta string)
     ObtenerReservasHostalAccederReserva()
     ConfirmarEliminarReservaAccederReserva()
     EliminarReservaAccederReserva()
     Float ObtenerTotCal() 
     
     Data Calificacion ObtenerCalificacion(CodigoEstadia Int)
     CalificarEstadiaAccRes(CodigoEstadia int, Califica int, Comentario string)
     DataCalificacion obtenerCalificaciones() 
     CancelarCalificacionAccRes()
     DataEstadiaExtra RetornarEstadias(CodigoEstadia Int)
     Set(DataEstadia) ObtenerEstadiasFinalizadasAccRes(EmailUsuario string)
     ObtenerEstadiaAbAccRes(EmailUsuario string)
     FinalizarEstadiaAccRes(CodigoEstadia int, FechaCheckOut DataFecha)
     CrearEstadia()
     CerrarReserva()
*/