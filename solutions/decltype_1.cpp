#include <tuple>

template<size_t first, size_t second, typename... Args>
auto to_pair(std::tuple<Args...> &t) -> decltype(std::make_pair(std::get<first>(t), std::get<second>(t))) {
    return std::make_pair(std::get<first>(t), std::get<second>(t));
}
