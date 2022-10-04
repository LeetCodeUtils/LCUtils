#ifndef LCUTILS_LCPARSE
#define LCUTILS_LCPARSE

#include "LCIncludes.h"

namespace LC {

    template<typename T>
    T convert(const string &s) {
        T value;
        stringstream convert;

        convert << s;
        convert >> value;

        return value;
    }

    template<>
    string convert<string>(const string &s) {
        return s;
    }
}
#endif //LCUTILS_LCPARSE
