#ifndef POLYNOMIALFUNCTION_HPP
#define POLYNOMIALFUNCTION_HPP

#include <vector>
#include "scalarfunction.hpp"

// initialization of polynomial function class. The operator from the base scalarfunction class is overriden.
// Constructs the polynomial function based on the coefficients provided by the user.

class polynomial_function : public scalar_function{
    public:
    polynomial_function(const std::vector<double> & coefficients) : coefficients_(coefficients){}

    double operator()(double x) const override {
        double result = 0.0;

        for (auto it = coefficients_.rbegin(); it != coefficients_.rend(); ++it){
            result = result * x + *it;
        }
        return result;
    }
    
    private:

    std::vector<double> coefficients_;
};


#endif 