#include "Calificacion.h"

Calificacion::Calificacion(){}

Calificacion::Calificacion(int calificacion, std::string comentarios){
	this->AgregarComentario(comentarios);
	this->Puntaje = calificacion;

}

Calificacion::~Calificacion(){
	for(IIterator *it = Comentarios->getIterator();it->hasCurrent();it->next()){
		String *str = dynamic_cast<String*>(it->getCurrent());
		this->Comentarios->remove(str);
		delete str;
	}	
}

int Calificacion::getCalificacion(){
	return this->Puntaje;
}
ICollection* Calificacion::getComentarios(){
	return this->Comentarios;
}

void Calificacion::setCalificacion(int cal){

	this->Puntaje = cal;

}

void Calificacion::setComentarios(ICollection* com){
	this->Comentarios = com;
}
DataCalificacion* Calificacion::getData(){
	return new DataCalificacion (this->getCalificacion(),this->getComentarios());
}

void Calificacion::AgregarComentario(std::string comentario){
	this->Comentarios->add(new String(comentario));
}



/*
	
	int GetCalificacion()
	ObtenerCalificacionAccederCalificacion ()
	AgregarComentarioAccederCalificacion(Respuesta string)	
*/