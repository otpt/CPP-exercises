template<typename T, typename S>
bool compare(const T&  a, const T& b, S (T::*mptr)() const) {
    return (a.*mptr)() < (b.*mptr)();
}
