#ifndef LCUTILS_LCPARSE
#define LCUTILS_LCPARSE

#include "LCIncludes.h"

template<typename T>
T LCConvert( const string& s ) {
    T value;
    stringstream convert;

    convert << s;
    convert >> value;

    return value;
}

template<>
string LCConvert<string>( const string& s ) {
    return s;
}

#endif //LCUTILS_LCPARSE
