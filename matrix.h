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