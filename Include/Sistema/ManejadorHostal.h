#ifndef MANEJADORHOSTAL_H
#define MANEJADORHOSTAL_H

#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ico.h"

#include "InterfazHostal.h"
#include <string>

class ManejadorHostal {
    private:
        static ManejadorHostal* instancia;
        ManejadorHostal();
        //std::string NombreHostal;
        IDictionary* Hostales = new OrderedDictionary();
        
    public:
        static ManejadorHostal* getInstance();
        //Hostal
        void add(IKey *k, ICollectible *val);
        bool member(IKey *k);
        void remove(IKey *k);
        ICollectible *find(IKey *k);
        bool isEmpty();
        int getSize();
        //
        IIterator * getIterator();
        IDictionary* getHostales();

        
        
};

#endif