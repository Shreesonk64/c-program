#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void addMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to calculate the determinant of a square matrix using Laplace expansion
int determinant(int **matrix, int order) {
    if (order == 1) {
        return matrix[0][0];
    }
    else if (order == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        int det = 0;
        for (int j = 0; j < order; j++) {
            int **submatrix = (int **)malloc((order - 1) * sizeof(int *));
            for (int i = 0; i < order - 1; i++) {
                submatrix[i] = (int *)malloc((order - 1) * sizeof(int));
            }
            for (int i = 1; i < order; i++) {
                int k = 0;
                for (int l = 0; l < order; l++) {
                    if (l != j) {
                        submatrix[i - 1][k] = matrix[i][l];
                        k++;
                    }
                }
            }
            int sign = (j % 2 == 0) ? 1 : -1;
            det += sign * matrix[0][j] * determinant(submatrix, order - 1);
            for (int i = 0; i < order - 1; i++) {
                free(submatrix[i]);
            }
            free(submatrix);
        }
        return det;
    }
}

// Function to input a matrix from the user
void inputMatrix(int **matrix, int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to display the current state of the system
void displaySystemState(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    printf("Matrix 1:\n");
    displayMatrix(matrix1, rows, cols);
    printf("\nMatrix 2:\n");
    displayMatrix(matrix2, rows, cols);
    printf("\nResult Matrix:\n");
    displayMatrix(result, rows, cols);
}

int main() {
    int rows, cols;
    // Get matrix dimensions from the user
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    // Check if matrix is square
    if (rows != cols) {
        printf("Error: Matrix must be square.\n");
        return 1;
    }
    // Allocate memory for matrices
    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }
    // Main menu-driven loop
    int choice;
    do {
        displaySystemState(matrix1, matrix2, result, rows, cols);
        // Get user input
        printf("\nMatrix Calculator\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Find Determinant\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Add Matrices
                inputMatrix(matrix1, rows, cols);
                inputMatrix(matrix2, rows, cols);
                addMatrices(matrix1, matrix2, result, rows, cols);
                break;
            case 2:
                // Subtract Matrices
                inputMatrix(matrix1, rows, cols);
                inputMatrix(matrix2, rows, cols);
                subtractMatrices(matrix1, matrix2, result, rows, cols);
                break;
            case 3:
                // Multiply Matrices
                inputMatrix(matrix1, rows, cols);
                inputMatrix(matrix2, cols, rows); // For matrix multiplication, cols of matrix1 must match rows of matrix2
                multiplyMatrices(matrix1, matrix2, result, rows, cols, rows);
                break;
            case 4:
                // Find Determinant
                printf("Determinant of Matrix 1: %d\n", determinant(matrix1, rows));
                break;
            case 5:
                // Exit the program
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    // Free allocated memory before exiting the program
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
    return 0;
}
