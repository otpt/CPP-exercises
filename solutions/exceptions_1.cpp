#include <string>
#include <sstream>
#include <exception>

class bad_from_string : public std::exception {
public:
	bad_from_string(const char * message)
	: message(message) {
	}

	const char * what() const noexcept {
    	return message;
    }
private:
	const char * message;
};

template <typename T>
T from_string(std::string s) {
	T value;

	std::istringstream stream(s);

	if (stream  >> std::noskipws >> value) {
		char ch;
		if (stream >> ch) {
			throw bad_from_string("exception");
		} else {
			return value;
		}
	} else {
		throw bad_from_string("exception");
	}

	return value;
}
