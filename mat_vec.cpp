#include <iostream>
#include <vector>

std::vector<double> mat_vec(const std::vector<std::vector<double>>& mat, const std::vector<double>& vec) {
    
    size_t matcol = mat[0].size();
    size_t vecsize = vec.size();

    if(matcol != vecsize) {
        throw std::invalid_argument("Matrix and vector dimensions do not match.");
    }

    std::vector<double> result(mat.size(), 0.0);

    for(size_t i = 0; i < mat.size(); i++) {
        for(size_t j = 0; j < matcol; j++) {
            result[i] += mat[i][j] * vec[j];
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<double>> matrix = {{1.0,2.0,3.0}, {1.0,2.0,3.0},{1.0,2.0,3.0}};
    std::vector<double> vector = {1.3,2.0,3.0};
    //std::vector<double> vector = {1.0,2.0};

    std::vector<double> result = mat_vec(matrix,vector);
    std::cout << "The product is: ";
    for (double val:result) {
        std::cout<<val << " ";
    }
    return 0;
}