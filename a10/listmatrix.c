#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
// A structure for representing a single entry in the matrix.  THis part is stored in the heap
struct MatrixEntry {
    int row;  // the row number of a specific entry
    int col;  // the col number of a specific entry
    int value;
    struct MatrixEntry* next; // Pointer to the next entry in the linked list
};
 
// A structure for representing the sparse matrix. This part is stored in the stack
struct SparseMatrix {
    int num_rows;  // the dimension of the matrix is
    int num_cols;  //  num_rows X num_cols
    struct MatrixEntry* head; // Pointer to the first entry of the linked list
};
 
// Define a function to insert a new entry into the front of the result matrix
// assume all arguments are valid
void insert_entry(struct SparseMatrix* result, int row, int col, int value) {
    if (value == 0) return;
    struct MatrixEntry* new = malloc(sizeof(struct MatrixEntry));
    assert(new);
    new->row = row;
    new->col = col;
    new->value = value;
    assert(result);
    new->next = result->head;
    result->head = new;
}

struct MatrixEntry* find_entry(const struct SparseMatrix* matrix, int row, int col){
    assert(matrix);
    struct MatrixEntry *target = matrix->head;
    while(target){
        if (target->row == row && target->col == col) return target;
        target = target->next;
    }
    return NULL;
}
 
// Define a function that multiplies two sparse matrices with valid sizes
struct SparseMatrix multiply_matrices(const struct SparseMatrix* matrix1, const struct SparseMatrix* matrix2) {
    assert(matrix1);
    assert(matrix2);
    struct SparseMatrix result = {matrix1->num_rows, matrix2->num_cols, NULL};
    for (int i = 0; i < result.num_rows*result.num_cols; i++){
        int curr_row = i/result.num_cols;
        int curr_col = i%result.num_cols;

        int sum = 0;
        for (int j = 0; j < matrix1->num_cols; j++){
            struct MatrixEntry* m1 = find_entry(matrix1, curr_row, j);
            struct MatrixEntry* m2 = find_entry(matrix2, j, curr_col);
            if (!m1 || !m2) continue;
            sum += m1->value*m2->value;
        }

        insert_entry(&result, curr_row, curr_col, sum);

    }
    return result;

}
 

// Function to free memory allocated for a sparse matrix
void free_sparse_matrix(struct SparseMatrix* matrix) {
    assert(matrix);
    struct MatrixEntry *curr = matrix->head;
    while(matrix->head){
        matrix->head = matrix->head->next;
        free(curr);
        curr = matrix->head;
    }
}

// Function to print a sparse matrix
// Do not change this function

