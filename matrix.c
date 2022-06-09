#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>
#include <math.h>

Matrix create_matrix(int *data, int n_rows, int n_cols){

  /*if((n_rows*n_cols)!= (sizeof(*data)/sizeof(data[0]))){
    printf("Error\n");
    exit(1);
  }*/
  
  
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

// Funções para acessar Elementos:

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

//Funções para manipulação de dimensões:

Matrix transpose(Matrix matrix){
  int transpor = matrix.n_rows;

  matrix.n_rows = matrix.n_cols;
  matrix.n_cols = transpor;
  transpor = matrix.stride_rows;
  matrix.stride_rows = matrix.stride_cols;
  matrix.stride_cols = transpor;

  return matrix;
}

Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols){
  /*if (new_n_cols*new_n_rows > sizeof(matrix.data) / sizeof(int) ){
    printf("Error\n");
    exit(1);
  } */ 

  matrix.n_rows = new_n_rows;
  matrix.n_cols = new_n_cols;
  matrix.stride_rows = new_n_cols;

  return matrix;
}

Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce);

// Funções de Agregação:

int min(Matrix matrix){
    int Nmin = 999999;

    for (int i = 0 ; i < matrix.n_cols * matrix.n_rows ; i++){
        if (matrix.data[i] < Nmin){
            Nmin = matrix.data[i];
        }
    }
    
    return Nmin; 
}

int max(Matrix matrix){
    int Nmax = -999999;

    for (int i = 0 ; i < matrix.n_cols * matrix.n_rows ; i++){
        if (matrix.data[i] > Nmax){
            Nmax = matrix.data[i];
        }
    }
    
    return Nmax; 
}

int argmin(Matrix matrix){
    int Nmin = 999999;

    for (int i = 0 ; i < matrix.n_cols * matrix.n_rows ; i++){
        if (matrix.data[i] < Nmin){
            Nmin = i;
        }
    }
    
    return Nmin; 
}

int argmax(Matrix matrix){
    int Nmax = -999999;

    for (int i = 0 ; i < matrix.n_cols * matrix.n_rows ; i++){
        if (matrix.data[i] > Nmax){
            Nmax = i;
        }
    }
    
    return Nmax; 
}