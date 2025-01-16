## Assignment 0
#(a)
I tested my code by creating an executable and running on the command prompt. The matrices used for testing are synthetically generated.

#(b)
The limitations of the matrix market is that it is widely supported for sparse matrices. However, it is not efficient and have limited data types. It does not scale with larger datasets.

#(c)
Right now, my code reads the size of the matrix when it is inputed. However, if I already know the size of the matrices, I would use static arrays, which is more efficient/

#(d)
The matrix is row-major order. This is default for cpp application. If I use column-major it would negatively impact the performance because CPU can cache rows more efficiently.

#(e)
I used in-line comments to describe the functionality of the code.

#(f)
The code may not be best at handling all possible edge cases. For example, when the data does not follow the MMTX format and possibly have strings in the data sequence, the proposed algorithm would not be able to handle the information.

#(g)
Current implementation of the code has different functions defined for the vector and matrix reading. In the future, this could be improved, by reading the user input and automatically switching between vector and matrix within a function. Moreover, the functions are pasted into one single cpp file, which could be improved by using hpp (header) files and importing from another .cpp file for better readability. In addition, there are limitation from the format, where dense matrices cause higher memory consumption.

#(h)
The approach I would take to optimize the code would be using headers. 
