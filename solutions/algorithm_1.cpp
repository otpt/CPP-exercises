#include <algorithm>

template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n) {
    while (n-- && p != q) {
        ++p;
    }
    if (p == q) return p;
    
    FwdIt prev = p++;
    while (p != q) {
        *prev++ = *p++;
    }
    return prev;
}
