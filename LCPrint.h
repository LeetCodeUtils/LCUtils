#ifndef LCUTILS_LCPRINT
#define LCUTILS_LCPRINT

#include "LCIncludes.h"

namespace LC {

    void print() {
        cout << '\n';
    }

    template<typename T, typename ...TAIL>
    void print(const T &t, TAIL... tail) {
        print(t);
        print(tail...);
    }

    template<typename T>
    void print(const vector<vector<T>> &v) {
        for (size_t i = 0; i < v.size(); ++i) {
            for (size_t j = 0; j < v[i].size(); ++j) {
                cout << v[i][j] << "\t";
            }
            cout << endl;
        }
    }

    template<typename T>
    void print(const vector<T> &v) {
        for (size_t j = 0; j < v.size(); ++j) {
            cout << v[j] << ",\t";
        }
    }

    template<typename T1, typename T2>
    void print(const pair<T1, T2> &p) {
        cout << "First: " << p.first << ", Second: " << p.second << endl;
    }
}
#endif //LCPRINT
