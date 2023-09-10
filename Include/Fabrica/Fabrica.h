#ifndef FABRICA_H
#define FABRICA_H

#include "../Sistema/ControladorHostal.h"
#include "../Sistema/ControladorUsuario.h"


class Fabrica {
    private:
        static Fabrica* instancia;
        Fabrica();

    public:
        static Fabrica * getInstance();
        ~Fabrica();
        InterfazHostal* Hostal();
        InterfazUsuario* Usuario();

};

#endif
