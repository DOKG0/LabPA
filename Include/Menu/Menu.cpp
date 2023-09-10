#include <iostream>
#include "Menu.h"
#include <string.h>

bool altaHabitacionConsultaHostal, asignarEmpleado, realizaReserva, 
registrarEstadiaConsultaReservaBajaReserva, finalizarConsultaEstadia, calificarcomentarEstadia, consultaUsuario; 


static Fabrica* fab = Fabrica::getInstance();

static InterfazUsuario * ControladorU = fab->Usuario();
static InterfazHostal * ControladorH = fab->Hostal();

static ControllerUsuario * user = ControllerUsuario::getInstance();
static ControllerHostal * host  = ControllerHostal::getInstance();


//Restringe opciones del menu
void statusMenu(int opcion){

};

//Menu en pantalla
void mostrarMenu(){
    statusMenu(0);
    std::cout << "Elegir la opcion deseada" << std::endl;
    std::cout <<"1 - Alta Usuario" << std::endl;
    std::cout <<"2 - Alta Hostal" << std::endl;
    std::cout <<"3 - Alta Habitacion" << std::endl;
    std::cout <<"4 - Asignar Empleado" << std::endl;
    std::cout <<"5 - Realizar Reserva" << std::endl;
    std::cout <<"6 - Consultar Top 3 Hostales" << std::endl;
    std::cout <<"7 - Registrar Estadia" << std::endl;
    std::cout <<"8 - Finalizar Estadia" << std::endl;
    std::cout <<"9 - Calificar Estadia" << std::endl;
    std::cout <<"10 - Comentar Calificacion" << std::endl;
    std::cout <<"11 - Consulta de Usuario" << std::endl;
    std::cout <<"12 - Consulta de Hostal" << std::endl;
    std::cout <<"13 - Consulta de Reserva" << std::endl;
    std::cout <<"14 - Consulta de Estadia" << std::endl;
    std::cout <<"15 - Baja de Reserva" << std::endl;
    std::cout <<"16 - Modificar Fecha de Sistema" << std::endl;
    std::cout <<"17 - Pre-cargar datos en el Sistema" << std::endl;
    std::cout <<"18 - Salir del sistema" << std::endl;
    std::cout <<"19 - Limpiar" << std::endl;
};

//Pedir opcion menu
int pedirOpcion(){
    int opcion = 0;
    
    while (true){
        mostrarMenu();
        std::cout << "\nIngrese una opcion valida: ";
        std::cin >> opcion;
        limpiarBuffer();
        if (opcion >=1 and opcion <= 19){
            break; //salgo while
            std::cin.clear();
        }
        pausa("El valor ingresado es invalido, por favor ingrese un valor valido.");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("clear");
    };

    return opcion;
};

