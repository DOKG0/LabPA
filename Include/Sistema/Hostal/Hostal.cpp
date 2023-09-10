#include "Hostal.h"
#include "../../ico.h"
#include "../../Datatypes/Datatypes.h"
#include "Reserva.h"
#include "ReservaGrupal.h"
#include "ReservaIndividual.h"
#include "../Usuario/Huesped.h"
#include "../ManejadorHostal.h"
#include "Estadia.h"
#include "../ManejadorUsuario.h"
#include "../Usuario/Huesped.h"
#include "../ControladorUsuario.h"
#include "../ControladorHostal.h"

static ControllerHostal * host = ControllerHostal::getInstance();
static ControllerUsuario * user = ControllerUsuario::getInstance();

Hostal::Hostal(std::string nombre, std::string direccion, std::string telefono){
  this->Nombre = nombre;
  this->Direccion = direccion;
  this->Telefono = telefono;
  this->contadorReserva = 1;
  this->Habitaciones = new OrderedDictionary();
  this->Reservas = new OrderedDictionary();
};

Hostal::~Hostal(){
  for (IIterator* it = this->Habitaciones->getIterator(); it->hasCurrent(); it->next()){
    OrderedKey* llave = new Integer(((Habitacion*)it->getCurrent())->getNumeroHab());
    this->eliminarHabitacion(((Habitacion*)it->getCurrent()));
  }

  for (IIterator* it = this->Reservas->getIterator(); it->hasCurrent(); it->next()){
    OrderedKey* llave = new Integer(((Reserva*)it->getCurrent())->getCodigo());
    this->eliminarReserva(((Reserva*)it->getCurrent()));
  }
};

void Hostal::setNombre(std::string nombre){
  this->Nombre = nombre;
}; 
void Hostal::setDireccion(std::string direccion){
  this->Direccion = direccion;
};
void Hostal::setTelefono(std::string telefono){
  this->Telefono = telefono;
};

std::string Hostal::getNombre(){
  return this->Nombre;
};
std::string Hostal::getDireccion(){
  return this->Direccion;
};
std::string Hostal::getTelefono(){
  return this->Telefono;
};

ICollection* Hostal::obtenerHabs(){
  //
  return nullptr;
};

void Hostal::agregarHabitacion(Habitacion* h){
  OrderedKey* llave = new Integer(h->getNumeroHab());
  this->Habitaciones->add(llave,h);
};

void Hostal::eliminarHabitacion(Habitacion* h){
  OrderedKey* llave = new Integer(h->getNumeroHab());
  this->Habitaciones->remove(llave);
};

void Hostal::agregarReserva(Reserva* r){

};

void Hostal::eliminarReserva(Reserva* r){
  //Eliminar cosas de reserva
  OrderedKey* llave = new Integer(r->getCodigo());
  this->Reservas->remove(llave);
};

DataHostalLight* Hostal::getDataL(){
    return new DataHostalLight(this->getNombre(), this->getDireccion(), this->getTelefono());

}

DataHostal* Hostal::getDataPrueba(){
    return new DataHostal(this->Nombre);

}

DataHostalLight * Hostal::getDatosHostal(){

  return new DataHostalLight(this->getNombre(),this->getDireccion(),this->getTelefono());
}

//******************************Mostrar*************************

IDictionary *Hostal::getDatosHostalprueba(){

  IDictionary * hostal = new OrderedDictionary;
  IIterator * it = host->hostales->getIterator();
  DataHostal * dth;
  OrderedKey * ik;
  for(it;it->hasCurrent();it->next()){
    dth = dynamic_cast<Hostal*>(it->getCurrent())->getDataPrueba();
    ik = new String(dth->getNombre());
    hostal->add(ik,dth);
  }
  return hostal;
}




void Hostal::AltaHabitacion(int numero, float precio, int capacidad){
  Habitacion * hab = new Habitacion(numero,precio,capacidad);
  OrderedKey *ik = new Integer(hab->getNumeroHab());
}

