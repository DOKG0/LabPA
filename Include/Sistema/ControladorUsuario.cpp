#include "ControladorUsuario.h"
#include "Usuario/Usuario.h"
#include "Usuario/Huesped.h"
#include "Usuario/Empleado.h"
#include "../ico.h" // /ICollection/..
#include "ManejadorUsuario.h"
#include "iostream"
#include "ManejadorHostal.h"
#include "ManejadorUsuario.h"
#include "Excepciones.h"
#include "ControladorHostal.h"

ControllerUsuario *ControllerUsuario::instance = 0;


static ManejadorHostal * manhost = ManejadorHostal::getInstance();


ControllerUsuario::ControllerUsuario(){
    this->empleados = new OrderedDictionary();
    this->huespedes = new OrderedDictionary();
    this->usuarios = new OrderedDictionary();

}

ControllerUsuario::~ControllerUsuario(){

}

ControllerUsuario *ControllerUsuario::getInstance(){
    if (instance == nullptr){
        instance = new ControllerUsuario();
    }
    return instance;
}

bool ControllerUsuario::ingresoData(std::string Email){
    ManejadorUsuario* manuser = ManejadorUsuario::getInstance();
    this->EmailUser = Email;
    IKey * ik = new String(Email);
    //si Existe retorna true
    if(manuser->memberEmpleados(ik)){
        return true;
    }else if(manuser->memberHuespedes(ik)){
        return true;
    }
    return false;
}

IDictionary* ControllerUsuario::ListarEmpleadosDisponibles(std::string NombreHostal){
    IDictionary * listempleados = new OrderedDictionary();

    for(IIterator *it = this->empleados->getIterator();it->hasCurrent();it->next()){
        Empleado* e = dynamic_cast<Empleado*>(it->getCurrent());
        if(e->trabajaEmp(NombreHostal) == false){
            DataEmpleado* dte = e->getdata();
            OrderedKey * ik = new String(dte->getEmailEmp());
            listempleados->add(ik, dte);

        }
    } 
    return listempleados;
};


//LISTAR USUARIOS ANDA************************************LISTAR USUARIOS******************************/
IDictionary* ControllerUsuario::ListaUsuarios() {
    ManejadorUsuario* manuser = ManejadorUsuario::getInstance();
    IIterator* ite;
    IIterator* ith;
    Empleado* e;
    Huesped* h;
    IDictionary* listuser = new OrderedDictionary();
    
    for (ite = this->empleados->getIterator(); ite->hasCurrent(); ite->next()) {
        e = (Empleado*)ite->getCurrent();
        OrderedKey * ok = new String(e->getEmail().c_str());
        listuser->add(ok, e);   
    }
    for (ith = this->huespedes->getIterator(); ith->hasCurrent(); ith->next()) {
        h = (Huesped*)ith->getCurrent();
        OrderedKey * ok = new String(h->getEmail().c_str());
        listuser->add(ok, h);
    }

    return listuser;
}

/********************************************************************************/
//asignar empleado
void ControllerUsuario::ConfirmarEmpleado(std::string NombreHostal, std::string EmailEmpleado, tipoCargo Cargo){
    ControllerHostal * host = ControllerHostal::getInstance();
    OrderedKey * ik  = new String(NombreHostal);
    OrderedKey * ike = new String(EmailEmpleado);
    Hostal * h;
    Empleado * e;
    if(h = dynamic_cast<Hostal*>(host->hostales->find(ik))){
        if(e = dynamic_cast<Empleado*>(this->empleados->find(ike))){
            e->AsignarEmpleado(h,Cargo);
        }
    }
}

//******************************************************ALTA USUAAAARIOOOO**********************************************************
void ControllerUsuario::ConfirmarAltaEmpleado(std::string nombre, std::string Email, std::string password, tipoCargo cargo){
   
    OrderedKey* ik = new String(Email);
    if(this->empleados->member(ik)){
        std::cout << "Ya existe un empleado con ese correo" << std::endl;
    }else{
    Empleado* e = new Empleado(nombre, Email, password, cargo);
    this->empleados->add(ik,e);
    }
};

void ControllerUsuario::ConfirmarAltaHuesped(std::string nombre,std::string Email, std::string password, bool esFinger){

    OrderedKey* ik = new String(Email);
    if(this->huespedes->member(ik)){
    std::cout << "Ya existe un empleado con ese correo" << std::endl;
    }else{
    Huesped* h = new Huesped(nombre, Email, password, esFinger);
    this->huespedes->add(ik, h);
    }
};
//****************************************************************************************************************

