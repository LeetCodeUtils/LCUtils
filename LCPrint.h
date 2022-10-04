#ifndef LCUTILS_LCPRINT
#define LCUTILS_LCPRINT

#include "LCIncludes.h"
#include "is_stl_container_like.h"

namespace LC {
    template<class Container>
    void printContainer(const Container &c) {}

    template<typename ...Ts>
    void print(const Ts &... inputs) {
        ([&] {
            if constexpr (is_stl_container_like<Ts>::value)
                printContainer(inputs);
            else cout << inputs << "\t";
        }(), ...);
        cout << endl;
    }
}
#endif //LCPRINT