IDictionary * Hostal::getReservas(std::string EmailHuesped){
  Reserva * rg;
  Reserva *ri;
  OrderedKey * ik = new String(EmailHuesped);
  IDictionary * reservitas;
  ICollectible * ic = user->huespedes->find(ik);
  if(ic != nullptr){
    for(IIterator *it = Reservas->getIterator();it->hasCurrent();it->next()){
      if(auto const rg = dynamic_cast<ReservaGrupal*>(it->getCurrent())){
        if(rg->ExisteEmailReservaGR(EmailHuesped) == true){
          if(rg->getEstadoReserva() != Cancelada){
          DataReservaLight * dtrgl = new DataReservaLight(rg->getCodigo(),rg->getFechaCheckIn(),rg->getFechaCheckOut(),rg->getEstadoReserva());
          OrderedKey * ikrg = new Integer(rg->getCodigo());
          reservitas->add(ikrg,dtrgl);
          delete ik;
          return reservitas;
          }
        }
      }else{
        auto const ri = dynamic_cast<ReservaIndividual*>(it->getCurrent());
        if(ri->ExisteEmailReservaI(EmailHuesped) == true){
          if(ri->getEstadoReserva() != Cancelada){
          DataReservaLight *dtril = new DataReservaLight(ri->getCodigo(),ri->getFechaCheckIn(),ri->getFechaCheckOut(),ri->getEstadoReserva());
          OrderedKey * ikri = new Integer(ri->getCodigo());
          reservitas->add(ikri,dtril);
          delete ik;
          return reservitas;
          }
        }
        throw std::invalid_argument("No existe Huesped en la lista de reservas.");
      }
    }
  }
  throw std::invalid_argument("No existe Huesped o Email Ingresado es incorrecto");
}


//Devuelve un DataHostal con sus respectivas colecciones de reservas y habitaciones
DataHostal* Hostal::getdataHostal(){
  Reserva * e;
  Reserva * i;
  IDictionary * Chab = new OrderedDictionary();
  IDictionary * CRes = new OrderedDictionary();
  //Calificacion *c;

  //obtengo la coleccion de habitaciones
  for(IIterator *it = Habitaciones->getIterator();it->hasCurrent();it->next()){
    Habitacion *h = (dynamic_cast<Habitacion*>(it->getCurrent()));
    DataHabitacion * hab = new DataHabitacion(dynamic_cast<Habitacion*>(it->getCurrent())->getNumeroHab(),dynamic_cast<Habitacion*>(it->getCurrent())->getPrecio(),dynamic_cast<Habitacion*>(it->getCurrent())->getCapacidad());
    OrderedKey *ik = new Integer(hab->getNumero());
    Chab->add(ik,hab);

  }
  //obtengo la coleccion de reservas
  for(IIterator *it = Reservas->getIterator();it->hasCurrent();it->next()){
    if(auto const e = dynamic_cast<ReservaGrupal*>(it->getCurrent())){
      //ReservaGrupal
      for(IIterator *it = e->getIteratorRG();it->hasCurrent();it->next()){
        DataReservaLight * dtrl = new DataReservaLight(dynamic_cast<Reserva*>(it->getCurrent())->getCodigo(),dynamic_cast<Reserva*>(it->getCurrent())->getFechaCheckIn(),dynamic_cast<Reserva*>(it->getCurrent())->getFechaCheckOut(),dynamic_cast<Reserva*>(it->getCurrent())->getEstadoReserva());
        OrderedKey * ik = new Integer(dtrl->getCodigo());
        CRes->add(ik,dtrl);
      }
    }else{
      //ReservaIndividual
      auto const i = dynamic_cast<ReservaIndividual*>(it->getCurrent());
      DataReservaLight * dtrl = new DataReservaLight(i->getCodigo(),i->getFechaCheckIn(),i->getFechaCheckOut(),i->getEstadoReserva());
      OrderedKey * ik = new Integer(dtrl->getCodigo());
      CRes->add(ik,dtrl);
    }
  }
  return new DataHostal(this->getNombre(),this->getDireccion(),this->getTelefono(),Chab,CRes);
};


