#ifndef ESTADIA_H
#define ESTADIA_H

#include <string>
#include "../../Datatypes/Datatypes.h"
#include "../../ico.h"
#include "../Usuario/Huesped.h"
#include "Calificacion.h"

class Estadia : public ICollectible{
	private:
		int codigoEstadia;
		DTFecha *fechaEntrada;
		DTFecha *fechaSalida;
		std::string promo;
		Calificacion * calificacion;
		IDictionary * ReservasEst;
		Huesped * HuespedesEst;

	public:
		Estadia();
		Estadia(int CodigoEstadia,DTFecha *FechaEntrada, std::string Promo);
		~Estadia();
		//getters
		int getCodigoEstadia();
		DTFecha *getFechaEntrada();
		DTFecha *getFechaSalida();
		std::string getPromo();
		//setters
		void setCodigoEstadia(int CodigoEstadia);
		void setFechaEntrada(DTFecha *FechaEntrada);
		void setFechaSalida(DTFecha *FechaSalida);
		void setPromo(std::string Promo);
		
		//
		void eliminarCalificacion();
		//
		std::string getEmailHuespedEstadia();
		//
		DataEstadia * getDataEstadia(); //solo datos de 1 estadia
		DataCalificacion *  getCalificacionEst();
		//
		//IDictionary * ObtenerCalificacionSinRAccEst(); //Segun lo que hice no va no es necesaria :V
		void AgregarComentarioCalificacionAccEst(std::string Comentario);

/*

	DataEstadiaExtra GetDataExtra(EmailUsuario)
	int ObtenerCal()

	DataCalificacion ObtenerCalificaciones() 
	Set(DataCalificacion) ObtenerCalificacionAccederEstadia () 
	AgregarComentarioAccederEstadia(CodigoCalficacion int, Respuesta string)
	
	ConfirmarEliminarReservaAccederEstadia()
	ObtenerEstadiaAbAccEst()
	ObtenerEstadiasFinalizadasAccEst()
	CalificarEstadiaAccEst(Califica int, Comentario string)
	FinalizarEstadiaAccEst(FechaCheckOut DataFecha)
	CancelarCalificaciónAccEst()
*/
};

#endif