#include "ReservaGrupal.h"

ReservaGrupal::ReservaGrupal(){

};

ReservaGrupal::ReservaGrupal(float Costo, bool Descuento){
    this->Costo = Costo;
    this->Descuento = Descuento;
};

ReservaGrupal::~ReservaGrupal(){

};

float ReservaGrupal::getCostoRG(){
    return this->Costo;
}

bool ReservaGrupal::getDescuentoRG(){
    return this->Descuento;
}

void ReservaGrupal::setCostoRG(float Costo){
    this->Costo = Costo;
}

void ReservaGrupal::setDescuentoRG(bool Descuento){
    this->Descuento = Descuento;
}

bool ReservaGrupal::ExisteEmailReservaGR(std::string EmailHuesped){
    for(IIterator *it = huespedes->getIterator();it->hasCurrent();it->next()){
        Huesped * h = dynamic_cast<Huesped*>(it->getCurrent());
        if(h->getEmail() == EmailHuesped){
            return true;
        }
    }

    return false;
}

void ReservaGrupal::CrearEstadiaRG(DTFecha *FechaCheckIn, std::string Promo){
    this->contadorEstadias++;
    Estadia * e = new Estadia(this->contadorEstadias,FechaCheckIn,Promo);
    IKey * ik = new Integer(e->getCodigoEstadia());
    estadias->add(ik,e);
}

//Finalizar estadia - obtener
DataEstadia * ReservaGrupal::ObtenerEstadiaAbAccRes(std::string EmailUsuario){ 
    Estadia *esta;
    IDictionary * estadiasgr;
    for(IIterator *it = estadias->getIterator();it->hasCurrent();it->next()){
        auto const esta = dynamic_cast<Estadia*>(it->getCurrent());
        if(strcmp(EmailUsuario.c_str(),esta->getEmailHuespedEstadia().c_str()) == 0){
            return new DataEstadia(esta->getCodigoEstadia(),esta->getFechaEntrada(),nullptr,esta->getPromo());
        }{
            //mensajito excepcion
        } 
    } 
    return nullptr;
}

DataEstadia * ReservaGrupal::FinEstadia(int CodigoEstadia, DTFecha *FechaCheckOut){
    IKey * ik = new Integer(CodigoEstadia);
    ICollectible * ic = this->estadias->find(ik);
    if(ic != nullptr){
        Estadia * est = dynamic_cast<Estadia*>(ic);
        if(est->getFechaSalida() == nullptr){
            est->setFechaSalida(FechaCheckOut);
            
        }else{ //mensajito

        }
    }else{ //mensajito
    
    }
    return nullptr;
}

//COnsulta Estadia
IDictionary * ReservaGrupal::ConseguirDataEstadiaBasicaReserva(){
    Estadia *e;
    IDictionary * databasica = new OrderedDictionary();
    for(IIterator * it = this->estadias->getIterator();it->hasCurrent();it->next()){
        e = dynamic_cast<Estadia*>(it->getCurrent());
        IKey * ik = new Integer(e->getCodigoEstadia());
        e->getDataEstadia();
        databasica->add(ik,e);
    }
    return databasica;
}

DataEstadiaExtra * ReservaGrupal::ConseguirDataEstadiaExtraReserva(int CodigoEstadia){
    DataEstadiaExtra * dteg;
    IKey * ik = new Integer(CodigoEstadia);
    Estadia * esta;
    esta = dynamic_cast<Estadia*>(estadias->find(ik));
    if(esta){
        dteg = new DataEstadiaExtra(esta->getCodigoEstadia(),esta->getFechaEntrada(),esta->getFechaSalida(),esta->getPromo(),esta->getEmailHuespedEstadia());
    }
    return dteg;
}

DataCalificacion * ReservaGrupal::ObtenerCalificacionAccResG(int CodigoEstadia){
    IKey * ik = new Integer(CodigoEstadia);
    Estadia * estad;
    estad = dynamic_cast<Estadia*>(estadias->find(ik)); // borre auto const
    if(estad){
        return estad->getCalificacionEst();
    }
    return nullptr;
}

//ComentarCalificacion - ObtenerReservas SinRespuesta
IDictionary * ReservaGrupal::ObtenerCalificacionesSinRAccResG(){
    IDictionary * datacale = new OrderedDictionary() ;
    for(IIterator * it = this->estadias->getIterator();it->hasCurrent();it->next()){
        Estadia * esta;
        esta = dynamic_cast<Estadia*>(it->getCurrent());
        if(esta){
            DataCalificacionExtra * dtce = new DataCalificacionExtra(esta->getCalificacionEst()->getCalifificacion(), esta->getCalificacionEst()->getComentarios(),esta->getCodigoEstadia());
            IKey * ik = new Integer(esta->getCodigoEstadia());
            datacale->add(ik,dtce);
        }
    }
    return datacale;
}

void ReservaGrupal::AgregarComentarioCalificacionAccResG(int CodigoEstadia, std::string comentario){
    Estadia * esta;
    IKey * ike = new Integer(CodigoEstadia);
    if(esta = dynamic_cast<Estadia*>(this->estadias->find(ike))){
        esta->AgregarComentarioCalificacionAccEst(comentario);
    }
     
}

//ico
void ReservaGrupal::addRG(IKey *k, ICollectible *val){
    this->huespedes->add(k, val);
};

bool ReservaGrupal::memberRG(IKey *k){
    return this->huespedes->member(k);
};

void ReservaGrupal::removeRG(IKey *k){
    this->huespedes->remove(k);
};

ICollectible* ReservaGrupal::findRG(IKey *k){
    return this->huespedes->find(k);
};

bool ReservaGrupal::isEmptyRG(){
    return this->huespedes->isEmpty();
};

int ReservaGrupal::getSizeRG(){
    return this->huespedes->getSize();
}

IIterator * ReservaGrupal::getIteratorRG(){
    return this->huespedes->getIterator();
}

void ReservaGrupal::EliminarReservaAccres(){
    Estadia * esta;
    for(IIterator *it = estadias->getIterator();it->hasCurrent();it->next()){
        esta = dynamic_cast<Estadia*>(it->getCurrent());
        IKey * ik = new Integer(esta->getCodigoEstadia());
        esta->eliminarCalificacion();
        this->estadias->remove(ik);
    }
    this->habitacion = nullptr; //forget
}
