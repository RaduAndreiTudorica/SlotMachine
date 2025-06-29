// Copyright 2024 <Tudorica Radu Andrei>
#include "alloc_free_arrays.h"
#include "helper.h"
#include <stdlib.h>
#include <string.h>

#define symbol 9

int task4(int **a, int row, int col) {
    int **copy_a, possible_win = 0, max_possible_win = 0;

    alloc_matrix(&copy_a, row, col);

    for (int i = 0; i < row; i++) {
        memcpy(copy_a[i], a[i], col * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int t = 0; t <= symbol; t++) {
                copy_a[i][j] = t;
                possible_win = task2(copy_a, col);
                if (possible_win > max_possible_win) {
                    max_possible_win = possible_win;
                }
            }
            copy_a[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        free(copy_a[i]);
    }
    free(copy_a);
    return max_possible_win;
}
