///////////////////////////////////////////////////////
#include "Fabrica.h"

#include "../Sistema/ControladorHostal.h"
#include  "../Sistema/ControladorUsuario.h"
#include "../Sistema/InterfazHostal.h"
#include "../Sistema/InterfazUsuario.h"


///////////////////////////////////////////////////////

Fabrica* Fabrica::instancia = 0;

Fabrica::Fabrica(){
}

Fabrica::~Fabrica(){
}

Fabrica * Fabrica::getInstance(){
    if(instancia == nullptr){
        instancia = new Fabrica();
    }
    return instancia;
}

//Controlador Usuario
InterfazUsuario * Fabrica::Usuario(){
    return ControllerUsuario::getInstance();
}

//Controlador Hostal
InterfazHostal * Fabrica::Hostal(){
    return ControllerHostal::getInstance();
}