//Logica alta usuario, interaccion Usuario-Sistema
void altaUsuario() {
    bool valido = false;
    std::string emailuser;
    std::string nombreuser;
    std::string contraseniauser;
    tipoCargo cargo;
    bool esfinger = false;
    std::string fing = "";

    imprimirTitulo(1);

    emailuser = pedirString("el email del usuario");
    nombreuser = pedirString("el nombre del usuario");
    contraseniauser = pedirString("La contrasenia del usuario");

    int opcion;
    std::cout << "";
    std::cout << "1 - Ingresar un Huesped" << std::endl;
    std::cout << "2 - Ingresar un Empleado" << std::endl;
    std::cout << "3 - Salir" << std::endl;
    std::cout << ">... ";
    std::cin >> opcion;

    switch (opcion) {
        case 1:
            system("clear");
            std::cout << "|=============|" << std::endl;
            std::cout << " Alta Huesped." << std::endl;
            std::cout << "|=============|" << std::endl;
            char confirmacion;
            std::cout << "Ingrese si el huesped es finger (s/n)" << std::endl;
            std::cout << ">... ";
            std::cin >> confirmacion;
            confirmacion = std::tolower(confirmacion);
            if (confirmacion == 's') {
                esfinger = true;
                fing = "esfinger";
            } else {
                esfinger = false;
                fing = "No esFinger";
            }
            system("clear");
            std::cout << "Desea confirmar el ingreso de los siguientes datos?(s/n)" << std::endl;
            std::cout << "Nombre: " << nombreuser << std::endl;
            std::cout << "Email: " << emailuser << std::endl;
            std::cout << "Password: " << contraseniauser << std::endl;
            std::cout << "Esfinger?: " << fing << std::endl;
            std::cout << ">... ";
            std::cin >> confirmacion;
            confirmacion = std::tolower(confirmacion);
            if (confirmacion == 's') {
                std::cin.clear();
                std::cin.ignore();
                ControladorU->ConfirmarAltaHuesped(nombreuser, emailuser, contraseniauser, esfinger);
                std::cout << "Ha confirmado el ingreso del huesped, felicitaciones." << std::endl;
            } else {
                std::cout << "Se ha cancelado el alta del empleado" << std::endl;
            }
            break;

        case 2:
            system("clear");
            std::cout << "|=============|" << std::endl;
            std::cout << " Alta Empleado." << std::endl;
            std::cout << "|=============|" << std::endl;

            int tipocarg;
            std::cout << "\n1 - Administracion" << std::endl;
            std::cout << "2 - Recepcion" << std::endl;
            std::cout << "3 - Limpieza" << std::endl;
            std::cout << "4 - Infraestructura" << std::endl;
            std::cout << "5 - No_Empleado\n" << std::endl;
            std::cout << "Ingrese el tipo de cargo que realizara el empleado (1/5)";
            std::cout << ">... ";
            std::cin >> tipocarg;
            
            switch (tipocarg) {
                case 1:
                    cargo = Administracion;
                    break;
                case 2:
                    cargo = Limpieza;
                    break;
                case 3:
                    cargo = Recepcion;
                    break;
                case 4:
                    cargo = Infraestructura;
                    break;
                case 5:
                    cargo = No_Empleado;
                    break;
                default:
                    std::cout << "Opción inválida" << std::endl;
                    break;
            }

            std::cout << "Desea confirmar el ingreso de los siguientes datos?" << std::endl;
            std::cout << "Nombre: " << nombreuser << std::endl;
            std::cout << "Email: " << emailuser << std::endl;
            std::cout << "Password: " << contraseniauser << std::endl;
            std::cout << "CargoEmpleado: " << obtenerNombreCargo(cargo) << std::endl;
            std::cout << "\n>... ";
            std::cin >> confirmacion;
            confirmacion = std::tolower(confirmacion);
            if (confirmacion == 's') {
                ControladorU->ConfirmarAltaEmpleado(nombreuser, emailuser, contraseniauser, cargo);
                std::cout << "Ha confirmado el ingreso del Empleado, felicitaciones." << std::endl;
            } else {
                std::cout << "Se ha cancelado el alta del empleado" << std::endl;

            }
            break;
        default:
            std::cout << "Opción inválida" << std::endl;
            break;
    }
};


//Alta Hostal
void altaHostalMenu(){
    system("clear");
    std::cout << "|=============|" << std::endl;
    std::cout << " Alta Hostal." << std::endl;
    std::cout << "|=============|" << std::endl;
    bool Correcto = false;
    char confirmacion;

    std::string nombreHostal;
    std::string direccion;
    std::string telefono;

    nombreHostal = pedirString("Nombre Hostal");
    direccion = pedirString("Direccion");
    telefono = pedirString("Telefono");

    std::cout << std::endl;
    std::cin.clear();
    std::cout << "Desea confirmar el ingreso de los siguientes datos?(s/n)" << std::endl;
    std::cout << "Nombre Hostal: " << nombreHostal << std::endl;
    std::cout << "Direccion: " << direccion << std::endl;
    std::cout << "Telefono: " << telefono << std::endl;

    std::cin >> confirmacion;
    confirmacion = std::tolower(confirmacion);
    if (confirmacion == 's') {
        ControladorH->altaHostal(nombreHostal, direccion, telefono);;
        pausa("Ha confirmado el ingreso del Hostal, felicitaciones.");
    } else {
        std::cout << "Se ha cancelado el alta del Hostal" << std::endl;

    }
};
 
