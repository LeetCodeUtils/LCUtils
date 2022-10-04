#ifndef IS_STL_CONTAINER_LIKE_H
#define IS_STL_CONTAINER_LIKE_H

#include <type_traits>

template<typename T>
struct is_stl_container_like
{
    template<typename A>
    static constexpr bool test(
            A const * cpt,
            decltype(cpt->begin()) * = nullptr,
            decltype(cpt->end()) * = nullptr,
            typename A::const_iterator * pci = nullptr,
            typename A::value_type * pv = nullptr) {

        typedef typename A::const_iterator const_iterator;
        typedef typename A::value_type value_type;
        return  std::is_same<decltype(cpt->begin()),const_iterator>::value &&
                std::is_same<decltype(cpt->end()),const_iterator>::value &&
                std::is_same<decltype(**pci),value_type const &>::value;

    }

    template<typename A>
    static constexpr bool test(...) {
        return false;
    }

    static const bool value = test<T>(nullptr);

};

#endif