void print_sparse_matrix(const struct SparseMatrix* matrix) {
    for (struct MatrixEntry* entry = matrix->head; entry != NULL; entry = entry->next) {
        printf("(%d, %d): %d\n", entry->row, entry->col, entry->value);
    }
}
 
 
// for testing. Do not submit the main function
int main(void) {
    // Create and initialize sparse matrices (matrix3 and matrix4)
    
    struct SparseMatrix matrix3;
    matrix3.num_rows = 3;
    matrix3.num_cols = 4;
    matrix3.head = NULL;
    // Initialize matrix3 with some entries
    insert_entry(&matrix3, 0, 0, 1);
    insert_entry(&matrix3, 1, 1, 2);
    insert_entry(&matrix3, 2, 2, 3);
    insert_entry(&matrix3, 0, 3, 5);
    printf("Matrix3 3x4:\n");
    print_sparse_matrix(&matrix3);
    
    struct SparseMatrix matrix4;
    matrix4.num_rows = 4;
    matrix4.num_cols = 3;
    matrix4.head = NULL;
 
    // Initialize matrix4 with some entries
    insert_entry(&matrix4, 0, 0, 4);
    insert_entry(&matrix4, 1, 1, 5);
    insert_entry(&matrix4, 2, 2, 6);
    insert_entry(&matrix4, 3, 2, 3);
    printf("Matrix4 4x3:\n");
    print_sparse_matrix(&matrix4);
    // Multiply matrices
    struct SparseMatrix result2 = multiply_matrices(&matrix3, &matrix4);
 
    // Print the result matrix
    printf("Result matrix3 x matrix4:\n");
    print_sparse_matrix(&result2);
 
    // Free memory allocated for matrices and result
    free_sparse_matrix(&matrix3);
    free_sparse_matrix(&matrix4);
    free_sparse_matrix(&result2);

    struct SparseMatrix matrix5 = {2,3,NULL};
    insert_entry(&matrix5, 0, 0, 1);
    insert_entry(&matrix5, 0, 1, 2);
    insert_entry(&matrix5, 0, 2, 3);
    insert_entry(&matrix5, 1, 0, 4);
    insert_entry(&matrix5, 1, 1, 5);
    insert_entry(&matrix5, 1, 2, 6);
    printf("Matrix5 2x3:\n");
    print_sparse_matrix(&matrix5);

    struct SparseMatrix matrix6 = {3,2,NULL};
    insert_entry(&matrix6, 0, 0, 1);
    insert_entry(&matrix6, 0, 1, 2);
    insert_entry(&matrix6, 1, 0, 3);
    insert_entry(&matrix6, 1, 1, 4);
    insert_entry(&matrix6, 2, 0, 5);
    insert_entry(&matrix6, 2, 1, 6);
    printf("Matrix6 3x2:\n");
    print_sparse_matrix(&matrix6);

    struct SparseMatrix result3 = multiply_matrices(&matrix5, &matrix6);
 
    // Print the result matrix
    printf("Result matrix5 x matrix5:\n");
    print_sparse_matrix(&result3);

    free_sparse_matrix(&matrix5);
    free_sparse_matrix(&matrix6);
    free_sparse_matrix(&result3);


    struct SparseMatrix matrix1;
    matrix1.num_rows = 15;
    matrix1.num_cols = 16;
    matrix1.head = NULL;
    insert_entry(&matrix1, 1, 13, -4);
    insert_entry(&matrix1, 6, 8, 6);
    insert_entry(&matrix1, 8, 10, -3);
    insert_entry(&matrix1, 8, 6, -2);
    insert_entry(&matrix1, 3, 15, 5);
    insert_entry(&matrix1, 13, 4, 8);
    insert_entry(&matrix1, 2, 15, 9);
    insert_entry(&matrix1, 12, 9, 0);
    insert_entry(&matrix1, 8, 5, 2);
    insert_entry(&matrix1, 14, 13, 1);
    insert_entry(&matrix1, 10, 12, 9);
    insert_entry(&matrix1, 7, 0, 0);
    insert_entry(&matrix1, 1, 15, 9);
    insert_entry(&matrix1, 0, 4, -4);
    insert_entry(&matrix1, 7, 4, -9);
    insert_entry(&matrix1, 9, 11, 2);
    insert_entry(&matrix1, 7, 7, 9);
    insert_entry(&matrix1, 1, 10, 3);
    insert_entry(&matrix1, 1, 5, 2);
    insert_entry(&matrix1, 13, 10, 9);
    insert_entry(&matrix1, 10, 3, -5);
    insert_entry(&matrix1, 7, 5, 5);
    insert_entry(&matrix1, 11, 8, 4);
    insert_entry(&matrix1, 1, 12, 4);
    insert_entry(&matrix1, 6, 2, 0);
    insert_entry(&matrix1, 4, 4, 0);
    insert_entry(&matrix1, 1, 6, 1);
    insert_entry(&matrix1, 14, 2, 9);
    insert_entry(&matrix1, 12, 0, 7);
    insert_entry(&matrix1, 13, 5, -9);
    insert_entry(&matrix1, 1, 3, 5);
    insert_entry(&matrix1, 8, 0, 1);
    insert_entry(&matrix1, 7, 6, -6);
    insert_entry(&matrix1, 7, 15, 0);
    insert_entry(&matrix1, 6, 7, -8);
    insert_entry(&matrix1, 4, 7, 8);
    insert_entry(&matrix1, 6, 4, -8);
    insert_entry(&matrix1, 11, 15, 1);
    insert_entry(&matrix1, 0, 10, -4);
    insert_entry(&matrix1, 9, 5, 6);
    insert_entry(&matrix1, 12, 4, -7);
    insert_entry(&matrix1, 0, 3, 2);
    insert_entry(&matrix1, 10, 10, -1);
    insert_entry(&matrix1, 14, 1, 7);
    insert_entry(&matrix1, 12, 12, 3);
    insert_entry(&matrix1, 8, 2, -9);
    insert_entry(&matrix1, 8, 7, -9);
    insert_entry(&matrix1, 10, 14, 3);
    insert_entry(&matrix1, 2, 8, 7);
    insert_entry(&matrix1, 5, 15, -8);
    insert_entry(&matrix1, 11, 2, -5);
    insert_entry(&matrix1, 3, 5, -5);
    insert_entry(&matrix1, 0, 9, -10);
    insert_entry(&matrix1, 11, 7, -2);
    insert_entry(&matrix1, 14, 3, -5);
    insert_entry(&matrix1, 0, 8, -5);
    insert_entry(&matrix1, 1, 1, -5);
    insert_entry(&matrix1, 7, 14, -6);
    insert_entry(&matrix1, 4, 12, 8);
    insert_entry(&matrix1, 8, 15, 2);
    insert_entry(&matrix1, 5, 7, -7);
    insert_entry(&matrix1, 9, 3, -5);
    insert_entry(&matrix1, 3, 2, -7);
    insert_entry(&matrix1, 10, 7, 2);
    insert_entry(&matrix1, 6, 0, 1);
    insert_entry(&matrix1, 2, 12, 5);
    insert_entry(&matrix1, 5, 10, -4);
    insert_entry(&matrix1, 4, 13, -1);
    insert_entry(&matrix1, 9, 10, 6);
    insert_entry(&matrix1, 2, 6, -2);
    insert_entry(&matrix1, 9, 0, 4);
    insert_entry(&matrix1, 4, 2, 4);
    insert_entry(&matrix1, 5, 3, 6);
    insert_entry(&matrix1, 11, 6, -9);
    insert_entry(&matrix1, 0, 6, 8);
    insert_entry(&matrix1, 11, 10, 5);
    insert_entry(&matrix1, 12, 5, 7);
    insert_entry(&matrix1, 13, 7, -4);
    insert_entry(&matrix1, 0, 1, -6);
    insert_entry(&matrix1, 2, 0, 1);
    insert_entry(&matrix1, 11, 14, -2);
    insert_entry(&matrix1, 5, 13, -3);
    insert_entry(&matrix1, 14, 10, -10);
    insert_entry(&matrix1, 14, 0, 4);
    insert_entry(&matrix1, 7, 3, 2);
    insert_entry(&matrix1, 12, 6, 4);
    insert_entry(&matrix1, 7, 12, 10);
    insert_entry(&matrix1, 12, 14, 10);
    insert_entry(&matrix1, 7, 1, -4);
    insert_entry(&matrix1, 3, 3, 10);
    insert_entry(&matrix1, 0, 15, 10);
    insert_entry(&matrix1, 8, 4, -3);
    insert_entry(&matrix1, 5, 5, -9);
    insert_entry(&matrix1, 14, 11, 7);
    insert_entry(&matrix1, 2, 2, -8);
    insert_entry(&matrix1, 1, 14, -6);
    insert_entry(&matrix1, 5, 2, -5);
    insert_entry(&matrix1, 3, 0, 1);
    insert_entry(&matrix1, 10, 1, 10);
    insert_entry(&matrix1, 9, 8, 6);
    insert_entry(&matrix1, 13, 15, -10);
    insert_entry(&matrix1, 13, 12, 7);
    insert_entry(&matrix1, 10, 8, -5);
    insert_entry(&matrix1, 3, 6, 4);
    insert_entry(&matrix1, 9, 13, -6);
    insert_entry(&matrix1, 4, 11, -1);
    insert_entry(&matrix1, 6, 14, -7);
    insert_entry(&matrix1, 9, 4, 3);
    insert_entry(&matrix1, 3, 4, 9);
    insert_entry(&matrix1, 5, 0, 9);
    insert_entry(&matrix1, 14, 5, 6);
    insert_entry(&matrix1, 4, 0, -3);
    insert_entry(&matrix1, 4, 10, 1);
    insert_entry(&matrix1, 6, 12, -3);
    insert_entry(&matrix1, 7, 8, 9);
    insert_entry(&matrix1, 0, 2, -4);
    insert_entry(&matrix1, 12, 15, 10);
    insert_entry(&matrix1, 11, 0, 5);
    insert_entry(&matrix1, 10, 15, -2);
    insert_entry(&matrix1, 3, 13, -4);
    insert_entry(&matrix1, 13, 14, 3);
    insert_entry(&matrix1, 5, 12, 5);
    insert_entry(&matrix1, 6, 6, 1);
    insert_entry(&matrix1, 3, 12, 8);
    insert_entry(&matrix1, 2, 13, 3);
    insert_entry(&matrix1, 9, 15, -4);
    insert_entry(&matrix1, 10, 6, 4);
    insert_entry(&matrix1, 4, 8, 0);
    insert_entry(&matrix1, 14, 9, 6);
    insert_entry(&matrix1, 3, 1, -8);
    insert_entry(&matrix1, 1, 4, 10);
    insert_entry(&matrix1, 9, 9, 6);
    insert_entry(&matrix1, 7, 9, 2);
    insert_entry(&matrix1, 2, 3, 5);
    insert_entry(&matrix1, 3, 7, 3);
    insert_entry(&matrix1, 10, 9, -6);
    struct SparseMatrix matrix2;
    matrix2.num_rows = 16;
    matrix2.num_cols = 10;
    matrix2.head = NULL;
    insert_entry(&matrix2, 6, 9, 6);
    insert_entry(&matrix2, 12, 9, -2);
    insert_entry(&matrix2, 6, 4, 0);
    insert_entry(&matrix2, 14, 1, -4);
    insert_entry(&matrix2, 6, 7, -9);
    insert_entry(&matrix2, 3, 9, 7);
    insert_entry(&matrix2, 11, 5, 0);
    insert_entry(&matrix2, 3, 6, 9);
    insert_entry(&matrix2, 9, 6, 5);
    insert_entry(&matrix2, 4, 9, 5);
    insert_entry(&matrix2, 3, 4, 9);
    insert_entry(&matrix2, 12, 7, 0);
    insert_entry(&matrix2, 4, 3, 7);
    insert_entry(&matrix2, 15, 5, -2);
    insert_entry(&matrix2, 9, 8, -1);
    insert_entry(&matrix2, 14, 0, -8);
    insert_entry(&matrix2, 4, 0, -6);
    insert_entry(&matrix2, 11, 6, -5);
    insert_entry(&matrix2, 1, 2, 0);
    insert_entry(&matrix2, 15, 4, 5);
    insert_entry(&matrix2, 0, 4, -7);
    insert_entry(&matrix2, 4, 4, -1);
    insert_entry(&matrix2, 12, 8, 6);
    insert_entry(&matrix2, 1, 8, -3);
    insert_entry(&matrix2, 2, 6, 7);
    insert_entry(&matrix2, 4, 8, -2);
    insert_entry(&matrix2, 3, 2, -6);
    insert_entry(&matrix2, 1, 9, 3);
    insert_entry(&matrix2, 1, 1, 3);
    insert_entry(&matrix2, 7, 9, 4);
    insert_entry(&matrix2, 6, 3, -9);
    insert_entry(&matrix2, 11, 1, -5);
    insert_entry(&matrix2, 10, 6, -7);
    insert_entry(&matrix2, 6, 6, 10);
    insert_entry(&matrix2, 7, 1, 1);
    insert_entry(&matrix2, 7, 0, 5);
    insert_entry(&matrix2, 3, 7, 7);
    insert_entry(&matrix2, 5, 3, 10);
    insert_entry(&matrix2, 0, 7, 0);
    insert_entry(&matrix2, 5, 7, 7);
    insert_entry(&matrix2, 2, 5, -8);
    insert_entry(&matrix2, 7, 3, -2);
    insert_entry(&matrix2, 11, 2, -2);

    struct SparseMatrix result = multiply_matrices(&matrix1, &matrix2);
    printf("Result matrix1 x matrix2:\n");
    print_sparse_matrix(&result);

    free_sparse_matrix(&matrix1);
    free_sparse_matrix(&matrix2);
    free_sparse_matrix(&result);

    return 0;
}