//CreaEstadia
void Hostal::CrearEstadiaH(int codigoReserva,DTFecha *FechaCheckIn, std::string Promo){
  OrderedKey * ik = new Integer(codigoReserva);
  Reserva *resg;
  Reserva *resi;
  ICollectible * ic = this->Reservas->find(ik);
  if(auto const resg = dynamic_cast<ReservaGrupal*>(ic)){
    resg->CrearEstadiaRG(FechaCheckIn,Promo);
    if(resg->getEstadoReserva() == Abierta){
      resg->setEstadoReserva(Cerrada);
    }
  }else{
    auto const resi = dynamic_cast<ReservaIndividual*>(ic);
    resi->CrearEstadiaRI(FechaCheckIn,Promo);
    if(resg->getEstadoReserva() == Abierta){
      resg->setEstadoReserva(Cerrada);
    }
  }
}

//FinlizarEstadia - Obtiene la estadia del huesped
IDictionary * Hostal::ObtenerEstadiasABHostal(std::string EmailHuesped){
  Reserva * res;
  Reserva * resi;
  IDictionary * estadiascolec = new OrderedDictionary();
  for(IIterator * it = Reservas->getIterator();it->hasCurrent();it->next()){
    if(auto const res = dynamic_cast<ReservaGrupal*>(it->getCurrent())){
      if(res->getEstadoReserva() == Cerrada){
        DataEstadia * dter = res->ObtenerEstadiaAbAccRes(EmailHuesped);
        dter->getCodigoEstadia();
        OrderedKey * ik = new Integer(dter->getCodigoEstadia());
        estadiascolec->add(ik,dter);
        //
      }
    }else{
      auto const resi = dynamic_cast<ReservaIndividual*>(it->getCurrent());
      if(resi->getEstadoReserva() == Cerrada){
        DataEstadia * dtei = resi->ObtenerEstadiaAbAccRes(EmailHuesped);
        dtei->getCodigoEstadia();
        OrderedKey * ik = new Integer(dtei->getCodigoEstadia());
         estadiascolec->add(ik,dtei);
         
      }
    }
  }
  return estadiascolec;
}

void Hostal::FinalizarEstadia(int CodigoEstadia, int CodigoReserva, DTFecha *FechaCheckOut){
  OrderedKey * ik = new Integer(CodigoReserva);
  ICollectible * ic = this->Reservas->find(ik);
  Reserva * resg;
  Reserva * resi;
  Estadia * esta;
  if(ic != nullptr){
    if(auto const resg = dynamic_cast<ReservaGrupal*>(ic)){
      resg->FinEstadia(CodigoEstadia, FechaCheckOut);
    }else{
      auto const resi = dynamic_cast<ReservaIndividual*>(ic);
      resi->FinEstadiaI(CodigoEstadia,FechaCheckOut);
    }
  }
}
//en hostal la funcion deberia:
    //encontrar la reserva x el codigo
    //y despues para esa reserva busca estadia x codigo estadia //res gruapal find
    //set fecha salida fechacheck out a la esta estadia



void Hostal::EliminarReservaAccHost(int CodigoReserva){
  OrderedKey * ik = new Integer(CodigoReserva);
  Reserva * rg;
  Reserva * ri;
  ICollectible * ic = Reservas->find(ik);
  if(ic!= nullptr){
    if(auto const rg = dynamic_cast<ReservaGrupal*>(ic)){
      rg->EliminarReservaAccres();
      eliminarReserva((Reserva*)rg);
    }else{
      auto const ri = dynamic_cast<ReservaIndividual*>(ic);
      ri->EliminarReservaAccres();
      eliminarReserva((Reserva*)ri);
    }

  }
}



