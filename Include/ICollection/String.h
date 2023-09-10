/* 
 * File:   String.h
 * Author: igui
 *
 * Created on 29 de mayo de 2011, 06:53 PM
*/

#ifndef PROG4_STRING_H
#define PROG4_STRING_H

#include "interfaces/ICollectible.h"
#include "interfaces/OrderedKey.h"
#include <string>

using namespace std;

/**
 *  Implementación simple del datatype String que hereda tanto de ICollectible
 *  como de HashedKey
 */
class String : public ICollectible, public OrderedKey
{
private:
    string s;

public:
    // construye el Datatype a partir de un string
    String(string s);

    // da el valor del string
    const string getValue() const;

    ComparisonRes compare(OrderedKey *k) const;
};

#endif /* PROG4_STRING_H */
