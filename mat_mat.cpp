#include <iostream>
#include <vector>

std::vector<std::vector<double>> mat_mat(const std::vector<std::vector<double>>&mat1,const std::vector<std::vector<double>>&mat2) {
    size_t mat1row = mat1.size();
    size_t mat1col = mat1[0].size();
    size_t mat2row = mat2.size();
    size_t mat2col = mat2[0].size();

    if (mat1col != mat2row){
        throw std::invalid_argument("Matrix dimensions do not match. Abort");
    }

    std::vector<std::vector<double>> result(mat1row,std::vector<double>(mat2col,0.0));

    for (size_t i = 0; i < mat1row; i++){
        for (size_t j = 0; j < mat2col; j++){
            for (size_t k = 0; k < mat1col; k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

void printmat(const std::vector<std::vector<double>> & mat){
    for (const std::vector<double> & row : mat){
        for (double val: row){
            std::cout << val << " ";

        }
        std::cout << std::endl;
    }
}


int main() {
    std::vector<std::vector<double>> matrix1 = {{1.0,2.0,3.0}, {1.0,2.0,3.0},{1.0,2.0,3.0}};
    std::vector<std::vector<double>> matrix2 = {{1.0,2.0,3.0}, {1.0,2.0,3.0},{1.0,2.0,3.0}};
    //std::vector<double> vector = {1.0,2.0};

    std::vector<std::vector<double>> result = mat_mat(matrix1,matrix2);
    std::cout << "The product is: "<< std::endl;
    printmat(result);
    return 0;
}