//Consulta Estadia
IDictionary * Hostal::ConseguirDataEstadiaBasicaHost(){
  Reserva * r;
  Reserva * ri;
  DataEstadia * dteg;
  DataEstadia * dtea;
  IDictionary * databasica = new OrderedDictionary();
  IDictionary * grupal = new OrderedDictionary();
  for(IIterator * it = this->Reservas->getIterator();it->hasCurrent();it->next()){
    if(auto const r = dynamic_cast<ReservaGrupal*>(it->getCurrent())){
      dtea = new DataEstadia(dynamic_cast<DataEstadia*>(r->ConseguirDataEstadiaBasicaReserva())->getCodigoEstadia(), dynamic_cast<DataEstadia*>(r->ConseguirDataEstadiaBasicaReserva())->getFechaEntrada(), dynamic_cast<DataEstadia*>(r->ConseguirDataEstadiaBasicaReserva())->getFechaSalida(), dynamic_cast<DataEstadia*>(r->ConseguirDataEstadiaBasicaReserva())->getPromo(), r->getCodigo());
      grupal = r->ConseguirDataEstadiaBasicaReserva();
      for(IIterator * itg = grupal->getIterator();itg->hasCurrent();itg->next()){
        dteg = dynamic_cast<DataEstadia*>(it->getCurrent());
        OrderedKey * ik = new Integer(dteg->getCodigoEstadia());
        databasica->add(ik,dtea);
      }
    }else{
      auto const ri = dynamic_cast<ReservaIndividual*>(it->getCurrent());
      DataEstadia * dtei = ri->ConseguirDataEstadiaBasicaReserva();
      OrderedKey * ik = new Integer(dtei->getCodigoEstadia());
      databasica->add(ik,dtei);
    }
  }
  return databasica;
}

DataEstadiaExtra * Hostal::ConseguirDataEstadiaExtraHost(int CodigoReserva, int CodigoEstadia){
  OrderedKey * ik = new Integer(CodigoReserva);
  Reserva * r;
  DataEstadiaExtra * dth;
  if(auto const r = dynamic_cast<ReservaGrupal*>(this->Reservas->find(ik))){
    dth = new DataEstadiaExtra(r->ConseguirDataEstadiaExtraReserva(CodigoEstadia)->getCodigoEstadia(), r->ConseguirDataEstadiaExtraReserva(CodigoEstadia)->getFechaEntrada(), r->ConseguirDataEstadiaExtraReserva(CodigoEstadia)->getFechaSalida(), r->ConseguirDataEstadiaExtraReserva(CodigoEstadia)->getPromo(), r->ConseguirDataEstadiaExtraReserva(CodigoEstadia)->getEmailHuesped(), r->getNumHabitacion(),r->getCodigo()); 
  }
  return dth;
}

DataReservaLight * Hostal::ObtenerDataReserva(int CodigoReserva){
  OrderedKey * ik = new Integer(CodigoReserva);
  Reserva * r;
  DataReservaLight * dtr;
  r = dynamic_cast<Reserva*>(Reservas->find(ik));
  if(r){
      return dtr = r->getReserva(); 
  }
  return nullptr;
}

DataCalificacion * Hostal::ObtenerCalificacionAccHost(int CodigoReserva, int CodigoEstadia){
  OrderedKey * ik = new Integer(CodigoReserva);
  Reserva * r;
  Reserva * ri;

  if(auto const r = dynamic_cast<ReservaGrupal*>(this->Reservas->find(ik))){
   return r->ObtenerCalificacionAccResG(CodigoEstadia);
  }else{
    auto const ri = dynamic_cast<ReservaIndividual*>(this->Reservas->find(ik));
    return ri->ObtenerCalificacionAccResI(CodigoEstadia);
  }
}


IDictionary * Hostal::ObtenerCalificacionSinRAccHostal(){
  Reserva * r;
  Reserva * ri;
  DataCalificacionExtra * dtce;
  DataCalificacionExtra * dtce2;
  IDictionary * datacale = new OrderedDictionary();
  for(IIterator * it = this->Reservas->getIterator();it->hasCurrent();it->next()){
    if(auto const r = dynamic_cast<ReservaGrupal*>(it->getCurrent())){
      for(IIterator * itc = r->ObtenerCalificacionesSinRAccResG()->getIterator();it->hasCurrent();it->next()){
        dtce = dynamic_cast<DataCalificacionExtra*>(it->getCurrent());
        dtce2 = new DataCalificacionExtra(dtce->getCalifificacionExtra(),dtce->getComentariosExtra(),dtce->getCodigoEstadiaCalExtra(),dtce->getCodigoReservaCalExtra());
        OrderedKey * ik = new Integer(dtce->getCodigoReservaCalExtra());
        datacale->add(ik,dtce);
      }
    }
  }
  return datacale;
}

