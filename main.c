// Copyright 2024 <Tudorica Radu Andrei>
#include <stdio.h>
#include "alloc_free_arrays.h"
#include "helper.h"
#include "task3&5.h"

extern int n_combos;

int main() {
    int **a, row, col, score, choice;
    scanf("%d", &choice);

    scanf("%d %d", &row, &col);

    alloc_matrix(&a, row, col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    switch (choice) {
        case 1:
            task1(a, row, col);
            break;
        case 2:
            score = task2(a, col);
            printf("%d\n%d\n", n_combos, score);
            break;
        case 3:
            printf("%d\n", task3(a, row, col));
            break;
        case 4:
            printf("%d\n", task4(a, row, col));
            break;
        case 5:
            printf("%d\n", task5(a, row, col));
            break;
        case 6:
            printf("%d\n", task6(a, col));
            break;
        default:printf("Try something else\n");
    }
    free_matrix(a, row);
    return 0;
}
