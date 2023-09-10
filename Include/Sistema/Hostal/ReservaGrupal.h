#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H

#include <string>
#include <string.h>
#include "Reserva.h"
#include "Estadia.h"
#include "../Usuario/Huesped.h"

class ReservaGrupal : public Reserva {
private:
		float Costo;
		bool Descuento;
		IDictionary * huespedes;
		IDictionary * estadias;
		int contadorEstadias;
	
public:
		ReservaGrupal();
		ReservaGrupal(float Costo, bool Descuento);
		~ReservaGrupal();
		float getCostoRG();
		bool getDescuentoRG();
		void setCostoRG(float Costo);
		void setDescuentoRG(bool Descuento);
		
		//
		bool ExisteEmailReservaGR(std::string EmailHuesped);
		//EstadiaGrupal
		void CrearEstadiaRG(DTFecha *FechaCheckIn, std::string Promo);

		//Operaciones icollection
		void addRG(IKey *k, ICollectible *val);
        bool memberRG(IKey *k);
        void removeRG(IKey *k);
        ICollectible *findRG(IKey *k);
        bool isEmptyRG();
        int getSizeRG();
        IIterator * getIteratorRG();
		DataEstadia * ObtenerEstadiaAbAccRes(std::string EmailUsuario);
		DataEstadia * FinEstadia(int CodigoEstadia, DTFecha *FechaCheckOut);

		//Eliminar reserva
		void EliminarReservaAccres();

		//Consulta estadia
		IDictionary * ConseguirDataEstadiaBasicaReserva();
		DataEstadiaExtra * ConseguirDataEstadiaExtraReserva(int CodigoEstadia);
		DataCalificacion * ObtenerCalificacionAccResG(int CodigoEstadia);
		//
		IDictionary* ObtenerCalificacionesSinRAccResG();
		void AgregarComentarioCalificacionAccResG(int CodigoEstadia, std::string comentario);


		

		

};

#endif