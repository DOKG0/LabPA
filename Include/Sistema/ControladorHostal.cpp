#include "ControladorHostal.h"

ControllerHostal * ControllerHostal::Instance = nullptr;



ControllerHostal::ControllerHostal(){
    this->hostales = new OrderedDictionary();
}

ControllerHostal::~ControllerHostal(){
}

ControllerHostal * ControllerHostal::getInstance(){
    if (Instance == nullptr){
        Instance = new ControllerHostal();
    }
    return Instance;
}



bool ControllerHostal::ExisteHabitacion(int numero){
    return false;
};


static ManejadorHostal * manhost = ManejadorHostal::getInstance();


//PENDIENTE DE REVISION
IDictionary * ControllerHostal::ListarHostal(){
    /*
    // Obtengo la colección total de hostales
    ICollection* hostales = this->ObtenerHostales();

    // Creo una colección vacía
    IDictionary* setDeHostales = new OrderedDictionary();

    // Itero sobre cada hostal en la colección
    for (IIterator* it = hostales->getIterator(); it->hasCurrent(); it->next()) {
        Hostal* hostal = dynamic_cast<Hostal*>(it->getCurrent());

        // Obtengo un objeto DataHostalLight utilizando la función getDataL() del hostal actual
        DataHostalLight* dataHostal = hostal->getDataL();
        // Creo una IKey con el nombre del hostal
        IKey *ik = new String(hostal->getNombre());
        // Agrego el objeto dataHostal con su respectiva IKey al conjunto a retornar
        setDeHostales->add(ik,dataHostal);

    }

    // Libero memoria borrando la colección total previamente obtenida
    delete hostales;
    // Retorno la colección ordenada de hostales
    return setDeHostales;
    */
}


IDictionary* ControllerHostal::ListarHabitacionDisponible(string nombreHostal, DTFecha *FechaCheckIn, DTFecha *FechaCheckOut ){
    // Recuerdo las variables en el controlador
    this->NombreHostal = nombreHostal;
    this->CheckInRes = FechaCheckIn;
    this->CheckOutRes = FechaCheckOut;
    // Encuentro el hostal
    IKey * ik = new String(nombreHostal);
    Hostal * h = (Hostal*)manhost->find(ik);
    // getHabitacionesDisp retorna un IDictionary con los datos de las habitaciones disponibles para las fechas pasadas por parámetro
    return h->getHabitacionesDisp(FechaCheckIn, FechaCheckOut);
}

//Obtener Hostal
//************************************************MOSTRAR********************************************************
IDictionary * ControllerHostal::ObtenerHostales(){
    IDictionary * lishost = new OrderedDictionary();
    IIterator * it;
    for(it = this->hostales->getIterator(); it->hasCurrent();it->next()){
        Hostal * h = (Hostal*)it->getCurrent();
        OrderedKey * ik = new String(h->getNombre().c_str());
        lishost->add(ik,h);
    }
    return lishost;
}
    


///////~Alta Habitacion//////////////
void ControllerHostal::ConfirmarAltaHabitacion(float precio, int capacidad){
    OrderedKey *ik = new String(this->NombreHostal);
    Hostal *h = (Hostal*)this->hostales->find(ik);
    h->AltaHabitacion(this->NumeroHabitacion,precio,capacidad);
}

//Verifica si existe la habitacion
bool ControllerHostal::ingresoDataHab(int numero, std::string nombreHostal){
    
    if (numero < 1){ //Control que numero no sea < 1 (0 o negativo)
        throw std::invalid_argument("El valor de numero habitacion no puede ser menor a 1");
    }

    OrderedKey * llave = new String(nombreHostal); //Encuentro hostal
    this->NombreHostal = nombreHostal; //Guardo en memoria
    Hostal* host = (Hostal*)this->hostales->find(llave); //Busco hostal
    bool existe = host->existeHabitacion(numero);

    if (existe){
        throw Duplicado("La habitacion ya existe para el hostal seleccionado");
    }
    
    this->NumeroHabitacion = numero; //Guardo en memoria si no existe
    return !existe;
}
///////Fin Alta Habitacion//////////////

