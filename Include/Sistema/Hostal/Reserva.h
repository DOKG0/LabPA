#ifndef RESERVA_H
#define RESERVA_H

#include "../../Datatypes/Datatypes.h" //aca esta el enum
#include "../../ico.h"
#include "Habitacion.h"

class Reserva: public ICollectible {

protected:
     int CodigoReserva;

	DTFecha *FechaCheckIn;
	DTFecha *FechaCheckOut;
	Estado EstadoReserva;
     Habitacion * habitacion;

public:
     Reserva();
     Reserva(int CodigoReserva, DTFecha FechaCheckIn,DTFecha FechaCheckOut,Estado EstadoReserva, Habitacion* habitacion);
     Reserva(int CodigoReserva, DTFecha *FechaCheckIn,DTFecha *FechaCheckOut,Estado EstadoReserva);

     ~Reserva();
  
     int getCodigo();
     DTFecha *getFechaCheckIn();
     DTFecha *getFechaCheckOut();
     Estado getEstadoReserva();
     //habitacion
     int getNumHabitacion();
     //calculo costo reserva
     float CalcularCosto(float precioHab, DTFecha* fecha_Checkin, DTFecha* fecha_Checkout);
     //setters
     void setCodigoReserva(int CodigoReserva);
     void setFechaCheckIn(DTFecha *FechaCheckIn);
     void setFechaCheckOut(DTFecha *FechaCheckOut);
     void setEstadoReserva(Estado EstadoReserva);
     void setHabitacion(Habitacion* h);
     //func
     float ObtenerTotCal();
     //Finalizar Estadia
     virtual DataEstadia *ObtenerEstadiaAbAccRes(std::string EmailUsuario) = 0;
     //getdataReserva

	   virtual DataReservaLight * getReserva() = 0;
     //
     virtual void EliminarReservaAccres() = 0;
     //
     
     //

     bool hayReservasParaLaHab(DTFecha* FechaCheckIn, DTFecha* FechaCheckOut);
     //void LinkearHabitacion(Habitacion* hab);  incluido en Hostal::crearReserva
/*
     
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
     
     FinalizarEstadiaAccRes(CodigoEstadia int, FechaCheckOut DataFecha)
     CrearEstadia()
     CerrarReserva()
*/
};

#endif