//cambiar a datausuario
IDictionary * ControllerUsuario::getDataEmp(std::string NombreHostal){
    
    IDictionary *datosEmpleado = new OrderedDictionary();
    Empleado *e;
    for(IIterator *it = empleados->getIterator(); it->hasCurrent();it->next()){
        e = (Empleado*) it->getCurrent();
        if(!e->trabajaEmp(NombreHostal)){
            DataEmpleado * dte = new DataEmpleado(e->getNombre(),e->getEmail(),e->getCargo());
            IKey * ik = new String(e->getEmail());
            datosEmpleado->add(ik,dte);
        }
    }
    
    return datosEmpleado;
    
   
}

DataHuesped *ControllerUsuario::InformacionHuesped(std::string Email){
    OrderedKey * ikh = new String(Email);

    if(DataHuesped * dth = dynamic_cast<DataHuesped*>(this->huespedes->find(ikh))){
        return new DataHuesped(dth->getNombreHuesped(),dth->getEmailHuesped(),dth->getesFinger());
    }
    throw std::invalid_argument("No hay Huespedes");
}

DataEmpleado *ControllerUsuario::InformacionEmpleado(std::string Email){
    OrderedKey * ike = new String(Email);
 
    if(DataEmpleado* dte = dynamic_cast<DataEmpleado*>(this->empleados->find(ike))){
        return new DataEmpleado(dte->getNombreEmp(),dte->getEmailEmp(),dte->getTipoCargo(),dte->HostalTrabajaData());
    }
    throw std::invalid_argument("No hay Empleados");
}

DataUsuario *ControllerUsuario::InformacionUsuario(std::string Email){
    
    OrderedKey * ik = new String(Email);
    ICollectible * ic = this->empleados->find(ik);
    //Usuario * u;
    bool flag = false;
    if(ic == nullptr){
        ic = this->huespedes->find(ik);
        flag = true;
    }
    if(flag && ic != nullptr){
        std::cout << "entra al datahues";
        return new DataHuesped(dynamic_cast<Huesped*>(ic)->getNombre(),dynamic_cast<Huesped*>(ic)->getEmail(),dynamic_cast<Huesped*>(ic)->getEsFinger());
    }else if(ic != nullptr){
        return new DataEmpleado(dynamic_cast<Empleado*>(ic)->getNombre(),dynamic_cast<Empleado*>(ic)->getEmail(),dynamic_cast<Empleado*>(ic)->getCargo());
    }
    // 
}


bool ControllerUsuario::ExisteUsuario(std::string Email){
    IKey *ik = new String(Email);
    Usuario *u;
    bool existe;
    if(dynamic_cast<Empleado*>(u)){
        return existe = this->empleados->member(ik);
    }else{
        return existe = this->huespedes->member(ik);
    }

}


std::string ControllerUsuario::ObtenerHostalTrabajaEmpleado(std::string EmailEmpleado){
    ManejadorUsuario* manuser = ManejadorUsuario::getInstance();

    IKey * ik = new String(EmailEmpleado);
    Empleado * emp;
    std::string hostaltrab;
    emp = dynamic_cast<Empleado*>(manuser->findEmpleados(ik));
    if(emp){
        hostaltrab = (emp->getHostalTrabaja());
    }else{
        //mensajito crear throw
    }
    return hostaltrab;
}

/*
 //PARA REVISAR
IDictionary * ControllerUsuario::ListarHuespedCtrU(){
    IDictionary * huesped = new OrderedDictionary();
    //////Cambiar
    if(!manuser->isEmptyHuespedes()){
        for(IIterator *it = manuser->getIteratorHuespedes();it->hasCurrent();it->next()){
            Huesped * h = dynamic_cast<Huesped*>(it->getCurrent());
            DataHuesped *dth = new DataHuesped(h->getNombre(),h->getEmail(),h->getEsFinger());
            IKey *ik = new String(h->getEmail());
            huesped->add(ik,dth);
        }
    }
    return huesped;
}

IDictionary* ListarEmpleadosDisponibles(std::string NombreHostal){

    IDictionary * empleados = new OrderedDictionary();

    for(IIterator *it = manuser->getIteratorEmpleados();it->hasCurrent();it->next()){
        Empleado* e = dynamic_cast<Empleado*>(it->getCurrent());
        if(!e->trabajaEmp(NombreHostal)){
            DataEmpleado* dte = e->getdata();
            String* llave=new String(dte->getEmailEmp());
            empleados->add(llave, dte);

        }

    } return empleados;

};




/*  IGNORADA POR EL MOMENTO
DataHuesped ControllerUsuario::SeleccionHuesped(Email string){
    if(!manuser->isEmptyHuespedes()){
        for(IIterator *it = manuser->getIteratorHuespedes();it->hasCurrent();it->next()){
            Huesped * h = dynamic_cast<Huesped*>(it->getCurrent());
            DataHuesped* huesped = new DataHuesped(h->get)
        }
    }
}
*/