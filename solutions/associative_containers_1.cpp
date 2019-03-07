#include <typeinfo>
#include <typeindex>
#include <functional>
#include <map>


template<class Base, class Result, bool Commutative>
struct Multimethod2 {

    typedef std::function<Result (Base *, Base *)> base_function;
    typedef std::pair<std::type_index, std::type_index> pair_of_type_index;

    void addImpl(const std::type_info& t1, const std::type_info& t2, const base_function& f) {
        methods[make_pair(
            std::type_index(t1), 
            std::type_index(t2))
        ] = f;
    }

    bool hasImpl(Base * a, Base * b) const {
        if (methods.find(make_pair_of_type_index(a, b)) != methods.end()) {
            return true;
        }
        if (Commutative) {
            return methods.find(make_pair_of_type_index(b, a)) != methods.end();
        }
        return false;
    }

    Result call(Base * a, Base * b) const {
        if (hasImpl(a, b)) {
            if (methods.find(make_pair_of_type_index(a, b)) != methods.end()) {
                return methods.at(make_pair_of_type_index(a, b))(a, b);
            } else return methods.at(make_pair_of_type_index(b, a))(b, a);
        }
    }    
private:
    std::map<pair_of_type_index, base_function> methods;
    
    pair_of_type_index make_pair_of_type_index(Base * a, Base * b) const {
        return make_pair(
            std::type_index(typeid(*a)), 
            std::type_index(typeid(*b))
        );
    }
};
