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

// Funções para acessar Elementos:

void print_matrix(Matrix matrix){
    int count = 0;

    printf("{{");
    for(int i= 0; i < matrix.n_cols * matrix.n_rows; i+= matrix.stride_cols) {
    
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
  
}

/*
n_rows é o número de linhas da matriz.
• n_cols é o número de colunas da matriz.
1
Uma matriz do tipo:
{{1, 2, 3},
{4, 5, 6},
{7, 8, 9}}
Será guardada como:
{1, 2, 3, 4, 5, 6, 7, 8, 9}
• stride_rows é um número que determina quantos elementos devem ser
“pulados” no array unidimensional para acessar uma próxima linha. No
exemplo acima, considerando o elemento 1 (elemento da primeira linha e da
primeira coluna), se quisermos acessar a próxima linha (elemento 4), temos
que andar 3 elementos no array unidimensional. Assim, stride_rows tem
o valor 3.
• stride_cols é o número que determina quantos elementos devem ser
“pulados” no array unidimensional para acessar a próxima coluna. Com
uma matriz criada, stride_cols vai ser igual a 1, pois para acessar um
elemento de uma próxima coluna basta acessar o próximo índice. Algumas
funções vão modificar esse número, então é importante defini-lo mesmo
que seu valor inicial seja sempre 1.
• offset é o índice de onde devemos começar a considerar os dados do array
unidimensional. Seu valor padrão quando uma matriz for criada é 0, pois
vamos considerar os dados desde o início. Algumas funções vão modificar
esse número, então é importante defini-lo mesmo que seu valor inicial seja
sempre 0. */