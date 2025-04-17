#include <iostream>
using namespace std;

// matrix class and relevant functions
class Matrix{
public:
    // member vars
    int rows;
    int cols;
    int **matrixdata;

    //constuctor, using dynamic mem
    Matrix(int r, int c){
        rows = r;
        cols = c;

        matrixdata = new int*[r];
        for (int i = 0; i < rows; i++){
            matrixdata[i] = new int[c];
        }
        // initialize to zeros.
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                matrixdata[i][j] = 0;
            }
        }
    }

    // default constructor
    Matrix(){
        rows = 0;
        cols = 0;
        matrixdata = nullptr;
    }

    //copy constructor
    Matrix(const Matrix& other){
        rows = other.rows;
        cols = other.cols;

        matrixdata = new int*[rows];
        for (int i = 0; i < rows; i++){
            matrixdata[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                matrixdata[i][j] = other.matrixdata[i][j];
            }
        }
    }

    // destructor
    ~Matrix(){
        deleteMatrix();
    }

    // easy way to insert matrix values
    void insertVal(int rowNum, int colNum, int val){
        matrixdata[rowNum][colNum] = val;
    }

    // used to transpose the matrix
    Matrix Transpose(){
        // create a new transpose matrix
        Matrix Transpose(cols, rows);
        for (int i = 0; i < rows; i ++){
            for (int j = 0; j < cols; j++){
                Transpose.matrixdata[j][i] = matrixdata[i][j];
            }
        }
        return Transpose;
    }

    // add two matricies together
    Matrix addMatricies(Matrix other){
        // make sure dimensions are the same
        if (rows != other.rows || cols != other.cols){
            display();
            other.display();
            cout << "error here" << endl;
            return *this;
        // add corressponding values
        }else{
            Matrix sum(rows, cols);
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++){
                    sum.matrixdata[i][j] = other.matrixdata[i][j] + matrixdata[i][j];
                }
            }
            return sum;
        }
        return *this;
    }

    // multiply by a constant integer val
    void multiplyConstant(int constant){
        // var used to keep track of the matrix product
        int product;

        // iterate and multiply
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                product = (matrixdata[i][j] * constant);
                matrixdata[i][j] = product;
            }
        }
    }
    
    // multiply two matrices
    Matrix multiplyMatrix(Matrix other){
        // make sure cols and rows match
        if (other.rows != cols){
            return *this;
        }else{
            // loop and preform matrix multiplication
            Matrix product(rows, other.cols);

            for (int i = 0; i < rows; i++){
                for (int j = 0; j < other.cols; j++){
                    for (int k = 0; k < cols; k ++){
                        product.matrixdata[i][j] += matrixdata[i][k] * other.matrixdata[k][j];
                    }
                }
                
            }
            // return the new matrix
            return product;

        }
    }

    // solves the equation A+(3*B)xC^T
    Matrix solveEquation(Matrix B, Matrix C){
        B.multiplyConstant(3);
        Matrix transposeC = C.Transpose();
        Matrix product = B.multiplyMatrix(transposeC);
        Matrix answer = addMatricies(product);
        return answer;
    }
    // used to help the destructor
    void deleteMatrix(){
        for (int i = 0; i < rows; i++){
            delete matrixdata[i];
        }
        delete[] matrixdata;
        matrixdata = nullptr;
    }


    void display(){
        // loop through and display the matrix
        for (int i = 0; i < rows; i++){
            cout << "[ ";
            for (int j = 0; j < cols; j++){
                cout << matrixdata[i][j] << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }



};

int main(){

    // initizalize and set matrix values corresponding to assignment
    Matrix A(2, 2);
    A.insertVal(0, 0, 6);
    A.insertVal(0, 1, 4);
    A.insertVal(1, 0, 8);
    A.insertVal(1, 1, 3);
    
    Matrix B(2, 3);
    B.insertVal(0, 0, 1);
    B.insertVal(0, 1, 2);
    B.insertVal(0, 2, 3);
    B.insertVal(1, 0, 4);
    B.insertVal(1, 1, 5);
    B.insertVal(1, 2, 6);

    Matrix C(2, 3);
    C.insertVal(0, 0, 2);
    C.insertVal(0, 1, 4);
    C.insertVal(0, 2, 6);
    C.insertVal(1, 0, 1);
    C.insertVal(1, 1, 3);
    C.insertVal(1, 2, 5);

    // print the starting values
    cout << "A = " << endl;
    A.display();
    cout << "B = " << endl;
    B.display();
    cout << "C = " << endl;;
    C.display();
    cout << endl;

    // calculate matrix D.
    cout << "Calculating Equation...." << endl;
    cout << endl;

    Matrix D(A.solveEquation(B, C));
    cout << "Result:" << endl;
    D.display();
    cout << endl;

    return 0;
}