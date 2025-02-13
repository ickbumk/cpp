#ifndef INTEGRATIONRULE_HPP
#define INTEGRATIONRULE_HPP

#include <vector>
#include <stdexcept>

class integration_rule {
    public:
    // constructor initialization of the integration nodes (sampling locations and weight pairs)
    integration_rule(const std::vector<double>& nodes, const std::vector<double> & weights): nodes_(nodes), weights_(weights){
        if (nodes_.size() != weights_.size())
        throw std::invalid_argument("Nodes and weights different size");
    }

    const std::vector<double>&nodes() const { return nodes_;}

    const std::vector<double>&weights() const {return weights_;}

    private:
    std::vector<double> nodes_;
    std::vector<double> weights_;
};


#endif