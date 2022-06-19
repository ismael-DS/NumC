/**
 * Projeto de Pogramação Estruturada
 * 
 * Professor: Igor Malheiros
 * Alunos: Ismael M. Araujo (20210094680) && Marilia Gabriela T. da Silva (20210067065) 
 * 
 * **/
#include <stdio.h>
#include "matrix.h"

int main() {
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12}, n;
    Matrix matrix1, matrix2, matrix3, matrix4, matrix5, result; 

    matrix1 = create_matrix(data, 3, 4);
    print_matrix(matrix1);
    matrix2 = i_matrix(16);
    print_matrix(matrix2);
    matrix3 = full_matrix(3, 3, 10);
    print_matrix(matrix3);
    matrix4 = zeros_matrix(4, 4);
    print_matrix(matrix4);
    matrix5 = tile_matrix(matrix1, 3);
    print_matrix(matrix5);

    printf("\n%d\n", get_element(matrix1, 2, 3));
    put_element(matrix1, 2, 3, 11);
    print_matrix(matrix1);

    result = transpose(matrix1);
    print_matrix(result);
    result = reshape(matrix1, 3, 3);
    print_matrix(result);
    print_matrix(matrix1);
    print_matrix(slice(matrix1, 0, 2, 0, 2));

    printf("Menor valor da Matriz: %d que esta no indice: %d\n", min(result), argmin(result));
    printf("Maior valor da Matriz: %d que esta no indice: %d\n", max(result), argmax(result));

    matrix4 = add(matrix3, result);
    print_matrix(matrix4);
    matrix5 = sub(matrix3, result);
    print_matrix(matrix5);
    matrix3 = division(matrix5, matrix4);
    print_matrix(matrix3);
    mul(matrix5, result);
} 