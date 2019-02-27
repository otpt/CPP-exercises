auto gen_finder = [](int * begin, int * end) {
    return [begin, end](int x) {
        int * current = begin; 
        while (current != end) if (*current++ == x) return true;
        return false;
    };
};
