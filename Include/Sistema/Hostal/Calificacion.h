#ifndef CALIFICACION_H
#define CALIFICACION_H

#include <string>
#include "../../ico.h" //ICollections
#include "../../Datatypes/Datatypes.h" //datatypes + enum

class Calificacion{
private:


	int Puntaje;

	ICollection* Comentarios;

	

public:
	Calificacion();
	Calificacion(int calificacion, std::string comentarios);
	~Calificacion();
	int getCalificacion();
	ICollection* getComentarios();

	void setCalificacion(int cal);
	void setComentarios (ICollection* com);
	DataCalificacion* getData();

	void AgregarComentario(std::string comentario);


/*
	
	int GetCalificacion()
	ObtenerCalificacionAccederCalificacion ()
	AgregarComentarioAccederCalificacion(Respuesta string)	
*/
};

#endif