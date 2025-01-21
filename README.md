# Matrix Computation Toolkit for Matrix Market format
This repository contains the necessary toolkit for Matrix Market format.

## Testing

The repository contains 
```bash
mat_mat.cpp
mat_vec.cpp
mmf_product.cpp
```

_mat_vec.cpp_ contains the necessary code to run dense matrix and vector product.
_mat_mat.cpp_ contains the necessary code to run dense matrix matrix product. 
_mmf_product.cpp_ contains the master code for the aforementioned operations.

You can take a look at either the individual code or test out sample cases by just double clicking the executables. With the same filename as the cpp files without any extension.

Please note that executing the _mmf_product_ file requires you to specify the computation type:
0. Matrix vector product
1. Matrix matrix product

Both CMake and the linkage between the cpp files have not been implemented yet.

## Using your own input file
You can test the code with your own input file by simply editing the paths for the two matrices/matrix-vector:
```bash
matA = "MMformat.ps";
matB = "MMformat.ps";
```
 
or uncomment the couts, 
```bash
std::cout<<"First Matrix filename is: ";
std::cin >> matA;
std::cout << "Second Matrix filename is : ";
std::cin >> matB; 
``` 
and compile the _mmf_product.cpp_ by simply typing: 
```bash
g++ mmf_product.cpp -o mmf_product
``` 
The above line will update the executable file. Once you run the executable you will see the promps where you can type the input path. The results will be stored in the _results.mm_ file. 


