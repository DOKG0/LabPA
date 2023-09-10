#ifndef InterfazUsuario_H
#define InterfazUsuario_H
#include <iostream>
#include "../Datatypes/Datatypes.h"

class InterfazUsuario {

    private:

    public:
            //altaUsuario

        virtual IDictionary *ListaUsuarios() = 0;
        //virtual void ConfirmarAltaUsuario() = 0;
        virtual void ConfirmarAltaEmpleado(std::string nombre, std::string email, std::string password, tipoCargo cargo) = 0;
        virtual void ConfirmarAltaHuesped(std::string nombre, std::string email,std::string password, bool esFinger) = 0;
        //asignar empleadohsotal
        virtual void ConfirmarEmpleado(std::string NombreHostal, std::string EmailEmpleado, tipoCargo Cargo)=0;
        
        virtual bool ingresoData(std::string Email) = 0;
        //ConsultaUsuario
        //virtual String ObtieneUsuario() = 0;
        virtual DataUsuario* InformacionUsuario(std::string Email) = 0;
        virtual DataHuesped *InformacionHuesped(std::string Email) = 0;
        virtual DataEmpleado *InformacionEmpleado(std::string Email) = 0;
        virtual bool ExisteUsuario(std::string Email) = 0;
        virtual IDictionary* getDataEmp(std::string NombreHostal) = 0;
        virtual IDictionary* ListarEmpleadosDisponibles(std::string NombreHostal) = 0;
        //Calificacoon comentar - obtener nombreHostal donde trabaja empleado
        virtual std::string ObtenerHostalTrabajaEmpleado(std::string EmailEmpleado) = 0;
};      

#endif