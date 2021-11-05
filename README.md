# Parallel processing

#Specification
Write a program that follows the following specification:
- The program must be written in C.
- Only the C library can be used. Do not use any extra library.
- It should be possible to compile the program on Linux or Windows.
- The setup of the compilation environment must be done with cmake (https://cmake.org). This
will ensure, that the program can be compiled on Linux and Windows. This environment will
be used in other classes, so please learn it now.
- The application should be a console program.
- The program must receive all input from the command line as parameter. For example
numbers or file names, etc.
- If there is a problem with the input, the program should exit and return an error code.
- The output of the program must be written into an “output” file.
- All parameters of the algorithms, like size of vector or filename must be an input parameter.
- Therefore all vectors and matrices must be dynamically allocated.
-The input text file should contain the matrix row-by-row. There can be spaces of TABS
between the numbers. For example:

 
```
1.2 4.5 5.6 1.7
4.56 3.21 8.631 7.234
1.0 4.5 7.7 9.3
4.1 5.8 8.3 3.0
```

- As a minimum, one test case must be included in the submitted homework. The test should be
executed with the cmake environment (ctest).

##Submission
You should submit the following in a zip file:

- Source code (including CMakelists.txt files)
NO binary files or generates project files (like a Visual Studio project) should be included.

##Requirement:
The program must read in an NxN matrix with floating point numbers. The program must
determine the index of columns, which contains one element that is equal to the average of the
values in the same column. The outputs are the indices of the columns.