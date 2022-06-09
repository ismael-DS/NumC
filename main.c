#include <stdio.h>

#include "matrix.h"

int main() {
    int data[] = {1,2,3,4,5,6,7,8,9}, n;
    Matrix matrix; 

    matrix = zeros_matrix(3,5);
    print_matrix(matrix);
    matrix = full_matrix(4, 8, 22);
    print_matrix(matrix);    
    matrix = transpose(matrix);
    print_matrix(matrix);
    matrix = reshape(matrix, 3, 3);
    print_matrix(matrix);
    matrix = i_matrix(4);
    print_matrix(matrix);
    printf("Menor valor da Matriz: %d que esta no indice: %d\n", min(matrix), argmin(matrix));
    printf("Maior valor da Matriz: %d que esta no indice: %d\n", max(matrix), argmax(matrix));
}