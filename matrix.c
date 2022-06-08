#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>
#include <math.h>

Matrix create_matrix(int *data, int n_rows, int n_cols){

  if((n_rows*n_cols)!= (sizeof(*data)/sizeof(data[0])))
  {
    printf("Error\n");
    exit(1);
    }
  
  
  Matrix matrix = {
  data, 
  n_rows, 
  n_cols,
  .stride_rows = n_cols,
  .stride_cols = 1, 
  .offset = 0};

  return matrix;
}


Matrix zeros_matrix(int n_rows, int n_cols){
  int elements = n_rows * n_cols;
  int *arr, count = 0;
  arr = calloc(elements, sizeof(int));
  
  Matrix matrix = {
  arr, 
  n_rows, 
  n_cols,
  .stride_rows = n_cols,
  .stride_cols = 1, 
  .offset = 0};

  return matrix;
  }
 

Matrix full_matrix(int n_rows, int n_cols, int value){
  int elements = n_rows * n_cols;
  int *arr;
  arr = calloc(elements, sizeof(int));

  for(int i= 0;i < elements; i++)
  {
    arr[i] = value;
  }
  
  Matrix matrix = {
  arr, 
  n_rows, 
  n_cols,
  .stride_rows = n_cols,
  .stride_cols = 1, 
  .offset = 0};

  return matrix;
}

Matrix i_matrix(int n){
  
  int y = (int)sqrt(n);
  
  if ((y*y)!= n){
    printf("Error\n");
    exit(1);
    }
  
  Matrix matrix = { 
  .n_rows = y, 
  .n_cols = y,
  .stride_rows = y,
  .stride_cols = 1, 
  .offset = 0};

  int *arr;
  arr = calloc(n, sizeof(int));
  arr[0] = 1;

  for(int i= 0;i < n; i += (matrix.stride_rows+1)){
    arr[i] = 1;
    }

  matrix.data = arr;

  return matrix;
}

void print_matrix(Matrix matrix){
    int count = 0;

    printf("{{");
    for(int i= 0;i < matrix.n_cols * matrix.n_rows; i++) {
    
        count += 1;
        if (count != matrix.n_cols) {    
            printf("%d, ", matrix.data[i]);
        }
        else if (i != matrix.n_cols * matrix.n_rows -1) {
            printf("%d},\n {", matrix.data[i]);
            count = 0;
        }     
        else{
            printf("%d}}\n", matrix.data[i]);
        }
    }
}