AUTHORING:
  Christian Ayala, UMBC CMSC313 Student, M/W 1000AM
  UMBC ID CS46491

Purpose of software:
  Provided is a C++ and C version of matrix libriaries for functions such as sclar multiplication, transposition and addition. This software is for Homework #8 as well as practice.

Files:
  cppMatrix.cpp: Includes C++ implementation of matrix functions. Utilizes classes and dynamic allocation
  matrixC.c: The C implemetation of the matrix functions. Utilizes a matrix struct and no dynamic allocation as I was not comfortable with it. 
  makefile: contains commands to make compilation easier. type into the command line "make cMatrix" and "make runc" to run the c version and "make cppMAtrix" and "make runcpp" to run the C++ version.

Build Instructions:
  Compile the C++ version with g++ and the C version with gcc. to make life easier, use the forllowing makefile commands:
  for C++: "make cppMatrix" to compile and "make runcpp" to run
  for C: "make cMatrix" to compile using C99 and "make runc" to run the program

Testing Methodology:
  Just run the code. The code is not interactive. If you want to change the matrix values, use the functions associated with it in the code. You can see its implementation in the main fucntion.

Additional Info:
  N/A

Code Running Example:

C:

![cRun](https://github.com/user-attachments/assets/fc24b9b6-a61b-4da2-8915-6832a270dd12)

C++:

![runCPP](https://github.com/user-attachments/assets/a0bf58c3-732b-4375-a113-74c3ed407e6a)