//Logica alta habitacion, interaccion Usuario-Sistema
void altaHabitacion(){
    system("clear");
    std::cout << "|=============|" << std::endl;
    std::cout << " Alta Habitacion." << std::endl;
    std::cout << "|=============|" << std::endl;
    bool flag = false;
    int elegirHostal, numerohab = 0, capacidadhab = 0;
    float preciohab;
    bool opcionValida = false;
    char confirmacion;
    std::string nombreHostal;
    //Obtengo hostales y los imprimo
    IDictionary * listhostales = new OrderedDictionary();
    listhostales = ControladorH->ObtenerHostales();

    std::cout << "\t**Hostales**" << std::endl;
    std::cout << std::endl;
    if(listhostales->isEmpty()){
    std::cout << "No Hay Hostales\n" << std::endl;
    pausa("Presione enter para volver al menu...");
    return;

    }else{
        IIterator * it;
        for(it = listhostales->getIterator();it->hasCurrent();it->next()){
            Hostal *dth = dynamic_cast<Hostal*>(it->getCurrent());
            std::cout << "===================================" <<std::endl;
            std::cout << "Nombre Hostal: " <<  dth->getNombre() << std::endl;
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
        pausa("Presiona cualquier tecla para continuar");
    }
    ////termina hostales

    //pido nombrehostal
    nombreHostal = pedirString("el nombre del Hostal");

    do{
        //Pido numero de habitacion
        //numerohab = pedirInt("el numero de la nueva habitacion");
        pausa("Presiona cualquier tecla para continuar...");
        std::cout << std::endl;
        std::cout << "Ingresa el numero de la habitacion" << std::endl;
        std::cout << ">...";
        cin >> numerohab;
        //Verifico que sea valido (< 1) y que no exista para el hostal elegido
            

            opcionValida = ControladorH->ingresoDataHab(numerohab, nombreHostal);
            std::cout << "NombreHostal: " + nombreHostal + " NumeroHab: " << numerohab << " Opcionvalida: " << opcionValida << std::endl;


        }while (!opcionValida);
        //Pido precio
        std::cout << std::endl;
        preciohab = pedirFloat("el precio base de la habitacion");

        opcionValida = false;
        do{
            //Pido capacidad
            std::cout << std::endl;
            capacidadhab = pedirInt("la capacidad de la habitacion");

            //Controlo que sea valido (< 1)
            try{
                opcionValida = capacidadValida(capacidadhab);
            }catch(std::invalid_argument inv){
                pausa(inv.what());
                std::cout << "Desea continuar con el proceso de AltaHabitacion?(s/n)" << std::endl;
                std::cout <<">...";
                std::cin >> confirmacion;
                confirmacion = std::tolower(confirmacion);
                if (confirmacion == 'n') {
                    return;
                }
            }
            
        }while (!opcionValida);

        if(opcionValida){
            /*std::cout << "¿Desea confirmar el ingreso de los siguientes datos?" << std::endl;
            std::cout << "Nombre Hostal: " << nombreHostal << std::endl << "Numero de Habitacion: " << numerohab << std::endl << "Precio de la Habitacion: " << preciohab << std::endl
            << "Capacidad de la Habitacion: " << capacidadhab << std::endl;*/
        
            //confirmacion
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << ("¿Desea confirmar el ingreso de los siguientes datos?\nNombre Hostal: " + nombreHostal + "\nNumero de Habitacion: " + 
            to_string(numerohab) + "\nPrecio de la Habitacion: " + to_string(preciohab) + "\nCapacidad de la Habitacion: " + to_string(capacidadhab)) << std::endl;
            std::cout <<">...";
            std::cin >> confirmacion;
            confirmacion = std::tolower(confirmacion);
            if (confirmacion == 'n') {
                return;
            }else{
                ControladorH->ConfirmarAltaHabitacion(preciohab, capacidadhab);
                std::cout << std::endl;
                pausa("Habitacion dada de alta con exito");
                flag = true;
            }
        }//opcion valida
       
        
       
};
//Fin alta hostal


void asignarEmpleadoMain(){
    std::cout << "|==========================|" << std::endl;
    std::cout << " Asignar Empleado a Hostal." << std::endl;
    std::cout << "|==========================|" << std::endl;
    ///////var
    bool seguir = false;
    std::string emailEmpleado;
    tipoCargo cargo;
    std::string nombreHostal;
    ///////
    do{
        //Lista hostales
        IDictionary * listhostales = new OrderedDictionary();
        listhostales = ControladorH->ObtenerHostales();

        std::cout << "\t**Hostales**" << std::endl;
        std::cout << std::endl;
        if(listhostales->isEmpty()){
        std::cout << "No Hay Hostales\n" << std::endl;
        pausa("Presione enter para volver al menu...");
        return;

        }else{
            IIterator * it;
            for(it = listhostales->getIterator();it->hasCurrent();it->next()){
                Hostal *dth = dynamic_cast<Hostal*>(it->getCurrent());
                std::cout << "===================================" <<std::endl;
                std::cout << "Nombre Hostal: " <<  dth->getNombre() << std::endl;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
            pausa("Presiona cualquier tecla para continuar");
        }
        //----------------------------FinlistaHostal----------------------------------

        //Pido Nombre Hostal
        bool flagh = false;
        do{
            nombreHostal = pedirString("el nombre del Hostal");
            OrderedKey * ik = new String(nombreHostal);
            if(host->hostales->member(ik) == false){
                pausa("Ingrese un hostal que exista porfavor");
                std::cout << std::endl;
            }else if(host->hostales->member(ik) == true){
                flagh = true;
            }
        }while(!flagh);
        //----------------------------finpidohostal----------------------------------
        //Lista empleados
        IDictionary * listaEmpleado = new OrderedDictionary();
        listaEmpleado = ControladorU->ListarEmpleadosDisponibles(nombreHostal);
        for(IIterator * ite = listaEmpleado->getIterator();ite->hasCurrent();ite->next()){
            DataEmpleado * e = dynamic_cast<DataEmpleado*>(ite->getCurrent());  

            std::cout << "Nombre Empleado: " << e->getNombreEmp() << std::endl;
            std::cout << "Email Empleado: " << e->getEmailEmp() << std::endl;
        }
        //----------------------------finlistaemppleados----------------------------------
        bool opcionValida = false;

        do{
            std::cout << ("Ingrese el email del empleado a seleccionar") << std::endl;
            std::cout << (">...");
            std::getline(std::cin,emailEmpleado);
            std::cout << ("email: ") << emailEmpleado << std::endl;
            OrderedKey * ik = new String(emailEmpleado);
            if(DataEmpleado * e = dynamic_cast<DataEmpleado*>(listaEmpleado->find(ik))){
                opcionValida = true;
            }
        }while(!opcionValida);

                int tipo;
                std::cout << "\n1 - Administracion" << std::endl;
                std::cout << "2 - Recepcion" << std::endl;
                std::cout << "3 - Limpieza" << std::endl;
                std::cout << "4 - Infraestructura" << std::endl;
                std::cout << "Ingrese el tipo de cargo que realizara el empleado (0/3): ";
                std::cin >> tipo;
                switch (tipo){
                    case 1:
                        cargo = Administracion;
                        break;
                    case 2:
                        cargo = Limpieza;
                        break;
                    case 3:
                        cargo = Recepcion;
                        break;
                    case 4:
                        cargo = Infraestructura;
                        break;
                    default:
                        std::cout << "Opcion invalida" << std::endl;
                        break;
                }
   


        system("clear");
        std::cout << "Desea confirmar el ingreso de los siguientes datos?(s/n)" << std::endl;
        std::cout << "Nombre Hostal -Asignado-: " << nombreHostal << std::endl;
        std::cout << "Email Empleado: " << emailEmpleado << std::endl;
        std::cout << "Cargo -Asignado-: " << cargo << std::endl;
        //confirmar asignacion
        char confirmacion;
        std::cout <<">...";
        std::cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if (confirmacion == 's') {
            ControladorU->ConfirmarEmpleado(nombreHostal,emailEmpleado,cargo);
            std::cout << std::endl;
            pausa("Se ha asignado el empleado exitosamente, felicitaciones");
            
        }else{
            seguir = false;
            pausa("Se ha cancelado el alta del empleado");
            //return;
        }
        //----------------------------finCOnfirmaEMpleado----------------------------------

        //Confirma seguir agregando?
        std::cout << "\n\nDesea seguir Asignando Empleados?(s/n)" << std::endl;
        std::cout << ">...";
        cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if (confirmacion == 's') {
            seguir = true;
            pausa("Presione cualquier tecla para seguir agregando Empleados.");
        }else{
            seguir = false;
            pausa("Presione cualquier tecla para volver al menu...");
            //return;
        }


    }while(seguir == true);
    
};

void realizarReserva(){
    std::cout << "Sin Implementar" << std::endl;
    pausa("Presione enter para continuar...");
};

//Consulta top 3 Hostales
void consultaTop3Hostales(){
    std::cout << "Sin Implementar" << std::endl;
    pausa("Presione enter para continuar...");

    //ICollection* top3 = ControladorH->Top3Hostales();

};


void registrarEstadia(){
    /*
    bool Correcto = false;
    //
    std::string NombreHostal;
    std::string EmailHuesped;
    int CodigoReserva;

    //Lista hostales
    //ICollection * listahostal = ControladorH->ObtenerHostales();
    //pide nombrehostal
    //std::string nombreHostal = imprimirObtengoHostales((List*)listahostal);
    pausa("Hola");
    //
    /*
    for(IIterator * it = ControladorH->MostarHostales()->getIterator(); it->hasCurrent();it->next()){
        
        DataHostal * h;
        h = dynamic_cast<DataHostal*>(it->getCurrent());
        if(h == nullptr){
            std::cout << "Muere aqui no hay hostal" << std::endl;
        }
        std::cout << "NombreHostal: " << h->getNombre() << std::endl;
    }
    std::cout << "Paso el mostrar hostal";
    getchar();

    // while (!Correcto){
    // NombreHostal = pedirString(" Nombre Hostal");
    // Correcto = ControladorU->ingresoData(EmailHuesped);
    // }

    // while (!Correcto){
    // EmailHuesped = pedirString(" email Huesped");
    // Correcto = ControladorU->ingresoData(EmailHuesped);
    // }

    //imprime
    Reserva * r;
    for(IIterator * it = ControladorH->ObtenerReservas(NombreHostal,EmailHuesped)->getIterator();it->hasCurrent();it->next()){
        r = dynamic_cast<Reserva*>(it->getCurrent());
        std::cout << "Codigo Reserva: " << r->getCodigo() << std::endl;
        std::cout << "Fecha CheckIn: " << r->getFechaCheckIn() << std::endl;
        std::cout << "Fecha CheckOut: " << r->getFechaCheckOut() << std::endl;
        std::cout << "Estado Reserva: " << r->getEstadoReserva() << std::endl;
    }
        bool correcto = false;
        while(!correcto){
            CodigoReserva = pedirInt("Ingrese codigo reserva");
            if(CodigoReserva == r->getCodigo()){
                correcto = true;
            }
        }

            static FechaSistema *reloj = FechaSistema::getInstancia();
            std::string promo = "no";

        ControladorH->CrearCheckIn(NombreHostal,CodigoReserva,reloj->getFechaSistema(),promo);
        */
};

void finalizarEstadia(){
/*
    std::string NombreHostal;
    std::string EmailHuesped;

    //Lista hostales
    IDictionary * listahostal = ControladorH->ObtenerHostales();
    //pide string
    std::string nombreHostal = imprimirObtengoHostales((List*)listahostal);

    bool correcto = false;
    while(!correcto){
        EmailHuesped = pedirString("email Huesped");
        if(ControladorU->ingresoData(EmailHuesped) == true){
            correcto = true;
        }
    }
    
    DataEstadia *dte;
    dte = ControladorH->ObtengoEstadiasAb(NombreHostal,EmailHuesped);
    std::cout << "Codigo Estadia: " << dte->getCodigoEstadia() << std::endl;
    std::cout << "Fecha CheckIn: " << dte->getFechaSalida() << std::endl;
    std::cout << "Fecha Checkout: " << dte->getPromo() << std::endl;

   // ControladorH->FinalizarEstadia(dte->getCodigoEstadia(),);

*/
};

void calificarEstadia(){
std::cout << "Sin Implementar" << std::endl;
    pausa("Presione enter para continuar...");
};

void comentarCalificacion(){
std::cout << "Sin Implementar" << std::endl;
    pausa("Presione enter para continuar...");
};


void consultaUsuarioMain(){
    system("clear");
    std::string emailuser;
    std::cout << "|====================|" << std::endl;
    std::cout << "  Lista de usuarios" << std::endl;
    std::cout << "|====================|\n" << std::endl;
    IDictionary * listhuesp = new OrderedDictionary();

    listhuesp = ControladorU->ListaUsuarios();
    if(listhuesp->isEmpty()){
        std::cout << "N/A" << std::endl;
    }else{
        IIterator * ith;
        for(ith = listhuesp->getIterator();ith->hasCurrent();ith->next()){
            if(Empleado* e = dynamic_cast<Empleado*>(ith->getCurrent())){
                std::cout << "Nombre del Empleado: " << e->getNombre() << std::endl;
                std::cout << "Email del Empleado: " << e->getEmail() << std::endl;
                std::cout << "===================================" <<std::endl;
            }else{
                 Huesped * h = dynamic_cast<Huesped*>(ith->getCurrent());
                std::cout << "Nombre del Huesped: " << h->getNombre() << std::endl;
                std::cout << "Email del Huesped: " << h->getEmail() << std::endl;
                std::cout << "===================================" <<std::endl;
            }  
        }
        /*
    char confirmacion;

    std::cout << "Desea consultar informacion de algun usuario?(s/n)" << std::endl;
    std::cout << ">...";
    std::cin >> confirmacion;
    confirmacion = std::tolower(confirmacion);
    if (confirmacion == 's') {
        limpiarBuffer();
        std::cout << "Ingrese el email del usuario" << std::endl;
        std::cout << ">...";
        std::getline(std::cin,emailuser,'\n');
        
          */  
            limpiarBuffer();
            limpiarBuffer();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(DataEmpleado * dte = (DataEmpleado*)ControladorU->InformacionEmpleado(emailuser)){
                std::cout << "Informacion del Empleado\n" << std::endl;
                std::cout << "Nombre del Empleado: " << dte->getNombreEmp() << std::endl;
                std::cout << "Email del Empleado: " << dte->getEmailEmp() << std::endl;
                std::cout << "Hostal donde trabaja: " << dte->HostalTrabajaData()<< std::endl;
                std::cout << "Cargo del Empleado: " << dte->getTipoCargo() << std::endl;
                mostrarError("pasa por el empleado");
            }else{
                DataHuesped * dth = (DataHuesped*)(ControladorU->InformacionHuesped(emailuser));
                std::cout << "Informacion del Huesped\n" << std::endl;
                mostrarError("entra al huesped");
                std::cout << "Nombre del Huesped: " << dth->getNombreHuesped() << std::endl;
                std::cout << "Email del Huesped: " << dth->getEmailHuesped() << std::endl;
                std::cout << "Esfinger?: " << dth->getesFinger() << std::endl;
                mostrarError("luego de esfinger huesped");
            }
    }   

};

void consultaHostal(){
    system("clear");
    IDictionary * listhostales = new OrderedDictionary();
    listhostales = ControladorH->ObtenerHostales();

    std::cout << "|====================|" << std::endl;
    std::cout << "  Consulta de Hostal" << std::endl;
    std::cout << "|====================|\n" << std::endl;


    if(listhostales->isEmpty()){
        std::cout << "N/A" << std::endl;
        
    }else{
        IIterator * it;
        for(it = listhostales->getIterator();it->hasCurrent();it->next()){
            Hostal *dth = dynamic_cast<Hostal*>(it->getCurrent());
            std::cout << "===================================" <<std::endl;
            std::cout << "Nombre Hostal: " <<  dth->getNombre() << std::endl;
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
        pausa("Presiona cualquier tecla para continuar");
    }
};


void consultaReserva(){
std::cout << "Sin Implementar" << std::endl;
    pausa("Presione enter para continuar...");
};

void consultaEstadia(){
std::cout << "Sin Implementar" << std::endl;
    pausa("Presione enter para continuar...");
};

void bajaReserva(){
std::cout << "Sin Implementar" << std::endl;
    pausa("Presione enter para continuar...");
};

void modificarFechaSistema(){
FechaSistema *fechaSistema = FechaSistema::getInstancia();

    int anio;
    bool existe = false;
    int a = 0;
    while (!existe)
    {
        std::cout << "Ingrese el anio: ";
        std::cin >> anio;
        if (anio >= 1900)
        {
            existe = true;
        }
        else
        {
            std::cout << "Error, el anio no es correcto, intentelo nuevamente" << endl;
            std::cout << "Ingresar 1 si quiere intentar de nuevo, si no quiere ingrese 0: ";
            std::cin >> a;
            existe = !(a == 1);
            if (existe)
                break;
        }
    };
    int mes;
    existe = false;
    while (!existe)
    {
        std::cout << "Ingresar mes: ";
        std::cin >> mes;
        if (mes > 0 && mes < 13)
        {
            existe = true;
        }
        else
        {
            std::cout << "Error, el mes no es correcto, intentelo nuevamente" << endl;
            std::cout << "Ingresar 1 si quiere intentar de nuevo, si no quiere ingrese 0: ";
            std::cin >> a;
            existe = !(a == 1);
            if (existe)
                break;
        }
    };

    int dia;
    existe = false;
    while (!existe)
    {
        std::cout << "Ingrese el dia: ";
        std::cin >> dia;
        if (dia > 0 && dia < 32)
        {
            existe = true;
        }
        else
        {
            std::cout << "Error, el dia no es correcto, intentelo nuevamente" << endl;
            std::cout << "Ingresar 1 si quiere intentar de nuevo, si no quiere ingrese 0: ";
            std::cin >> a;
            existe = !(a == 1);
            if (existe)
                break;
        }
    };

    int hora;
    existe = false;
    while (!existe)
    {
        std::cout << "Ingrese la hora: ";
        std::cin >> hora;
        if (hora >= 0 && hora < 24)
        {
            existe = true;
        }
        else
        {
            std::cout << "Error, la hora no es correcta, intentelo nuevamente" << endl;
            std::cout << "Ingresar 1 si quiere intentar de nuevo, si no quiere ingrese 0: ";
            std::cin >> a;
            existe = !(a == 1);
            if (existe)
                break;
        }
    };

    int minuto;
    existe = false;
    while (!existe)
    {
        std::cout << "Ingrese el minuto: ";
        std::cin >> minuto;
        if (minuto >= 0 && minuto < 60)
        {
            existe = true;
        }
        else
        {
            std::cout << "Error, el minuto no es correcto, intentelo nuevamente" << endl;
            std::cout << "Ingresar 1 si quiere intentar de nuevo, si no quiere ingrese 0: ";
            std::cin >> a;
            existe = !(a == 1);
            if (existe)
                break;
        }
    };

    fechaSistema->setFechaSistema(dia, mes, anio, hora, minuto);
    std::cout << "Fecha y Hora ingresada: " << dia << "/" << mes << "/" << anio << " " << hora << ":" << minuto << endl;


};
void cargarDatos(){
    system("clear");
    //////////USUARIO////////////
    std::string nombre;
    std::string email;
    std::string password;
    tipoCargo cargo;
    bool esfinger;
    //////////USUARIO////////////

    //////////HOSTAL////////////
    std::string nomh;
    std::string dirh;
    std::string telh;
    //////////HOSTAL////////////

    int opcion;
    std::cout << "|=============|" << std::endl;
    std::cout << " Cargar Datos." << std::endl;
    std::cout << "|=============|" << std::endl;
    std::cout << std::endl;
    std::cout << "1 - AltaUsuario" << std::endl;
    std::cout << "2 - AltaHostal" << std::endl;
    std::cout << "\n>... ";
    cin >> opcion;
    switch(opcion){
        case 1:
            //Empleado1
            nombre = "Emilia"; email = "emilia@mail.com"; password = "123"; cargo = Recepcion;
            ControladorU->ConfirmarAltaEmpleado(nombre,email,password,cargo);
            nombre.clear(); email.clear(); password.clear();
            //Empleado2
            nombre = "Leonardo"; email = "leo@mail.com"; password = "123"; cargo = Recepcion;
            ControladorU->ConfirmarAltaEmpleado(nombre,email,password,cargo);
            nombre.clear(); email.clear(); password.clear();
            //Empleado3
            nombre = "alina"; email = "alina@mail.com"; password = "123"; cargo = Administracion;
            ControladorU->ConfirmarAltaEmpleado(nombre,email,password,cargo);
            nombre.clear(); email.clear(); password.clear();
            //Empleado4
            nombre = "Barliman"; email = "barli@mail.com"; password = "123"; cargo = Recepcion;
            ControladorU->ConfirmarAltaEmpleado(nombre,email,password,cargo);
            nombre.clear(); email.clear(); password.clear();
            /////////////////////////////////////////////////////////////////////////////////////////
            //
            //Huesped1
            nombre = "Sofia"; email = "sofia@mail.com"; password = "123"; esfinger = true;
            ControladorU->ConfirmarAltaHuesped(nombre,email,password,esfinger);
            nombre.clear(); email.clear(); password.clear();
            //Huesped2
            nombre = "Frodo"; email = "frodo@mail.com"; password = "123"; esfinger = true;
            ControladorU->ConfirmarAltaHuesped(nombre,email,password,esfinger);
            nombre.clear(); email.clear(); password.clear();
            //Huesped3
            nombre = "Sam"; email = "sam@mail.com"; password = "123"; esfinger = false;
            ControladorU->ConfirmarAltaHuesped(nombre,email,password,esfinger);
            nombre.clear(); email.clear(); password.clear();
            //Huesped4
            nombre = "Merry"; email = "merry@mail.com"; password = "123"; esfinger = false;
            ControladorU->ConfirmarAltaHuesped(nombre,email,password,esfinger);
            nombre.clear(); email.clear(); password.clear();
            //Huesped5
            nombre = "Pippin"; email = "pippin@mail.com"; password = "123"; esfinger = false;
            ControladorU->ConfirmarAltaHuesped(nombre,email,password,esfinger);
            nombre.clear(); email.clear(); password.clear();
            //Huesped6
            nombre = "Seba"; email = "seba@mail.com"; password = "123"; esfinger = true;
            ControladorU->ConfirmarAltaHuesped(nombre,email,password,esfinger);
            nombre.clear(); email.clear(); password.clear();
        break;
        case 2:
            /////////////////////////////////////////////////////////////////////////////////////////
            //
            //AltaHostal1
            nomh = "La posada del finger"; dirh = "Av de la playa 123, Maldonado"; telh = "099111111";
            ControladorH->altaHostal(nomh,dirh,telh);
            nomh.clear(); dirh.clear(); telh.clear();
            //AltaHostal2
            nomh = "Mochileros"; dirh = "Rambla Costanera 333, Rocha"; telh = "42579512";
            ControladorH->altaHostal(nomh,dirh,telh);
            nomh.clear(); dirh.clear(); telh.clear();
            //AltaHostal3
            nomh = "El Pony Pisador"; dirh = "Bree (preguntar por Gandalf)"; telh = "000";
            ControladorH->altaHostal(nomh,dirh,telh);
            nomh.clear(); dirh.clear(); telh.clear();
            //AltaHostal4
            nomh = "Altos de Fing"; dirh = "Av del Toro 1424"; telh = "099892992";
            ControladorH->altaHostal(nomh,dirh,telh);
            nomh.clear(); dirh.clear(); telh.clear();
            //AltaHostal5
            nomh = "Caverna Lujosa"; dirh = "Amaya 2515"; telh = "233233235";
            ControladorH->altaHostal(nomh,dirh,telh);
            nomh.clear(); dirh.clear(); telh.clear();
        break;
        default:
            std::cout << "Opcion Invalida" << std::endl;
        break;
    }
};

void salirSistema(){
std::cout << "Sin Implementar" << std::endl;
    pausa("Presione enter para continuar...");
};

void Limpiar(){
    limpiarBuffer();
    std::cin.clear();
    std::cin.ignore();
    system("clear");
    mostrarMenu();
}
