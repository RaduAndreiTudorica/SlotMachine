// Copyright 2024 <Tudorica Radu Andrei>
#include <stdio.h>

void column_spin(int **a, int row, int the_col, unsigned int rotation) {
    while (rotation--) {
        int aux = a[row - 1][the_col];
        for (int i = row - 1; i > 0; i--) {
            a[i][the_col] = a[i - 1][the_col];
        }
        a[0][the_col] = aux;
    }
}

int task1(int **a, int row, int col) {
    int the_col;
    unsigned int rotation;

    scanf("%d %u", &the_col, &rotation);
    column_spin(a, row, the_col, rotation);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
