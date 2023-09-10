#include "Estadia.h"
#include "../../Datatypes/Datatypes.h"


Estadia::Estadia(){}


Estadia::Estadia(int CodigoEstadia,DTFecha *FechaEntrada, std::string Promo){
	this->codigoEstadia = CodigoEstadia;
	this->fechaEntrada = FechaEntrada;
	//this->fechaSalida = FechaSalida;
	this->promo  = Promo;
}

Estadia::~Estadia(){}

//getters
int Estadia::getCodigoEstadia(){
	return this->codigoEstadia;
}
DTFecha * Estadia::getFechaEntrada(){
	return this->fechaEntrada;
}
DTFecha * Estadia::getFechaSalida(){
	return this->fechaSalida;
}
std::string Estadia::getPromo(){
	return this->promo;
}
//setters

void Estadia::setCodigoEstadia(int CodigoEstadia){
	this->codigoEstadia = CodigoEstadia;
}
void Estadia::setFechaEntrada(DTFecha *FechaEntrada){
	this->fechaEntrada = FechaEntrada;
}
void Estadia::setFechaSalida(DTFecha *FechaSalida){
	this->fechaSalida = FechaSalida;
}
void Estadia::setPromo(std::string Promo){
	this->promo = Promo;
}


std::string Estadia::getEmailHuespedEstadia(){
	return this->HuespedesEst->getEmail();
}

DataEstadia * Estadia::getDataEstadia(){
	return new DataEstadia(this->getCodigoEstadia(),this->getFechaEntrada(),this->getFechaSalida(),this->getPromo());
}

//eliminar Calificacion
void Estadia::eliminarCalificacion(){
	if(this->calificacion){
		delete this->calificacion;
	}
}

DataCalificacion * Estadia::getCalificacionEst(){
	DataCalificacion * dtc;
	return dtc = new DataCalificacion(calificacion->getCalificacion(),calificacion->getComentarios());
}

//COmentar calificacion / obtener
//No va me parece segun lo que hice
/*
IDictionary * Estadia::ObtenerCalificacionSinRAccEst(){
	
	DataCalificacion * dtc;
	if(this->calificacion->getComentarios() != nullptr){
		//Supongo que va a asi la movida
		 dtc = this->getCalificacionEst();
		
		// = new DataCalificacion(dynamic_cast<DataCalificacion*>(this->calificacion->getCalificacion(),dynamic_cast<DataCalificacion*>(this->calificacion->getComentarios())));
	}	
}
*/

//Comentar calificacion / comentar
void Estadia::AgregarComentarioCalificacionAccEst(std::string Comentario){
	this->calificacion->AgregarComentario(Comentario);
}

/*

	DataEstadiaExtra GetDataExtra(EmailUsuario)
	int ObtenerCal()

	DataCalificacion ObtenerCalificaciones() 
	Set(DataCalificacion) ObtenerCalificacionAccederEstadia () 
	AgregarComentarioAccederEstadia(CodigoCalficacion int, Respuesta string)
	
	ConfirmarEliminarReservaAccederEstadia()
	ObtenerEstadiaAbAccEst()
	ObtenerEstadiasFinalizadasAccEst()
	CalificarEstadiaAccEst(Califica int, Comentario string)
	FinalizarEstadiaAccEst(FechaCheckOut DataFecha)
	CancelarCalificaciónAccEst()
*/