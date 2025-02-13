#ifndef GAUSSLEGENDRE_HPP
#define GAUSSLEGENDRE_HPP

#include <vector>
#include <cmath>
#include <stdexcept>
#include "integration_rule.hpp"

integration_rule get_gauss_legendre(int num_points){
    switch (num_points) {
        case 1: {
            std::vector<double> nodes = {0.0};
            std::vector<double> weights = {2.0};
            return integration_rule(nodes,weights);
        }
        case 2: {
            double invsqrt3 =  1.0/std::sqrt(3.0);
            std::vector<double> nodes = {-invsqrt3, invsqrt3};
            std::vector<double> weights = {1.0, 1.0};
            return integration_rule(nodes,weights);
        }
        case 3: {
            double sqrt35 = std::sqrt(3.0/5.0);

            std::vector<double> nodes = {-sqrt35, 0.0, sqrt35};
            std::vector<double> weights = {5.0/9.0, 8.0/9.0, 5.0/9.0};
            return integration_rule(nodes,weights);
        }
        case 4: {
            double sqrt65 = std::sqrt(6.0/5.0);
            double term1 = std::sqrt((3.0+2.0*sqrt65)/7.0);
            double term2 = std::sqrt((3.0 -2.0*sqrt65)/7.0);

            std::vector<double> nodes = {-term1, -term2, term2, term1};

            double weight1 = (18 + std::sqrt(30.0))/36.0;
            double weight2 = (18 - std::sqrt(30.0))/36.0;
            std::vector<double> weights = {weight1, weight2, weight2, weight1};

            return integration_rule(nodes,weights);
        }
        default:
        throw std::invalid_argument("Gauss-Legendre supports 1-4 points only\n");
    }
}


#endif