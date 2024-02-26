#include <stdio.h>
#include <stdlib.h>
#include <valgrind/callgrind.h>

#define N 500

void multiply_matrices(int **A, int **B, int **result, int size) {
    CALLGRIND_START_INSTRUMENTATION;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += A[i][k] * B[k][j];
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
