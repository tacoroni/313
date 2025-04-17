CXX = g++
CXXFLAGS = -Wall

cppMatrix: cppMatrix.cpp
	$(CXX) $(CXXFLAGS) cppMatrix.cpp -o matrixCpp

cMatrix:
	gcc -std=c99 -Wall -o cMatrix matrixC.c

runcpp:
	./matrixCpp

runc:
	./cMatrix