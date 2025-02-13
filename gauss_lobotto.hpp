#ifndef GAUSSLOBOTTO_HPP
#define GAUSSlOBOTTO_HPP

#include <vector>
#include <cmath>
#include <stdexcept>
#include "integration_rule.hpp"

// Implmementation of gauss lobotto integration method.
// Provides nodes and weights based on the number of points (user input)

integration_rule get_gauss_lobotto(int num_points){
    switch (num_points) {
        case 3: {
            std::vector<double> nodes = {-1.0, 0.0, 1.0};
            std::vector<double> weights = {1.0/3.0, 4.0/3.0, 1.0/3.0};
            return integration_rule(nodes,weights);
        }
        case 4: {
            double invsqrt5 =  1.0/std::sqrt(5.0);
            std::vector<double> nodes = {-1.0, -invsqrt5, invsqrt5, 1.0};
            std::vector<double> weights = {1.0/6.0,5.0/6.0,5.0/6.0, 1.0/6.0};
            return integration_rule(nodes,weights);
        }
        case 5: {
            double sqrt37 = std::sqrt(3.0/7.0);

            std::vector<double> nodes = {-1.0,-sqrt37, 0.0, sqrt37, 1.0};
            std::vector<double> weights = {1.0/10.0, 49.0/90.0, 32.0/45.0, 49.0/90.0, 1.0/10.0};
            return integration_rule(nodes,weights);
        }
        default:
        throw std::invalid_argument("Gauss-Legendre supports 3-5 points only\n");
    }
}


#endif