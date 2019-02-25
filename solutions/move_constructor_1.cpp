template<class T>
struct Array {
    explicit Array(size_t size = 0);
    Array(Array const& a);
    Array & operator=(Array const& a);
    ~Array();

    size_t size() const;
    T &         operator[](size_t i);
    T const&    operator[](size_t i) const;

    void swap(Array & a) {
        std::swap(size_, a.size_);
        std::swap(data_, a.data_);
    }
    
    Array(Array && a) : Array(0) {
        swap(a);
    }

    Array & operator=(Array && a) {
        swap(a);
        return *this;
    }

private:    
    size_t  size_;
    T *     data_;    
};
