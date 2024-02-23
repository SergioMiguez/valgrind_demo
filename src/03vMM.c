#include <stdio.h>
#include <stdlib.h>

#define N 100
#define BLOCK_SIZE 10

void multiply_matrices(int A[N][N], int B[N][N], int result[N][N]) {
    for (int i = 0; i < N; i += BLOCK_SIZE) {
        for (int j = 0; j < N; j += BLOCK_SIZE) {
            for (int k = 0; k < N; k += BLOCK_SIZE) {
                // Block matrix multiplication
                for (int ii = i; ii < i + BLOCK_SIZE; ++ii) {
                    for (int kk = k; kk < k + BLOCK_SIZE; ++kk) {
                        for (int jj = j; jj < j + BLOCK_SIZE; ++jj) {
                            result[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int A[N][N];
    int B[N][N];
    int result[N][N];

    // Initialize matrices A and B
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Multiply matrices
    multiply_matrices(A, B, result);

    // Display the result matrix (for demonstration purposes)
    printf("Result matrix:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
