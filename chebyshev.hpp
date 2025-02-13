#ifndef CHEBYSHEV_HPP
#define CHEBYSHEV_HPP

#include <vector>
#include <cmath>
#include <stdexcept>
#include "integration_rule.hpp"

integration_rule get_chebyshev(int num_points){
    if (num_points < 1){
        throw std::invalid_argument("You need more points than that!");
    }

    std::vector<double> nodes;
    std::vector<double> weights;

    double weight = M_PI / num_points;

    for (int k = 1; k <= num_points; ++k){
        double node = std::cos((2.0 * k -1)*M_PI/ (2.0*num_points));
        nodes.push_back(node);
        weights.push_back(weight);
    }
    return integration_rule(nodes, weights);
}


#endif