//**************************************************************************************
//Alta Hostal
void ControllerHostal::altaHostal(std::string nombreHostal, std::string direccion, std::string telefono){
    OrderedKey * ik = new String(nombreHostal);
    if(this->hostales->member(ik)){
        std::cout << "Hostal ya existe";
    }else{
    Hostal* h = new Hostal(nombreHostal, direccion, telefono);
    this->hostales->add(ik, h);
    this->NombreHostal = nombreHostal;
    }
};
//**************************************************************************************
//Consulta top 3 hostales
ICollection* ControllerHostal::Top3Hostales(){
    ICollection* top3 = new List();
    for (IIterator* it = manhost->getIterator(); it->hasCurrent(); it->next()){
        Hostal* h = (Hostal*)it->getCurrent(); 
        //Fijarse top 3
    }
    return nullptr;

};
//**************************************************************************************
//Consulta Reserva
DataReserva * ControllerHostal::ObtenerReservasHostal(std::string NombreHostal, int CodigoReserva){
    IKey * ik = new String(NombreHostal);
    ICollectible *ic = manhost->find(ik);
    if(ic != nullptr){
        //Ob; tenerReserva(CodigoReserva)//algo asi
    }
    return nullptr;
};
//**************************************************************************************

//**************************************************************************************
//ConsultaHostal
DataHostal * ControllerHostal::InformacionHostal(std::string NombreHostal){
    IKey *ik = new String(NombreHostal);
    Hostal *h = dynamic_cast<Hostal*>(manhost->find(ik));
    return h->getdataHostal();  
};
//**************************************************************************************
//RegistrarEstadia
IDictionary * ControllerHostal::ObtenerReservas(std::string NombreHostal, std::string EmailHuesped){
    IKey * ik = new String(NombreHostal);
    ICollectible * ic = manhost->find(ik);
    if(ic != nullptr){
        Hostal *h = dynamic_cast<Hostal*>(h);
        return h->getReservas(EmailHuesped);
    }
    return nullptr;
}

void ControllerHostal::CrearCheckIn(std::string NombreHostal,int codigoReserva, DTFecha *FechaCheckin,std::string Promo){
    IKey * ik = new String(NombreHostal);
    ICollectible * ic = manhost->find(ik);
    Hostal *h;
    if(ic != nullptr){
        auto const h = dynamic_cast<Hostal*>(ic);
        h->CrearEstadiaH(codigoReserva,FechaCheckin,Promo);
    }
}
//**************************************************************************************
//Finalizar Estadia - obtener estadia
DataEstadia * ControllerHostal::ObtengoEstadiasAb(std::string NombreHostal, std::string EmailHuesped){
    IKey * ik = new String(NombreHostal);
    ICollectible * ich = manhost->find(ik);
    Hostal *h;
    if(ich != nullptr){
        h = dynamic_cast<Hostal*>(ich);
        this->NombreHostal = NombreHostal;
        this->EmailUsuario = EmailHuesped;
        h->ObtenerEstadiasABHostal(EmailHuesped);
    }
    return nullptr;
};

void ControllerHostal::FinalizarEstadia(int CodigoEstadia, int CodigoReserva, DTFecha *FechaCheckOut){
    IKey * ik = new String(this->NombreHostal);
    ICollectible * ic = manhost->find(ik);
    Hostal * h = dynamic_cast<Hostal*>(ic);
    h->FinalizarEstadia(CodigoEstadia,CodigoReserva,FechaCheckOut);
}








DataReservaLight * ControllerHostal::RealizarReserva(int numeroHabitacion){
    IKey * ik = new String(this->NombreHostal);
    Hostal * hostal = dynamic_cast<Hostal*>(manhost->find(ik));
    DataReservaLight* nuevaRes = hostal->crearReserva(numeroHabitacion, this->CheckInRes, this->CheckOutRes);
    //this->reserva = nuevaRes;
    //DataReservaLight* dataNuevaRes = nuevaRes->getReserva();
    return nuevaRes;
}

void ControllerHostal::ConfirmarRealizarReserva(){
    IKey * ikHostal = new String(this->NombreHostal);
    Hostal * hostal = dynamic_cast<Hostal*>(manhost->find(ikHostal));
    hostal->ConfirmarReserva(this->reserva);
}

void ControllerHostal::CancelarRealizarReserva(){
    IKey * ikHostal = new String(this->NombreHostal);
    Hostal * hostal = dynamic_cast<Hostal*>(manhost->find(ikHostal));
    delete(this->reserva);
}
//eliminar reserva reserva todo para dentro en destructor
void ControllerHostal::EliminarReserva(std::string NombreHostal, int CodigoReserva){
    IKey * ik = new String(NombreHostal);
    ICollectible * ic = manhost->find(ik);
    if(ic != nullptr){
        Hostal * h = dynamic_cast<Hostal*>(ic);
        h->EliminarReservaAccHost(CodigoReserva);    
    }
};

