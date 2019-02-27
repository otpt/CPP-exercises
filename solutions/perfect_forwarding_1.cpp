#include <utility> // std::move, std::forward

template <class F, typename ...Args>
auto apply (F func, Args&&... args) -> decltype(func(std::forward<Args>(args)...)) {
    return func(std::forward<Args>(args)...);
}
