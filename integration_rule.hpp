#ifndef INTEGRATIONRULE_HPP
#define INTEGRATIONRULE_HPP

#include <vector>
#include <stdexcept>
#include <string>

// Class initialization for the integration assignment
// Integration rule can be specified with different methods (gauss legendre, gauss lobotto, chebyshev)

class integration_rule {
    public:
    integration_rule(const std::vector<double>& nodes, const std::vector<double> weights): nodes_(nodes), weights_ (weights){
        if (nodes_.size() != weights_.size()){
            throw std::invalid_argument("Nodes and weights must have matching size");
        }
    }

    std::vector<double> get_nodes() const {return nodes_;}
    std::vector<double> get_weights() const {return weights_;}

    private:
    std::vector<double> nodes_;
    std::vector<double> weights_;
};


#endif