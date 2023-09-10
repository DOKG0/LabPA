#ifndef ControladorUsuario_H
#define ControladorUsuario_H

#include <string>
#include "../Datatypes/Datatypes.h"

#include "InterfazUsuario.h"
#include "../ico.h"
#include "ManejadorUsuario.h"


class ControllerUsuario: public InterfazUsuario{

    private:
        static ControllerUsuario *instance;
        ControllerUsuario();
        
        std::string NombreUser;
        std::string EmailUser;
        std::string PasswordUser;
        tipoCargo CargoEmp;
        bool esFingerHuesped;
        //Colecciones

        IDictionary* usuarios;


    public:
        static ControllerUsuario* getInstance();
        ////
        IDictionary* huespedes;
        IDictionary* empleados;
        ////

        //
        DataHuesped *InformacionHuesped(std::string Email);
        DataEmpleado *InformacionEmpleado(std::string Email);


        //Mostrar
        IDictionary * ListaUsuarios();
        ///////
        //alta usuario
        //void AltaEmpleado(std::string Nombre, std::string Email, std::string Contraseña, tipoCargo  Cargo);
        //void AltaHuesped(std::string Nombre , std::string Email, std::string Contraseña , bool EsFinger );
        void ConfirmarAltaEmpleado(std::string nombre, std::string email, std::string password, tipoCargo cargo);
        void ConfirmarAltaHuesped(std::string nombre, std::string email, std::string password, bool esFinger);
        bool ingresoData(std::string Email);
        //asignaremplado
        void ConfirmarEmpleado(std::string NombreHostal, std::string EmailEmpleado, tipoCargo Cargo);
        //ConsultaUsuario
        string** ObtieneUsuario();
        DataUsuario* InformacionUsuario(std::string Email);
        IDictionary* getDataEmp(std::string NombreHostal);
        IDictionary* ListarEmpleadosDisponibles(std::string NombreHostal);
        ~ControllerUsuario();
        //Existeusuario?
        bool ExisteUsuario(std::string Email);
        //comentar calificacion
        std::string ObtenerHostalTrabajaEmpleado(std::string EmailEmpleado);
        IDictionary * ListarHuespedCtrU();
        DataHuesped SeleccionHuesped(std::string Email);
};

#endif