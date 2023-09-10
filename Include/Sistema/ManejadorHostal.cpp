#include "ManejadorHostal.h"
#include "../ICollection/collections/OrderedDictionary.h"

ManejadorHostal * ManejadorHostal::instancia = 0;


ManejadorHostal::ManejadorHostal(){
    this->Hostales = new OrderedDictionary();
};

ManejadorHostal* ManejadorHostal::getInstance(){
    if (instancia == nullptr){
        return new ManejadorHostal();
    }
    return instancia;
};

void ManejadorHostal::add(IKey *k, ICollectible *val){
    this->Hostales->add(k, val);
};

bool ManejadorHostal::member(IKey *k){
    return this->Hostales->member(k);
};

void ManejadorHostal::remove(IKey *k){
    this->Hostales->remove(k);
};

ICollectible* ManejadorHostal::find(IKey *k){
    return this->Hostales->find(k);
};

bool ManejadorHostal::isEmpty(){
    return this->Hostales->isEmpty();
};

int ManejadorHostal::getSize(){
    return this->Hostales->getSize();
};

IIterator * ManejadorHostal::getIterator(){
    return this->Hostales->getIterator();
};

IDictionary* ManejadorHostal::getHostales(){
    return this->Hostales;
}