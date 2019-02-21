//typedef ComplexFunction

// typedef int*(*(*ComplexFunction)(int, int (*)(double)))(char const *);

typedef int* (*TmpFunc)(char const *);
typedef TmpFunc (*ComplexFunction)(int, int (*)(double));
