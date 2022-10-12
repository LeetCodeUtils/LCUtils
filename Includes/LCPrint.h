#ifndef LCUTILS_LCPRINT
#define LCUTILS_LCPRINT

namespace LC {
    static const string
            printDelimiter = "\t",
            containerOpen = "{",
            containerClose = "}",
            endOfLine = "\n--------------------\n",
            containerEndOfLine = "\n";

    template<typename ...Ts>
    void print(const Ts &... inputs);
}

#include "../Source/LCPrintImpl.h"

#endif //LCPRINT
