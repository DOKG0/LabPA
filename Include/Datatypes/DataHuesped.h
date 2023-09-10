#ifndef DATAHUESPED_H
#define DATAHUESPED_H

#include "DataUsuario.h"
#include <string>

class DataHuesped : public DataUsuario{
    private:
        std::string Nombre;
        std::string Email;
        bool esFinger;
    public:
        DataHuesped();
        DataHuesped(std::string _nombre, std::string _email, bool _esFinger);
        ~DataHuesped();

        std::string getNombreHuesped();
        std::string getEmailHuesped();
        bool getesFinger();

};

#endif