#ifndef SCALAR_FUNCTION_H
#define SCALAR_FUNCTION_H


#include <vector>
/* #include <utility> // this enables the usage of std::pair for storing (sample location, weight) */

/* 
Assumptions :
- The function is continuous over the domain of integration
- The function is defined for all inputs in the given range
*/

class scalar_function {
    public:

    virtual ~scalar_function() = default; // virtual destructor 

    virtual double operator()(double x) const = 0;
};

#endif 