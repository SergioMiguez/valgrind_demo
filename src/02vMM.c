#include <stdio.h>
#include <stdlib.h>
#include <valgrind/callgrind.h>
#include <valgrind/cachegrind.h>

#define N 500
#define BLOCK_SIZE 19

void multiply_matrices(int **A, int **B, int **result, int size) {
    CALLGRIND_START_INSTRUMENTATION;
    for (int i = 0; i < size; i += BLOCK_SIZE) {
        for (int j = 0; j < size; j += BLOCK_SIZE) {
            for (int k = 0; k < size; k += BLOCK_SIZE) {
                // Block matrix multiplication
                for (int ii = i; ii < i + BLOCK_SIZE; ++ii) {
                    for (int jj = j; jj < j + BLOCK_SIZE; ++jj) {
                        for (int kk = k; kk < k + BLOCK_SIZE; ++kk) {
                            result[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
    CALLGRIND_STOP_INSTRUMENTATION;
}

int **allocate_matrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; ++i) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}

void initialize_matrix(int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void display_matrix(int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void deallocate_matrix(int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int size = N;
    int **A = allocate_matrix(size);
    int **B = allocate_matrix(size);
    int **result = allocate_matrix(size);

    // Initialize matrices A and B
    initialize_matrix(A, size);
    initialize_matrix(B, size);

    // Multiply matrices
    multiply_matrices(A, B, result, size);

    // Display the result matrix (for demonstration purposes)
    printf("Result matrix:\n");
    display_matrix(result, size);

    // Free dynamically allocated memory
    deallocate_matrix(A, size);
    deallocate_matrix(B, size);
    deallocate_matrix(result, size);

    return 0;
}
