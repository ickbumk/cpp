# Numerical Integration Toolkit
This repository contains the necessary toolkit for different numerical integration approaches 
- Gauss-Legendre 
- Gauss-Lobotto 
- Chebyshev

## File description
This repository contains
```bash
chebyshev.hpp
gauss_legendre.hpp
gauss_lobotto.hpp
```
Header files for loading the weights for the respective approaches. 
```bash
integration_rule.hpp
polynomial_function.hpp
scalarfunction.hpp
```
contains the class definitions for construction.

```bash
polynomial_integrate.cpp
```
is the main file.

## Testing
After you clone the repo,
```bash
mkdir build
cd build
cmake ..
make
./polynomial_integrate
```
will run the program. If you want to perform the unittest, you can _./unittest_ instead of _./polynomialintegrate_. After you execute the polynomial integrate, you will be directed with the following prompt:

- Enter integration limits separated by space(a and b):
- Enter polynomial coefficients (c0 c1 c2 ...) separated by space:
- Enter the type of integration rule (e.g. gle(gauss_legendre), glo(gauss-lobotto), cs(chebyshev)):
- Enter the number of points: