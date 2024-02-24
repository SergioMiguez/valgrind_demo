#include <stdio.h>
#include <stdlib.h>

#define N 100

void multiply_matrices(int A[N][N], int B[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void initialize_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void display_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N];
    int B[N][N];
    int result[N][N];

    // Initialize matrices A and B
    initialize_matrix(A);
    initialize_matrix(B);

    // Multiply matrices
    multiply_matrices(A, B, result);

    // Display the result matrix (for demonstration purposes)
    printf("Result matrix:\n");
    display_matrix(result);

    return 0;
}