#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <cassert>

#include "scalarfunction.hpp"
#include "integration_rule.hpp"
#include "polynomial_function.hpp"
#include "gauss_legendre.hpp"
#include "gauss_lobotto.hpp"
#include "chebyshev.hpp"


double integrate(const scalar_function& func, double a, double b, const integration_rule& rule){
    double scale = (b-a)/2.0;
    double midpoint = (a+b)/2.0;
    double result = 0.0;

    const auto& nodes = rule.nodes();
    const auto& weights = rule.weights();
    for (size_t i =0; i<nodes.size(); ++i){
        double x = scale * nodes[i] + midpoint;
        result += weights[i] * func(x);
    }
    return scale * result;
}

//parsedoubles reads the user inputs
std::vector<double> parseDoubles() {
    std::vector<double> values;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    double number;

    while (iss>>number) {
        values.push_back(number);
    }
    return values;
}

void test_gle(std::vector<double> coefficients, double a, double b, double c, const integration_rule&rule){

    std::unique_ptr<scalar_function> polyfunc = std::make_unique<polynomial_function>(coefficients);
    double approx = integrate(*polyfunc, a, b, rule);
    
    assert(std::abs(approx-6) < 1);
}

void test_glo(std::vector<double> coefficients, double a, double b, double c, const integration_rule&rule){
    
    std::unique_ptr<scalar_function> polyfunc = std::make_unique<polynomial_function>(coefficients);
    double approx = integrate(*polyfunc, a, b, rule);
    
    assert(std::abs(approx-6) < 1);
}
void test_cs(std::vector<double> coefficients, double a, double b, double c, const integration_rule&rule){
    
    std::unique_ptr<scalar_function> polyfunc = std::make_unique<polynomial_function>(coefficients);
    double approx = integrate(*polyfunc, a, b, rule);
    
    assert(std::abs(approx-10) < 1);
}


int main(){
    std::cout<< "Unittest will be carried with integration limits 0 and 1: \n";
    double a, b, c;

    a = {0.0};
    b = {1.0};
    c = {4};

    std::cout<< "The polynomial coefficients chosen for this is 2,3,4,5: \n";
    std::vector<double> coefficients ={4,3,2,1};
    
    std::cout << "Starting the integration \n";

    try {
        test_glo(coefficients, a, b, c, get_gauss_lobotto(c));
        test_gle(coefficients, a, b, c, get_gauss_legendre(c));
        test_cs(coefficients, a, b, c, get_chebyshev(c));
        return 0;
    } catch (...){
        return 1;
    }
    

}