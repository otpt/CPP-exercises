#include <ostream>
#include <typeinfo>

void print_values(std::ostream & os) {
    return;
}

template<typename T, typename ... Args>
void print_values(std::ostream & os, T value, Args... args) {
    os << typeid(value).name() << ": " << value << std::endl;
    print_values(os, args...);
}
