template<typename IntList>
struct Length {
    static const int value = 1 + Length<typename IntList::Tail>::value;
};

template<>
struct Length<IntList<>> {
    static const int value = 0;
};
