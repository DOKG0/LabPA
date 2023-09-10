#ifndef RESERVAINDIVIDUAL_H
#define RESERVAINDIVIDUAL_H

#include <string>
#include "Reserva.h"
#include "Estadia.h"
#include "../../ico.h"
#include "../Usuario/Huesped.h"
#include "../../Datatypes/Datatypes.h"

class ReservaIndividual: public Reserva {
private:
		float Costo;
		//IDictionary *huesped;
		Huesped *huesped; //Arreglar
		Estadia * estadia;
		//Huesped * huesped;
public:
		ReservaIndividual();
		ReservaIndividual(float costo);
		~ReservaIndividual();
		float getCostoRI();
		void setCostoRI(float costo);
		//Calcular costo
		float CalcularCostoRI(int codigoReserva,float precioHab, DTFecha *fecha_Checkin, DTFecha *fecha_Checkout);
		//ExisteHUesped¿
		bool ExisteEmailReservaI(std::string EmailHuesped);
		//CreaEstadiaIndi
		void CrearEstadiaRI(DTFecha *FechaCheckIn, std::string Promo);
		//FinalizarEstadia
		DataEstadia * ObtenerEstadiaAbAccRes(std::string EmailHuesped); // ????
		DataEstadia * FinEstadiaI(int CodigoEstadia, DTFecha *FechaCheckOut);

		//baja res
		void EliminarReservaAccres();
		//ConsultaEstadia
		DataEstadia * ConseguirDataEstadiaBasicaReserva();
		DataEstadiaExtra * ConseguirDataEstadiaExtraReservaIn(int CodigoEstadia);
		DataCalificacion * ObtenerCalificacionAccResI(int CodigoEstadia);
		//comentar calificacion
		DataCalificacionExtra * ObtenerCalificacionSinRAccResI();
		void AgregarComentarioAccResI(int CodigoEstadia, std::string Comentario);
		//
};

#endif