#ifndef DATAEMPLEADO_H
#define DATAEMPLEADO_H


#include "DataUsuario.h"
#include <string>
#include "Enum.h"
class DataEmpleado : public DataUsuario{
    private:
        std::string Nombre;
        std::string Email;
        tipoCargo TipoCargo;
    public:
        DataEmpleado();
        DataEmpleado(std::string _nombre, std::string _email, tipoCargo _TipoCargo);
        ~DataEmpleado();
        DataEmpleado(std::string _nombre, std::string _email, tipoCargo _TipoCargo, std::string nameht);

        std::string getNombreEmp();
        std::string getEmailEmp();
        tipoCargo getTipoCargo();
        std::string HostalTrabajaData();        

};
#endif