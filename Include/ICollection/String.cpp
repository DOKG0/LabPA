#include <stddef.h>
#include <stdexcept>
#include <string.h>
#include "String.h"

String::String(string str) : s(str)
{
}

ComparisonRes String::compare(OrderedKey *k) const
{
    String *str = dynamic_cast<String *>(k);
    if (str == NULL)
        throw std::invalid_argument("Invalid key k");
    int cmp = strcmp(s.c_str(), str->s.c_str());
    if (cmp == 0)
        return EQUAL;
    else if (cmp > 0)
        return GREATER;
    else
        return LESSER;
}

const string String::getValue() const
{
    return s;
}
