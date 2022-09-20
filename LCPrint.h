#ifndef LCUTILS_LCPRINT
#define LCUTILS_LCPRINT

#include "LCIncludes.h"

template<typename T>
void LCPrint(const vector<vector<T>> &v) {
    for (auto i: v) {
        print(i);
        cout << endl;
    }
}

template<typename T>
void LCPrint(const vector<T> &v) {
    cout << "[";
    for (size_t j = 0; j < v.size(); ++j) {
        cout << v[j] << " ";
    }
    cout << "]";
}


void LCPrint() {
    cout << '\n';
}

template<typename T, typename ...TAIL>
void LCPrint(const T &t, TAIL... tail) {
    cout << t << ' ';
    print(tail...);
}

#endif
