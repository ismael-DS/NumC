#include <stdio.h>
#include "matrix.h"

int main() {
    int data[] = {1,2,3,4,5,6,7,8,9}, n;
    Matrix matrix, matriz, result; 

    matriz = create_matrix(data,3,3);
    print_matrix(matriz);

    matrix = full_matrix(3, 3, 10);
    print_matrix(matrix);  

    result = add(matrix,matriz);  
    print_matrix(result);
        print_matrix(matrix);  


    result = sub(result, matrix);  
    print_matrix(result);

    printf("Menor valor da Matriz: %d que esta no indice: %d\n", min(matrix), argmin(matrix));
    printf("Maior valor da Matriz: %d que esta no indice: %d\n", max(matrix), argmax(matrix));
}