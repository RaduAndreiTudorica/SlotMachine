// Copyright 2024 <Tudorica Radu Andrei>
#include <stdio.h>
#include <limits.h>
#include "alloc_free_arrays.h"

#define source_vert 0

struct coord {
    int x, y;
};

int absolut(int num1, int num2) {
    if (num1 > num2) {
        return num1 - num2;
    }
    return num2 - num1;
}

int min(int x, int y) {
    if (x > y) {
        return y;
    }
    return x;
}

int neighbor(const int *nodes, int i, int j) {
    struct coord first, second;
    first.x = nodes[i] / 10;
    first.y = nodes[i] % 10;
    second.x = nodes[j] / 10;
    second.y = nodes[j] % 10;

    if (first.x == second.x && absolut(first.y, second.y) == 1) {
        return 1;
    }
    if (first.y == second.y && absolut(first.x, second.x) == 1) {
        return 1;
    }
    return 0;
}

int DistMin(const int *dist, const int *spt, int vertices) {
    int min = INT_MAX, min_index = 0;
    for (int i = 0; i < vertices; i++) {
        if (!spt[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int disjkstra(int **graph, int source, int vertices) {
    int *dist, *spt;
    alloc_vector(&dist, vertices);
    alloc_vector(&spt, vertices);
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        spt[i] = 0;
    }
    dist[source] = 0;
    for (int i = 0; i < vertices - 1; i++) {
        int min = DistMin(dist, spt, vertices);
        spt[min] = 1;
        for (int j = 0; j < vertices; j++) {
            if (!spt[j] && graph[min][j] != -1) {
                if (dist[min] != INT_MAX) {
                    if (dist[min] + graph[min][j] < dist[j]) {
                        dist[j] = dist[min] + graph[min][j];
                    }
                }
            }
        }
    }
    return dist[vertices - 1];
}


int task6(int **a, int col) {
    int row_panel = 3, length = 0;
    int **value, **graph, *nodes;

    alloc_matrix(&value, row_panel, col);
    alloc_vector(&nodes, row_panel * col);

    for (int i = 0; i < row_panel; i++) {
        for (int j = 0; j < col; j++) {
            nodes[length++] = i * 10 + j;
        }
    }
    for (int i = 0; i < row_panel; i++) {
        for (int j = 0; j < col; j++) {
            value[i][j] = absolut(a[0][0], a[i][j]);
        }
    }

    alloc_matrix(&graph, length, length);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (neighbor(nodes, i, j) == 1) {
                graph[i][j] = value[nodes[j] / 10][nodes[j] % 10];
            } else {
                graph[i][j] = -1;
            }
        }
    }

    int dist_min = disjkstra(graph, source_vert, length);

    free_matrix(value, row_panel);
    free_matrix(graph, length);
    free_vector(nodes, length);
    return dist_min;
}
