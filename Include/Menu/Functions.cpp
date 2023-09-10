#include "Functions.h"
#include "../Sistema/ManejadorHostal.h"
#include "../Sistema/ControladorHostal.h"
#include "../Sistema/InterfazHostal.h"
#include "../Fabrica/Fabrica.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "../Datatypes/Datatypes.h"
#include "../ico.h"

static Fabrica* fab = Fabrica::getInstance();
static InterfazHostal * ControladorH = fab->Hostal();
static ManejadorHostal* manhost = ManejadorHostal::getInstance();

//Imprime un pequenio titulo para el caso de uso
void imprimirTitulo(int parte){
    system("clear");
    std::cout << "|=============|" << std::endl;
    
    switch(parte){
        case 1:
            std::cout << "~~ Alta Usuario ~~" << std::endl;
            break;
        case 2:
            std::cout << "~~ Alta Hostal ~~" << std::endl;
            break;
        case 3:
            std::cout << "~~ Alta Habitacion ~~" << std::endl;
            break;
        case 4:

            break;
    }
    std::cout << "|=============|" << std::endl;
};

char confirmarSN(std::string msg){

    std::cin.ignore();
    std::cin.clear();
    while (true) {
        std::string respuesta;
        std::cout << msg << std::endl;
        std::cout << "Digite (s/n) para confirmar: ";
        std::getline(std::cin, respuesta);

        if (respuesta.length() == 1) {
            char opcion = respuesta[0];
            if (opcion == 's' || opcion == 'S') {
                return 's';
            } else if (opcion == 'n' || opcion == 'N') {
                return 'n';
            }
        }
        pausa("Respuesta inválida. Por favor, ingresa 's' para Sí o 'n' para No.");
        system("clear");
    }
    
}
//************************************************************************************//

bool verificarEnLista(std::string** l, std::string p){
    int i = 0;
    while(l[i]){
        if(*l[i] == p)
            return true;
        i++;
    }
    return false;
}
//************************************************************************************//
int DiferenciaEnDias(DTFecha* fecha1, DTFecha* fecha2) {
    // Fechas a segundos
    int segundos_fecha1 = fecha1->getAno() * 31536000 + fecha1->getMes() * 2592000 + fecha1->getDia() * 86400 + fecha1->getHoras() * 3600 + fecha1->getMinutos() * 60;
    int segundos_fecha2 = fecha2->getAno() * 31536000 + fecha2->getMes() * 2592000 + fecha2->getDia() * 86400 + fecha2->getHoras() * 3600 + fecha2->getMinutos() * 60;
    // Diferencia en segundos
    int diferencia_segundos = segundos_fecha2 - segundos_fecha1;
    // Segundos a días
    int diferencia_dias = diferencia_segundos / 86400;

    return diferencia_dias;
};
//************************************************************************************//
int pedirInt(std::string msg){
    std::cout << "Ingrese " << msg << ": ";
    int valor;
    std::cin >> valor;

    return valor;
};
//************************************************************************************//
float pedirFloat(std::string msg){
    std::cout << "Ingrese " << msg << ": ";
    float valor;
    std::cin >> valor;

    return valor;
}

//************************************************************************************//
std::string pedirString(std::string msg){
    std::cout << "Ingrese " << msg << ": ";
    std::string valor;
    std::getline(std::cin, valor); 
    system("clear");
    
    return valor;
};
//************************************************************************************//

void limpiarBuffer(){
    while (getchar() != '\n'){
        //pass
    }
}
//************************************************************************************//

void borrarLista(ICollection* lista){
    for (IIterator* it = lista->getIterator(); it->hasCurrent(); it->next()){
        ICollectible* col = it->getCurrent();
        lista->remove(col);
        delete col;
    }
};

//************************************************************************************//
void pausa(std::string msg){
    std::cout << msg;
    while(getchar() != '\n'){
        //para generar pausa
    }
};
//************************************************************************************//

bool validarExisteOpcionString(ICollection* coleccion, std::string valor){
    bool encontre = false;

    for(IIterator* it = coleccion->getIterator(); it->hasCurrent() && !encontre; it->next()){
        if (strcmp(((String*)it->getCurrent())->getValue().c_str(),valor.c_str()) == 0){
            encontre = true;
        }
    }

    return encontre;
};
//************************************************************************************//

bool validarNombreHostal(std::string nombreHostal){
    if (strcmp(nombreHostal.c_str(), "p") == 0){
        return false;
    }
    if (strcmp(nombreHostal.c_str(), "n") == 0){
        return false;
    }
    if (!(manhost->isEmpty())){
        String* llave = new String(nombreHostal);
        if (manhost->member(llave)){
            return false;
        }
    }

    return true;
};

//************************************************************************************//