//**************************************************************************************
//COnsultar estadia
IDictionary *ControllerHostal::ObtenerDataEstadiaBasica(std::string NombreHostal){
    IKey * ik = new String(NombreHostal);
    Hostal * h;
    DataEstadia * e;
    IDictionary * dic = new OrderedDictionary();
    h = dynamic_cast<Hostal*>(manhost->find(ik));
    this->CodigoReserva = dynamic_cast<DataEstadiaExtra*>(h->ConseguirDataEstadiaBasicaHost())->getCodigoReserva();
    this->NombreHostal = NombreHostal;
    if(h){
        h->ConseguirDataEstadiaBasicaHost();
        DataEstadia * dte = dynamic_cast<DataEstadia*>(h);
        IKey * ike = new Integer(dte->getCodigoEstadia());
        dic->add(ike,h);
    }
    return dic;
}


DataEstadiaExtra * ControllerHostal::ObtenerDataEstadiaExtra(std::string NombreHostal, int CodigoReserva, int CodigoEstadia){
    IKey * ik = new String(NombreHostal);
    DataEstadiaExtra * dtefin;
    Hostal * h = dynamic_cast<Hostal*>(manhost->find(ik));
    if(h != nullptr){
        dtefin = new DataEstadiaExtra(h->ConseguirDataEstadiaExtraHost(CodigoReserva,CodigoEstadia)->getCodigoEstadia(), h->ConseguirDataEstadiaExtraHost(CodigoReserva,CodigoEstadia)->getFechaEntrada(), h->ConseguirDataEstadiaExtraHost(CodigoReserva,CodigoEstadia)->getFechaSalida(), h->ConseguirDataEstadiaExtraHost(CodigoReserva,CodigoEstadia)->getPromo(), h->ConseguirDataEstadiaExtraHost(CodigoReserva,CodigoEstadia)->getEmailHuesped(), NombreHostal, h->ConseguirDataEstadiaExtraHost(CodigoReserva,CodigoEstadia)->getNumeroHabitacion(), h->ConseguirDataEstadiaExtraHost(CodigoReserva,CodigoEstadia)->getCodigoReserva());
    }
    return dtefin;
}


DataReservaLight * ControllerHostal::ObtenerInfoReserva(std::string NombreHostal, std::string EmailUsuario, int CodigoReserva, int CodigoEstadia){
    IKey * ik = new String(NombreHostal);
    Hostal * h;
    h = dynamic_cast<Hostal*>(manhost->find(ik));
    if(h){    
        return h->ObtenerDataReserva(CodigoReserva);
    }
    return nullptr;
}

DataCalificacion * ControllerHostal::ObtenerCalificacion(std::string NombreHostal, std::string EmailUsuario, int CodigoReserva, int CodigoEstadia){
    IKey * ik = new String(NombreHostal);
    Hostal * h;
    h = dynamic_cast<Hostal*>(manhost->find(ik));
    if(h){
        return h->ObtenerCalificacionAccHost(CodigoReserva, CodigoEstadia);
    }
    return nullptr;
}
//**************************************************************************************

//Comentar calificacion - obtenerCalifiacionSinRESPUESTA
IDictionary * ControllerHostal::ObtenerCalificacionesSinRespuesta(std::string NombreHostal){
    IKey * ik = new String(NombreHostal);
    Hostal * h;
    DataCalificacionExtra * dtce;
    h = dynamic_cast<Hostal*>(manhost->find(ik));
    if(h){
        dtce = dynamic_cast<DataCalificacionExtra*>(h->ObtenerCalificacionSinRAccHostal());
        this->CodigoEstadia = dtce->getCodigoEstadiaCalExtra();//ni idea si esta bien
        this->CodigoReserva = dtce->getCodigoReservaCalExtra();// si no esta bien esto habria que recorrer para sacar el dato creo
        return h->ObtenerCalificacionSinRAccHostal();   
    }
    return nullptr;
}

//ComentarCalificacin - agregar comentario
void ControllerHostal::AgregarComentarioCalificacion(std::string NombreHostal, int CodigoEstadia, std::string comentario){
    IKey * ikh = new String(NombreHostal);
    Hostal * h;
    h = dynamic_cast<Hostal*>(manhost->find(ikh));
    if(h){

    }
}