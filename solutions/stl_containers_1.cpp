template<class It>
size_t max_increasing_len(It p, It q) {
    size_t len = 1;
    size_t maxlen = 1;
    It prev = p;
    ++p;
    
    while (p != q) {
        if (*p++ > *prev++) {
            ++len;
            if (len > maxlen) {
                maxlen = len;
            }
        } else {
            len = 1;
        }
    }
    return maxlen;
}
