#ifndef LCUTILS_LCPARSE
#define LCUTILS_LCPARSE
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
    string convert<string>(const string &s);
}
#endif //LCUTILS_LCPARSE
