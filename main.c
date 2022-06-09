#include "matrix.h"

int main() {
    int data[] = {1,2,3,4,5,6,7,8,9};
    Matrix matrix; 


    matrix = zeros_matrix(3,5);
    print_matrix(matrix);
    matrix = full_matrix(4, 8, 22);
    print_matrix(matrix);    
    matrix = transpose(matrix);
    print_matrix(matrix);
    matrix = i_matrix(6);
    print_matrix(matrix);

}