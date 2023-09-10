#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <iostream>

class Duplicado: public std::exception {
    private:
        std::string message;

    public:
        Duplicado(std::string msg) : message(msg){};
        std::string what(){
            return this->message;
        };
};

#endif