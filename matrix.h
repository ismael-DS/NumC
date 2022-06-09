typedef struct {
int *data;
int n_rows;
int n_cols;
int stride_rows;
int stride_cols;
int offset;
} Matrix;

Matrix i_matrix(int n);
Matrix full_matrix(int n_rows, int n_cols, int value);
Matrix zeros_matrix(int n_rows, int n_cols);
Matrix create_matrix(int *data, int n_rows, int n_cols);

void print_matrix(Matrix matrix);

Matrix transpose(Matrix matrix);
Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols);
Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce);
