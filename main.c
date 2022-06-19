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
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    Matrix matrix_1, matrix_2, result; 

    matrix_1 = create_matrix(data,3,3);
    print_matrix(matrix_1);

    print_matrix(zeros_matrix(3,3));

    print_matrix(full_matrix(2,3,5));

    print_matrix(i_matrix(16));

    print_matrix(tile_matrix(matrix_1,3));

    printf("%d\n\n",get_element(matrix_1,2,3));

    put_element(matrix_1,2,3,10);
    print_matrix(matrix_1);

    matrix_2 = create_matrix(data,3,4);
    print_matrix(matrix_2);

    print_matrix(slice(matrix_2, 0, 2, 0, 2));
  
    print_matrix(transpose(matrix_2));
    
    matrix_2 = reshape(matrix_2,6,2);
    print_matrix(matrix_2);
    
    print_matrix(add(matrix_1, matrix_2));
    print_matrix(sub(matrix_1, matrix_2));
    print_matrix(division(matrix_1, matrix_2));
    print_matrix(mul(matrix_1, matrix_2));
  
    printf("Menor valor da Matriz: %d que esta no indice: %d\n", min(matrix_1), argmin(matrix_1));
    printf("Maior valor da Matriz: %d que esta no indice: %d\n", max(matrix_1), argmax(matrix_1));
}
