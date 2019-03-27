template <int v, typename IL>
struct IntCons;

template <int v, int ... IL>
struct IntCons<v, IntList<IL...>> {
    using type = IntList<v, IL...>;
};

template<int N>
struct Generate;

template<int N, typename IL>
struct GenerateList;

template<>
struct Generate<0> {
    using type = IntList<>;
};

template<int N>
struct Generate {
     using type = typename GenerateList<N, Generate<0>::type>::type;
};

template <int ... IL>
struct GenerateList<0, IntList<IL...>> {
    using type = IntList<IL...>;
};

template <int N, int ... IL>
struct GenerateList<N, IntList<IL...>> {
    using type = typename GenerateList<N-1, IntList<N-1, IL...>>::type;
};
