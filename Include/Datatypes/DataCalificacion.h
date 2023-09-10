#ifndef DATACALIFICACION_H
#define DATACALIFICACION_H

#include <iostream>
#include "../ICollection/collections/List.h"
#include "Enum.h"

class DataCalificacion : public ICollectible{
protected:
    int Calificacion;
    ICollection* Comentarios; 


public:
    DataCalificacion(int calificacion, ICollection* comentarios);

    ~DataCalificacion();

    int getCalifificacion();
    ICollection* getComentarios();
};

class DataCalificacionExtra: public ICollectible{

    private:
        int Calificacion;
        ICollection* Comentarios; 
        int CodigoEstadia;
        int CodigoReserva;
    public:
        DataCalificacionExtra(int calificacion, ICollection* comentarios, int CodigoEstadia, int CodigoReserva);
        DataCalificacionExtra(int calificacion, ICollection* comentarios, int CodigoEstadia);
        ~DataCalificacionExtra();
        //getters
        int getCodigoEstadiaCalExtra();
        int getCodigoReservaCalExtra();
        int getCalifificacionExtra();
        ICollection* getComentariosExtra();



};

#endif