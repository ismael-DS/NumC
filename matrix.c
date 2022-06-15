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
  int *arr;
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
  
  if ((y*y)!= n)
  {
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

Matrix tile_matrix(Matrix matrix, int reps) {

  Matrix matrix_rep = {.n_rows = matrix.n_rows * reps,
                       .n_cols = matrix.n_cols,
                       .stride_rows = matrix.n_cols,
                       .stride_cols = 1,
                       .offset = 0};

  
  int elements_og = matrix.n_rows * matrix.n_cols;
  int elements_rep = elements_og * reps;
  int *arr;
  arr = calloc(elements_rep, sizeof(int));
  int *p = &arr[0];
  

  for (int i = 0; i < elements_rep; i++) 
  {
    arr[i] = matrix.data[i];
      if (i==elements_og)
        arr[elements_og++] = *p++;
    }

  matrix_rep.data = arr;

  return matrix_rep;
}

int get_element(Matrix matrix, int ri, int ci){
  int element;
    if (ri == 1){
      element = matrix.data[ci-1];}
    else
    {
      element = matrix.data[(matrix.n_cols * (ri-1) + ci)-1];}

  return element;
}

void put_element(Matrix matrix, int ri, int ci, int elem){
  if (ri == 1){
      matrix.data[ci-1] = elem;}
    else
    {
      matrix.data[(matrix.n_cols * (ri-1) + ci)-1] = elem;}

}

void print_matrix(Matrix matrix){    
  int elements = matrix.n_cols * matrix.n_rows, i = matrix.offset, j = 0;
   
  printf("{{");
  while (i != elements-1){
    j++;
    if (j == matrix.n_cols){
      printf("%d}, \n {", matrix.data[i]);
      j = 0;
    } else printf("%d, ", matrix.data[i]);
    
    i += matrix.stride_cols;

    if(i > elements -1){
      i -= elements -1;
    }
  }
  printf("%d}}\n", matrix.data[elements-1]);
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

Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce){

/*slice retorna um “recorte” da matriz original.
• a_matrix é a matriz original
• rs é o índice da linha inicial do recorte
• re é o índice da linha final do recorte
• cs é o índice da coluna inicial do recorte
• ce é o índice da coluna final do recorte
Dada a matriz:
Matrix my_matrix;
int data[] = {1,2,3,4,5,6,7,8,9};
my_matrix = create_matrix(data, 3, 3);
A chamada:
my_matrix = slice(my_matrix, 0, 2, 1, 3);
vai cortar my_matrix começando na linha 0 e indo até a linha de índice 1, e
começando na coluna 1 e indo até a coluna de índice 2. É importante ressaltar
que se re for 2 o índice final é 1, e se re for 3 o índice final é 2. Então, o índice
final é sempre subtraído de 1.*/
 

}

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

// Funções Aritmeticas:

Matrix add(Matrix matrix_1, Matrix matrix_2){
  if ((matrix_1.n_cols * matrix_1.n_rows) != (matrix_2.n_cols * matrix_2.n_rows)) {
    printf("Error: As matrizes envolvidas na adição devem ser da mesma ordem \n");
    exit(1);}

  Matrix matrix_result = matrix_1;
  
  for (int i = 0; i < matrix_result.n_cols * matrix_result.n_rows; i++){
    matrix_result.data[i] = matrix_1.data[i + matrix_1.offset] + matrix_2.data[i + matrix_2.offset];}
  
  return matrix_result;
  }

Matrix sub(Matrix matrix_1, Matrix matrix_2){
  if ((matrix_1.n_cols * matrix_1.n_rows) != (matrix_2.n_cols * matrix_2.n_rows)) {
    printf("Error: As matrizes envolvidas na subtração devem ser da mesma ordem \n");
    exit(1);}

  Matrix matrix_result = matrix_1;
  
  for (int i = 0; i < matrix_result.n_cols * matrix_result.n_rows; i++){
    matrix_result.data[i] = matrix_1.data[i + matrix_1.offset] - matrix_2.data[i + matrix_2.offset];}
  
  return matrix_result;
  }

Matrix mul(Matrix matrix_1, Matrix matrix_2){
  if (matrix_1.n_cols != matrix_2.n_rows) {
    printf("Error: As matrizes envolvidas nessa operação devem ter o numero de colunas da primeira igual ao numero de linhas da segunda\n");
    exit(1);}
  
  Matrix matrix_result = {.n_rows = matrix_1.n_rows,
                          .n_cols = matrix_2.n_cols,
                          .stride_rows = matrix_2.n_cols,
                          .stride_cols = 1,
                          .offset = 0,
                          .data = matrix_1.data};

  for (int i = 0; i < matrix_result.n_cols * matrix_result.n_rows; i++){
    matrix_result.data[i] = matrix_1.data[i + matrix_1.offset] - matrix_2.data[i + matrix_2.offset];}
  
  return matrix_result;

}

Matrix division(Matrix matrix_1, Matrix matrix_2);
