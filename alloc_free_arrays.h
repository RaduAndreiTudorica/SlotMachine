// Copyright 2024 <Tudorica Radu Andrei>
#pragma once
int alloc_matrix(int ***matrix, int row, int col);
int alloc_vector(int **vector,int length);
void free_matrix(int **matrix, int row);
void free_vector(int *vector,int length);