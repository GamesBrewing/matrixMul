#include "matrixMulSeq.h"

// Need to allocate the memory for the matrix when compiling, otherwise I get a segmentation fault. I think it is caused by stack overload.
int ** allocateMatrix ( int n){  
    int** matrix = (int**)malloc(n* sizeof(int*));
    for (int i =0; i < n; ++i){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

int main() {

    
    // Allocation of matrices
    int** A = allocateMatrix(N);
    int** B = allocateMatrix(N);
    int** C = allocateMatrix(N);

    printf("Matrices allocated successfully.\n");

    // Initialize matrices A and B
    for (int i = 0; i < N; ++i) {  //column
        for (int j = 0; j < N; ++j) {  //row
            A[i][j] = 1; 
            B[i][j] = 1;
            C[i][j] = 0;
        }
    }

    printf("Matrices initialized successfully.\n");

    matrixMultiply(A, B, C);

    printf("Matrix multiplication complete!\n");

    // Display the resulting matrix C
    printf("Resulting Matrix C:\n");
    displayMatrix(C);
    return 0;
}

