#ifndef LCUTILS_LCPRINTIMPL
#define LCUTILS_LCPRINTIMPL

#include "LCIncludes.h"
#include "../Source/is_stl_container_like.h"

namespace LC {
    namespace Internal {
        template<class Container>
        void printContainer(const Container &c,
                            const string &delimiter,
                            const string &eol,
                            const size_t charCount,
                            const string &spacer);

        template<typename ...Ts>
        void print_internal(const string &eol,
                            const string &delimiter,
                            const string &containerEOL,
                            const string &containerSpacer,
                            size_t existingCharCount,
                            const Ts &... inputs) {
            size_t charCount = existingCharCount;
            string tempDelimiter;
            ([&] {
                if constexpr (is_stl_container_like<Ts>::value) {
                    cout << tempDelimiter;
                    printContainer(inputs,
                                   delimiter,
                                   containerEOL,
                                   charCount,
                                   containerSpacer);

                } else {
                    stringstream temp;
                    temp << tempDelimiter << inputs;
                    temp.seekg(0, ios::end);
                    charCount += temp.tellg();
                    cout << tempDelimiter << inputs;
                }
                tempDelimiter = delimiter;
            }(), ...);
            cout << eol;
        }

        template<class Container>
        void printContainer(const Container &c,
                            const string &delimiter,
                            const string &eol,
                            const size_t charCount,
                            const string &spacer) {
            string tempDelimiter, tempEOL, tempSpacer = "-";
            cout << eol
                 << (spacer[0] == '-' ? "" : spacer)
                 << containerOpen;
            for (const auto &item: c) {
                cout << tempDelimiter;
                print_internal("",
                               delimiter,
                               tempEOL,
                               tempSpacer,
                               charCount,
                               item);
                tempDelimiter = delimiter;
                tempEOL =
                        containerEndOfLine + string(containerOpen.size(), ' ');
                tempSpacer =
                        ((spacer[0] == '-') ? string(charCount, '-')
                                            : string(charCount, ' '));
            }
            cout << containerClose;
        }
    }

    template<typename ...Ts>
    void print(const Ts &... inputs) {
        Internal::print_internal(endOfLine,
                                 printDelimiter,
                                 "",
                                 "",
                                 0,
                                 inputs...);
    }
}
#endif //LCPRINTIMPL
