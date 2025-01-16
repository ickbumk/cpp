#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::vector<double>> readMMformat(const std::string & filename){
    std::ifstream file(filename);

    std::string line;

    std::getline(file, line); //
    while (line.substr(0,2) == "%%") { 
        // if it is a header
        std::cout << "The header says: " << line << " \n";
        std::getline(file,line); // skip to the next line
    }

    std::getline(file, line);
    while (line.substr(0,2) == "%") {
        // if it is a comment
        std::cout << "The comments says: " << line << " \n";
        std::getline(file, line); // skip to the next line
    }

    std::stringstream ss(line);

    size_t n_row, n_col, entry;

    ss>>n_row>> n_col>> entry;

    std::vector<std::vector<double>> result(n_row, std::vector<double>(n_col, 0.0)); //initialize the result matrix
    
    for (size_t i = 0; i < entry; i++){
        std::getline(file, line);
        std::stringstream ss(line);
        size_t row, col;
        double val;
        ss >> row >> col>> val;
        result[row-1][col-1] = val;
    }
    file.close();
    return result;
}

std::vector<double> readMMformat_vector(const std::string & filename){
    std::ifstream file(filename);

    std::string line;

    std::getline(file, line); //
    while (line.substr(0,2) == "%%") { 
        // if it is a header
        std::getline(file,line); // skip to the next line
    }

    std::getline(file, line);
    while (line.substr(0,2) == "%") {
        // if it is a comment
        std::getline(file, line); // skip to the next line
    }

    std::stringstream ss(line);

    size_t n_row, n_col, entry;

    ss>>n_row>> n_col>> entry;

    std::vector<double> result(std::vector<double>(n_col, 0.0)); //initialize the result matrix
    
    for (size_t i = 0; i < entry; i++){
        std::getline(file, line);
        std::stringstream ss(line);
        size_t row, col;
        double val;
        ss >> row >> col>> val;
        result[col-1] = val;
    }
    file.close();
    return result;
}



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

void saveMMfile(const std::string & filename, const std::vector<std::vector<double>> & matrix){
    std::ofstream file(filename);

    size_t nrow = matrix.size();
    size_t ncol = matrix[0].size();

    file << "%%MatrixMarket matrix array real general\n";
    file << nrow << ncol << nrow << "\n";

    for (size_t i = 0; i< nrow; ++i){
        for (size_t j = 0; j < ncol; ++i){
            file << i << j << matrix[i][j] << "\n";
        }
    }

    file.close();
}

void saveMMfile_vector(const std::string & filename, const std::vector<double> & matrix){
    std::ofstream file(filename);

    size_t nrow = matrix.size();

    file << "%%MatrixMarket matrix array real general\n";
    file << nrow << 1 << nrow << "\n";

    for (size_t i = 0; i< nrow; ++i){
        file << i << 1 << matrix[i] << "\n";
        }

    file.close();
}


int main() {
    std::string matA, matB;
    int computationType;
    /* 
    std::cout << "First Matrix filename is: ";
    std::cin >> matA;
    std::cout << "Second Matrix filename is: ";
    std::cin >> matB; */

    matA = "MMformat.ps";
    matB = "MMformat.ps";
    std::cout << "Computation type is: ";
    std::cin >> computationType;

    std::vector<std::vector<double>> matrixA = readMMformat(matA);
    /* 

    if (computationType == 0){
        std::vector<double> matrixB = readMMformat_vector(matB);
        std::vector<double> result;
        result= mat_vec(matrixA, matrixB);
        saveMMfile_vector("result.mm", result);
    }

    if (computationType == 1){
        std::vector<std::vector<double>> matrixB = readMMformat(matB);
        std::vector<std::vector<double>> result;
        result = mat_mat(matrixA, matrixB);
        saveMMfile("result.mm", result);
    }
 */
    return 0;
}
