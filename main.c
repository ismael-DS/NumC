#include "matrix.h"

int main() {
    int arr[9] = {10, 12, 14,
                   11, 30, 40,
                   10, 12, 14};
    Matrix matrix; 

    matrix = zeros_matrix(3,5);
    print_matrix(matrix);
    matrix = full_matrix(4, 8, 22);
    print_matrix(matrix);
    matrix = i_matrix(5);
    print_matrix(matrix);
}