#include <iostream>
#include <memory>
#include <vector>
#include <sstream>

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


int main(){
    std::cout<< "Enter integration limits separated by space(a and b): ";
    double a, b, c;
    std::string user_input;


    std::cin >> a >> b;
    std::cin.ignore(); //discard the rest of the line

    std::cout<< "Enter polynomial coefficients (c0 c1 c2 ...) separed by space: ";
    std::vector<double> coefficients = parseDoubles();
    std::unique_ptr<scalar_function> polyfunc = std::make_unique<polynomial_function>(coefficients);

    std::cout<< "Enter the type of integration rule (e.g. gle(gauss_legendre), glo(gauss-lobotto), cs(chebyshev)): ";
    std::getline(std::cin, user_input);

    std::cout<< "Enter the number of points: ";
    std::cin >> c;

    std::cout << "Starting the integration \n";

    if(user_input == "gle"){
        std::cout<< "user selected Gauss-Legendre integration method\n";

        integration_rule rule = get_gauss_legendre(c);
        double approx = integrate(*polyfunc, a, b, rule);
        std::cout << "Gauss-Legendre integration result is approximately: "<< approx << "\n";


    }else if(user_input == "glo"){
        std::cout<< "user selected Gauss-lobotto integration method\n";

        integration_rule rule = get_gauss_lobotto(c);
        double approx = integrate(*polyfunc, a, b, rule);
        std::cout << "Gauss-Lobotto integration result is approximately: "<< approx << "\n";

        
    }else if(user_input == "cs"){
        std::cout<< "user selected Chebyshev integration method\n";

        integration_rule rule = get_chebyshev(c);
        double approx = integrate(*polyfunc, a, b, rule);
        std::cout << "Chebyshev integration result is approximately: "<< approx << "\n";

    }else {
        std::cout<<"Incorrect integration method specified \n";
    }

}