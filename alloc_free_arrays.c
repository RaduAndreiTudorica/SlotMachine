// Copyright 2024 <Tudorica Radu Andrei>
#include <stdio.h>
#include <stdlib.h>

int alloc_matrix(int ***matrix, int row, int col) {
    *matrix = malloc(row * sizeof(int *));
    if (!*matrix) {
        printf("error_mat1\n");
        return 1;
    }

    for (int i = 0; i < row; i++) {
        (*matrix)[i] = malloc(col * sizeof(int));
        if (!(*matrix)[i]) {
            printf("error_mat2\n");
            for (int j = 0; j < i; j++) {
                free((*matrix)[j]);
            }
            free(*matrix);
            matrix = NULL;
            return 1;
        }
    }
    return 0;
}

int alloc_vector(int **vector, int lenght) {
    *vector = malloc(lenght * sizeof(int));
    if (!*vector) {
        printf("error_vect\n");
        return 1;
    }
    return 0;
}

void free_matrix(int ***matrix, int row) {
    if (matrix) {
        for (int i = 0; i < row; i++) {
            free(matrix[i]);
        }
        free(matrix);
        matrix = NULL;
    }
}

void free_vector(int *vector) {
    if (vector) {
        free(vector);
    }
}
