#ifndef IS_PAIR_LIKE_H
#define IS_PAIR_LIKE_H

#include <type_traits>

template<typename T>
struct is_pair_like {
    template<typename A>
    static constexpr bool test(
            A const *cpt,
            decltype(cpt->first) * = nullptr,
            decltype(cpt->second) * = nullptr,
            typename A::first_type *pv1 = nullptr,
            typename A::second_type *pv2 = nullptr) {

        typedef typename A::first_type first_type;
        typedef typename A::second_type second_type;
        return std::is_same<decltype(cpt->first), first_type>::value &&
               std::is_same<decltype(cpt->second), second_type>::value;

    }

    template<typename A>
    static constexpr bool test(...) {
        return false;
    }

    static const bool value = test<T>(nullptr);

};

#endif
