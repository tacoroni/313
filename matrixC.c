#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10

// using a struct instead of a class, to mimic cpp
typedef struct matrix{
    int rows;
    int cols;
    int data[MAX_ROW][MAX_COL];
}matrix;

// initializes the matrix, sets the size and makes everything 0
matrix makeMatrix(int r, int c){
    matrix m;
    m.rows = r;
    m.cols = c;
    for (int i = 0; i < m.rows; i++){
        for (int j = 0; j < m.cols; j++){
            m.data[i][j] = 0;
        }
    }

    return m;
}

void multConstant(int constant, matrix *m){
    int product;
    // iterate and multiply
    for (int i = 0; i < m->rows; i++){
        for (int j = 0; j < m->cols; j++){
            product = (m->data[i][j] * constant);
            m->data[i][j] = product;
        }
    }

}

// easy way to insert matrix values
void insertVal(int rowNum, int colNum, int val, matrix *m){
    m->data[rowNum][colNum] = val;
}

void transpose(matrix *m){
    matrix transpose = makeMatrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; i ++){
        for (int j = 0; j < m->cols; j++){
            transpose.data[j][i] = m->data[i][j];
        }
    }

    // no dynamic allocation in this so this works
    *m = transpose;
}

// used to multiply two matrices
matrix multiplyMatrix(matrix *m1, matrix *m2){
    // make sure columns of m1 == rows of m2
    if (m2->cols != m1->rows){
        return *m1;
    }else{
        matrix product = makeMatrix(m1->rows, m2->cols);
        for (int i = 0; i < m1->rows; i++){
            for (int j = 0; j < m2->cols; j++){
                for (int k = 0; k < m1->cols; k ++){
                    product.data[i][j] += m1->data[i][k] * m2->data[k][j];
                }
            }
        }
        return product;
    }
}

// iterate and display the matrix
void display(matrix m){
    for (int i = 0; i < m.rows; i++){
        printf("[");
        for (int j = 0; j < m.cols; j++){
            printf("%d", m.data[i][j]);
            printf(" ");
        }
        printf("]\n");
    }
    printf("\n");
}

matrix addMatrices(matrix m1, matrix m2){
    // check the dimensions are the same
    if (m1.rows != m2.rows || m1.cols != m2.cols){
            return m1;
        }else{
            // loop through and add
            matrix sum = makeMatrix(m1.rows, m1.cols);
            for (int i = 0; i < m1.rows; i++){
                for (int j = 0; j < m1.cols; j++){
                    sum.data[i][j] = m2.data[i][j] + m1.data[i][j];
                }
            }
            return sum;
        }
        return m1;
}

//D = A+(3*B) * C^T
// used to solve the equation step by step
matrix solveEquation(matrix A, matrix B, matrix C){
    multConstant(3, &B);
    transpose(&C);
    matrix BxCT = multiplyMatrix(&B, &C);
    matrix answer = addMatrices(A, BxCT);
    return answer;
}

int main(){
    // set up the matrices
    matrix A = makeMatrix(2,2);
    insertVal(0, 0, 6,&A);
    insertVal(0, 1, 4, &A);
    insertVal(1, 0, 8, &A);
    insertVal(1, 1, 3, &A);
    matrix B = makeMatrix(2,3);
    insertVal(0, 0, 1, &B);
    insertVal(0, 1, 2, &B);
    insertVal(0, 2, 3, &B);
    insertVal(1, 0, 4, &B);
    insertVal(1, 1, 5, &B);
    insertVal(1, 2, 6, &B);

    matrix C = makeMatrix(2,3);
    insertVal(0, 0, 2, &C);
    insertVal(0, 1, 4, &C);
    insertVal(0, 2, 6, &C);
    insertVal(1, 0, 1, &C);
    insertVal(1, 1, 3, &C);
    insertVal(1, 2, 5, &C);
    // display the starting vals
    printf("A = \n");
    display(A);
    printf("B = \n");
    display(B);
    printf("C = \n");
    display(C);

    printf("Calculating D...\n");
    matrix D = solveEquation(A,B,C);
    display(D);
    return 0;
}