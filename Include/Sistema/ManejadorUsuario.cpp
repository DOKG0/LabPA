#include "ManejadorUsuario.h"


ManejadorUsuario * ManejadorUsuario::instancia = nullptr;

ManejadorUsuario * ManejadorUsuario::getInstance(){
    if (instancia = nullptr){
        return new ManejadorUsuario();
    }
    return instancia;
};

ManejadorUsuario::ManejadorUsuario(){
    this->Empleados = new OrderedDictionary();
    this->Huespedes = new OrderedDictionary();
};

//Coleccion Empelados
void ManejadorUsuario::addEmpleados(IKey *k, ICollectible *val){
    this->Empleados->add(k, val);
};
bool ManejadorUsuario::memberEmpleados(IKey *k){
    return this->Empleados->member(k);
};
void ManejadorUsuario::removeEmpleados(IKey *k){
    this->Empleados->remove(k);
};
ICollectible* ManejadorUsuario::findEmpleados(IKey *k){
    return this->Empleados->find(k);
};
bool ManejadorUsuario::isEmptyEmpleados(){
    return this->Empleados->isEmpty();
};

IIterator * ManejadorUsuario::getIteratorEmpleados(){
    return this->Empleados->getIterator();
}

int ManejadorUsuario::getSizeEmpleados(){
    return this->Empleados->getSize();
}

//Coleccion Huespedes
void ManejadorUsuario::addHuespedes(IKey *k, ICollectible *val){
    this->Huespedes->add(k, val);
};
bool ManejadorUsuario::memberHuespedes(IKey *k){
    return this->Huespedes->member(k);
};
void ManejadorUsuario::removeHuespedes(IKey *k){
    this->Huespedes->remove(k);
};
ICollectible* ManejadorUsuario::findHuespedes(IKey *k){
    return this->Huespedes->find(k);
};
bool ManejadorUsuario::isEmptyHuespedes(){
    return this->Huespedes->isEmpty();
};

IIterator * ManejadorUsuario::getIteratorHuespedes(){
    return this->Huespedes->getIterator();
}

int ManejadorUsuario::getSizeHuespedes(){
    return this->Huespedes->getSize();
}
