#include "DataCalificacion.h"
#include "../../Include/ICollection/interfaces/IIterator.h"
#include "../../Include/ICollection/String.h"

DataCalificacion::DataCalificacion(int calificacion, ICollection* comentarios){
    this->Calificacion = calificacion;
    this->Comentarios = comentarios;
};

DataCalificacion::~DataCalificacion(){ 
    for (IIterator* it = this->Comentarios->getIterator(); it->hasCurrent(); it->next()){
        String* str = (String*)it->getCurrent();
        Comentarios->remove(it->getCurrent());
        delete str;
    };
};

int DataCalificacion::getCalifificacion(){
    return this->Calificacion;
};

ICollection* DataCalificacion::getComentarios(){
    return this->Comentarios;
};

//////////////////////////DataCalificacionExtra/////////////////////////

DataCalificacionExtra::DataCalificacionExtra(int calificacion, ICollection* comentarios, int CodigoEstadia, int CodigoReserva){
    this->Calificacion = calificacion;
    this->Comentarios = comentarios;
    this->CodigoEstadia = CodigoEstadia;
    this->CodigoReserva = CodigoReserva;
}

DataCalificacionExtra::DataCalificacionExtra(int calificacion, ICollection* comentarios, int CodigoEstadia){
    this->Calificacion = calificacion;
    this->Comentarios = comentarios;
    this->CodigoEstadia = CodigoEstadia;
}

int DataCalificacionExtra::getCodigoEstadiaCalExtra(){
    return this->CodigoEstadia;
}
int DataCalificacionExtra::getCodigoReservaCalExtra(){
    return this->CodigoReserva;
}

DataCalificacionExtra::~DataCalificacionExtra(){ 
    for (IIterator* it = this->Comentarios->getIterator(); it->hasCurrent(); it->next()){
        String* str = (String*)it->getCurrent();
        Comentarios->remove(it->getCurrent());
        delete str;
    };
};

int DataCalificacionExtra::getCalifificacionExtra(){
    return this->Calificacion;
};

ICollection* DataCalificacionExtra::getComentariosExtra(){
    return this->Comentarios;
};