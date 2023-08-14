#ifndef MXCOMPILER_2023_EXCEPTION_H
#define MXCOMPILER_2023_EXCEPTION_H
#include <stdexcept>
#include <string>

//inheriting constructor
class syntax_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class semantic_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

#endif //MXCOMPILER_2023_EXCEPTION_H
