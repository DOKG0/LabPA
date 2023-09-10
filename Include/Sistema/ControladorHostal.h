#ifndef ControladorHostal_H
#define ControladorHostal_H

#include "InterfazHostal.h"
#include "Excepciones.h"
#include "Hostal/Hostal.h"
#include "ManejadorHostal.h"
#include "ManejadorUsuario.h"
#include "../ico.h"
#include "../Sistema/Usuario/Empleado.h"
#include "../ICollection/interfaces/ICollection.h"
#include <string>

class ControllerHostal: public InterfazHostal{

    private:
        static ControllerHostal *Instance;
        ControllerHostal();
        ///////////////////////////////
        ////////MemoriaRecuerda////////
        //Hostal 
        std::string NombreHostal;
        //Usuario
        std::string EmailUsuario;
        //Habitacion
        Habitacion * habitacion;
        //Reserva
        int CodigoReserva;
        //Estadia
        int CodigoEstadia;
        ////////MemoriaRecuerda////////
        ///////////////////////////////

        Reserva * reserva;
        
        //Atributos
        int NumeroHabitacion;
        float PrecioHabitacion;
        int CapacidadHabitacion;
        DTFecha * CheckInRes;
        DTFecha * CheckOutRes;  
        
    public:
        //General/////////////////////////////
        static ControllerHostal* getInstance();
        ~ControllerHostal();
        IDictionary * hostales;
        //Fin General/////////////////////////
        IDictionary* ObtenerHostales();

        //AltaHostal
        void altaHostal(string nombreHostal, string direccion, string telefono);

        //Top3Hostal
        ICollection* Top3Hostales();
        

        //~AltaHabitacion///////////////////////////////
        bool ingresoDataHab(int numero, std::string nombreHostal); //Chequea si existe esa hab
        void ConfirmarAltaHabitacion(float precio, int capacidad); //Confirmar el alta de la habitacio
        //Fin AltaHabitacion///////////////////////////////

        bool ExisteHabitacion(int numero);
        //asignar empleado
        

        //Consulta Reserva //Baja Reserva
        DataReserva * ObtenerReservasHostal(std::string NombreHostal, int CodigoReserva);
        //ConsultaHostal
        DataHostal * InformacionHostal(std::string NombreHostal);
        //Registrar Estadia
        IDictionary * ObtenerReservas(std::string NombreHostal, std::string EmailHuesped);
        void CrearCheckIn(std::string NombreHostal, int codigoReserva, DTFecha *FechaCheckin, std::string Promo);
        //Finalizar Estadia
        DataEstadia * ObtengoEstadiasAb(std::string NombreHostal, std::string EmailHuesped);
        void FinalizarEstadia(int CodigoEstadia, int CodigoReserva, DTFecha *FechaCheckOut);
        //Baja Reserva
        void ConfirmarEliminarReserva(std::string NombreHostal, int CodigoReserva);
        void EliminarReserva(std::string NombreHostal, int CodigoReserva);
        //Consultar estadia
        IDictionary * ObtenerDataEstadiaBasica(std::string NombreHostal);
        DataEstadiaExtra * ObtenerDataEstadiaExtra(std::string NombreHostal, int CodigoReserva, int CodigoEstadia);
        DataReservaLight * ObtenerInfoReserva(std::string NombreHostal, std::string EmailUsuario, int CodigoReserva, int CodigoEstadia);
        DataCalificacion * ObtenerCalificacion(std::string NombreHostal, std::string EmailUsuario, int CodigoReserva, int CodigoEstadia);
        //
        IDictionary * ObtenerCalificacionesSinRespuesta(std::string NombreHostal);
        void AgregarComentarioCalificacion(std::string NombreHostal, int CodigoEstadia, std::string comentario);
        //
        IDictionary * ListarHostal();

        void CancelarRealizarReserva();
        void ConfirmarRealizarReserva();
        DataReservaLight* RealizarReserva(int numeroHabitacion);
        IDictionary* ListarHabitacionDisponible(string nombreHostal, DTFecha *FechaCheckIn, DTFecha *FechaCheckOut);

};


#endif