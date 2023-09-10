#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include "InterfazUsuario.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ico.h"

class ManejadorUsuario{
    private:
        static ManejadorUsuario* instancia;
        ManejadorUsuario();
        IDictionary* Empleados;
        IDictionary* Huespedes;
        ////////////////////////
    public:
        static ManejadorUsuario* getInstance();
        //////////
        //Empleados
        void addEmpleados(IKey *k, ICollectible *val);
        bool memberEmpleados(IKey *k);
        void removeEmpleados(IKey *k);
        ICollectible *findEmpleados(IKey *k);
        bool isEmptyEmpleados();
        int getSizeEmpleados();
        IIterator * getIteratorEmpleados();
        //Huespedes
        void addHuespedes(IKey *k, ICollectible *val);
        bool memberHuespedes(IKey *k);
        void removeHuespedes(IKey *k);
        ICollectible *findHuespedes(IKey *k);
        bool isEmptyHuespedes();
        int getSizeHuespedes();
        IIterator * getIteratorHuespedes();
};

#endif