std::string imprimirObtengoHostales(List* listaHostal){
    int topexPagina = 10, total=0, actual, pagina;
    std::string nombreHostal;
    bool elegido = false, alcanceLimite;

    //total de hostales
    for(IIterator * it = listaHostal->getIterator();it->hasCurrent();it->next()){
        total++;
    }

    //Cantidad de paginas que tengo
    pagina = (int)total/topexPagina;

    //Imprimo titulos
    imprimirTitulo(3);
    std::cout << "\n     Hostales Registrados      " << std::endl;

    pagina = 1;
    while (!elegido){
        actual = 0;
        alcanceLimite = false;

        //Itero mientras tenga o mientras la cantidad actual es menor al tope x pagina
        for(IIterator * it = listaHostal->getIterator();it->hasCurrent() && !alcanceLimite;it->next()){
            actual++;

            if (pagina == (int)actual/topexPagina){
                String* str = (String*)it->getCurrent();
                std::cout << actual << " - " << str->getValue() << std::endl;
                //Imprimi 10 hostales
                if (actual%topexPagina == 0){
                    alcanceLimite = true;
                }
            }
        }

        //Primera pagina pero + de 10
        if (alcanceLimite && pagina == 1){
            std::cout << "Pagina Siguiente : n" << std::endl;
        }
        //Pagina 2 o mas, y quedan mas de 10
        if (alcanceLimite && pagina != 1){
            std::cout << "Pagina Anterior : p" << std::endl;
            std::cout << "Pagina Siguiente : n" << std::endl;
        }
        //Ultima pagina
        if (!alcanceLimite && pagina != 1){
            std::cout << "Pagina Anterior : p" << std::endl;
        }

        nombreHostal = pedirString("Nombre Hostal a elegir");

        if (strcmp(nombreHostal.c_str(), "p") == 0){
            pagina--;
        } else if (strcmp(nombreHostal.c_str(), "n") == 0){
            pagina++;
        } else {
            elegido = validarExisteOpcionString(listaHostal, nombreHostal);
        }
    }
    return nombreHostal;
};
//************************************************************************************//

bool habitacionValida(int numerohab, std::string nombreHostal){
    if (numerohab < 1){
        throw std::invalid_argument("El valor ingresado es negativo o invalido.");
    }

    for (IIterator * it = manhost->getIterator(); it->hasCurrent(); it->next()){
        Hostal* h = (Hostal*)it->getCurrent();
        if (h->existeHabitacion(numerohab)){
            throw Duplicado("Ya existe una habitacion para el hostal seleccionado con el numero ingresado");
        }
    }

    return true; //Eleccion correcta
};

bool capacidadValida(int capacidadhab){
    if (capacidadhab < 1){
        throw std::invalid_argument("La capacidad debe ser un numero positivo");
    }
    return true;
};

//************************************************************************************//
int opcionAltaUsuario(){
    char opcion;
    std::cout << "1 - Ingresar un Huesped" << std::endl;
    std::cout << "2 - Ingresar un Empleado" << std::endl;
    std::cout << "3 - Salir" << std::endl;
    std::cin >> opcion;
    
    return opcion;
};

//************************************************************************************//
bool confirmarSN(char respuesta) {
    respuesta = std::tolower(respuesta); // Convertir a minúscula para aceptar 'S' o 'N'
    return (respuesta == 's' || respuesta == 'n');
}

bool validarRespuesta(const std::string& respuesta) {
    if (respuesta.length() != 1) {
        return false; // La respuesta no tiene una sola letra
    }

    char entrada = respuesta[0];
    if (!std::isalpha(entrada)) {
        return false; // La respuesta no es una letra
    }

    return confirmarSN(entrada);
}



char Confirmacion(char opcion) {
    //char opcion;
    bool entrada_valida = false;
    
    do {
        std::cout << "Ingrese 's' para Sí o 'n' para No: ";
        std::cin >> opcion;
        
        // Limpiar el buffer del cin en caso de que se ingresen caracteres adicionales
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Verificar que solo se haya ingresado un carácter válido
        if (opcion == 's' || opcion == 'n') {
            entrada_valida = true;
        } else {
            std::cout << "Entrada inválida. Intente nuevamente." << std::endl;
        }
    } while (!entrada_valida);
    
    return opcion;
}




char confirmarSN2(){
    while (true) {
        std::string respuesta;
        std::cout << "Digite (s/n) para confirmar: ";
        std::getline(std::cin, respuesta);

        if (respuesta.length() == 1) {
            char opcion = respuesta[0];
            if (opcion == 's' || opcion == 'S') {
                return 's';
            } else if (opcion == 'n' || opcion == 'N') {
                return 'n';
            }
        }
        std::cout << "Respuesta inválida. Por favor, ingresa 's' para Sí o 'n' para No." << std::endl;
    }
}

///////////////////********
std::string obtenerNombreCargo(tipoCargo cargo) {
    switch (cargo) {
        case 0: Administracion:
            return "Administracion";
            break;
        case 1: Limpieza:
            return "Recepcion";
            break;
        case 2: Recepcion:
            return "Limpieza";
            break;
        case 3: Infraestructura:
            return "Infraestructura";
            break;
        case 4: No_Empleado:
            return "No_Empleado";
            break;
    }
}

void mostrarError(const std::string& mensaje) {
    std::cerr << "Error: " << mensaje << std::endl;
}