void Hostal::AgregarComentarioCalificacionAccHost(int CodigoEstadia, std::string comentario){
  Reserva *r ;
  Reserva *ri;
  for(IIterator * it = this->Reservas->getIterator();it->hasCurrent();it->next()){
    if(auto const r = dynamic_cast<ReservaGrupal*>(it->getCurrent())){
      r->AgregarComentarioCalificacionAccResG(CodigoEstadia,comentario);
    }else{
      auto const ri = dynamic_cast<ReservaIndividual*>(it->getCurrent());
      ri->AgregarComentarioAccResI(CodigoEstadia,comentario);
    }
  }
}

  /*
// devuelve un set con los números de todas las habitaciones
ICollection * Hostal::ObtenerHab(){
	ICollection * setHabitaciones = new List();

	for(IIterator *it = Habitaciones->getIterator(); it->hasCurrent();it->next()){
            Habitacion* h = dynamic_cast<Habitacion*>(it->getCurrent());
            ICollectible * numeroHabitacion = new Integer(h->getNumeroHab());
            setHabitaciones->add(numeroHabitacion);
        }
		
	return setHabitaciones;
}

*/


IDictionary* Hostal::getHabitacionesDisp(DTFecha* FechaCheckIn, DTFecha* FechaCheckOut){
    //Creo una coleccion vacia a retornar despues 
    IDictionary* habitacionesSinReserva = new OrderedDictionary();
     
    // Itero sobra las habitaciones
    for (IIterator *itHab = Habitaciones->getIterator(); itHab->hasCurrent(); itHab->next()) {
        Habitacion* habitacion = dynamic_cast<Habitacion*>(itHab->getCurrent());
		int numHab = habitacion->getNumeroHab();
        bool tieneReserva = false;

        //Itero sobre las reservas
        for (IIterator * itRes =  Reservas->getIterator(); itRes->hasCurrent(); itRes->next()) {
            Reserva* reserva = dynamic_cast<Reserva*>(itRes->getCurrent());
            int numResHab = reserva->getNumHabitacion();
               
			// Llamo a hayReservasParaLaHab, si retorna true hay una reserva, si retorna false, está libre   
            if (numResHab == numHab) {
				      tieneReserva = reserva->hayReservasParaLaHab(FechaCheckIn, FechaCheckOut);
            }
        }
    	// Si no tiene reserva, se agrega al conjunto de habitacionesSinReserva
        if (!tieneReserva) {
          OrderedKey * ik = new Integer(habitacion->getNumeroHab());
          DataHabitacion* dth = new DataHabitacion(habitacion->getNumeroHab(), habitacion->getPrecio(), habitacion->getCapacidad());
          habitacionesSinReserva->add(ik,dth);
        }  
        // El conjunto 'habitacionesSinReserva' contiene los números de las habitaciones sin reserva
        return habitacionesSinReserva;  
    }
    return nullptr;
};

//Verifica que exista una habitacion con numero = numeroHabitacion
bool Hostal::existeHabitacion(int numeroHabitacion){
  OrderedKey* ik = new Integer(numeroHabitacion); //Creo llave
  bool existe = this->Habitaciones->member(ik); //Pregunto si existe
  delete ik; //Elimino llave
  return existe; //Retorno la busqueda
}; 

DataReservaLight* Hostal::crearReserva(int numeroHab, DTFecha* FechaCheckIn, DTFecha* FechaCheckOut){
	OrderedKey* ik = new Integer(numeroHab);
	//Habitacion* habitacion = dynamic_cast<Habitacion*>(Habitaciones->find(ik));
	return new DataReservaLight(this->contadorReserva, FechaCheckIn, FechaCheckOut, Abierta);
}

void Hostal::ConfirmarReserva(Reserva* res){
	OrderedKey * ikRes = new Integer(res->getCodigo());
	this->Reservas->add(ikRes,res);
	this->contadorReserva=this->contadorReserva+1;
}

