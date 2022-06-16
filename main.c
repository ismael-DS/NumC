#include <stdio.h>
#include "matrix.h"

int main() {
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12}, n;
    Matrix matrix, matriz, result; 

    matrix = create_matrix(data,3,3);
    print_matrix(matrix);

    matriz = slice(matrix,0,2,1,3);
    print_matrix(matriz);

    matriz = create_matrix(data,3,4);
    print_matrix(matriz);

    matrix = transpose(matrix);
    print_matrix(matrix);

    matriz = transpose(matriz);
    print_matrix(matriz);

    printf("Menor valor da Matriz: %d que esta no indice: %d\n", min(matrix), argmin(matrix));
    printf("Maior valor da Matriz: %d que esta no indice: %d\n", max(matrix), argmax(matrix));
} 