#include <algorithm>
#include <vector>

template<class Iterator>
size_t count_permutations(Iterator p, Iterator q) {
    std::vector<typename std::iterator_traits<Iterator>::value_type> elements(p, q);

    std::sort(elements.begin(), elements.end());
    size_t result = 0;
    
    do {
        result += (std::adjacent_find(elements.begin(), elements.end()) == elements.end());
    } while (std::next_permutation(elements.begin(), elements.end())); 
    
    return result;
}
