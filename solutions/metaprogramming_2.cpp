template<int ...Ints>
struct IntList;

template<int H, int ... I>
struct IntList<H, I...> {
    static const int Head = H;
    using Tail = IntList<I...>;
};

template<>
struct IntList<> {};
