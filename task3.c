// Copyright 2024 <Tudorica Radu Andrei>
#include <stdio.h>
#include "helper.h"

int task3(int **a, int row, int col) {
    int roll, the_col, score = 0;
    unsigned int rotation;
    scanf("%d", &roll);

    for (int i = 0; i < roll; i++) {
        scanf("%d %u", &the_col, &rotation);
        column_spin(a, row, the_col, rotation);
        score += task2(a, col);
    }
    return score;
}
