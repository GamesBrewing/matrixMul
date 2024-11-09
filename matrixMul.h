#include <stdio.h>
#include <omp.h>

#define N 10 // Size of the matrices


void displayMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiply(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for schedule(static) collapse(2) //parallelize two outer loops using static scheduling.
   
   for (int x = 0; x < N; ++x){ //iterate through row x in A and C
    for (int i = 0; i < N; ++i) { 
         int tempC = 0; //temp variable to hold value for C
        for (int j = 0; j < N; ++j) { 
            tempC += A[j][x] * B [i][j]; // iterate through row x column j of A and column i row j of B.
        }
        C [i][x] = tempC; // fill in element in matrix C  
        tempC = 0;
        
    }
    
   }
}