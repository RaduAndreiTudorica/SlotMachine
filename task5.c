// Copyright 2024 <Tudorica Radu Andrei>
#include "helper.h"

void column(int **a, int row, int the_col) {
    int aux = a[row - 1][the_col];
    for (int i = row - 1; i > 0; i--) {
        a[i][the_col] = a[i - 1][the_col];
    }
    a[0][the_col] = aux;
}

int task5(int **a, int row, int col) {
    int max_score = 0, score = 0;
    for (int i = 0; i < col - 1; i++) {
        for (int j = i + 1 ; j < col; j++) {
            for (int k = 0; k < row; k++) {
                for (int l = 0; l < row; l++) {
                    score = task2(a, col);
                    if (score > max_score) {
                        max_score = score;
                    }
                    column(a, row, j);
                }
                column(a, row, i);
            }
        }
    }

    return max_score;
}
