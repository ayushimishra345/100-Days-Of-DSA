/*
  Given an m x n matrix, return all elements of the matrix in spiral order.

 Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int rows = matrixSize;
    int cols = *matrixColSize;
    int total = rows * cols;
    
    int* result = (int*)malloc(total * sizeof(int));
    *returnSize = total;
    
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    
    int idx = 0;
    
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            result[idx++] = matrix[top][j];
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            result[idx++] = matrix[i][right];
        }
        right--;
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[idx++] = matrix[bottom][j];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[idx++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return result;
}
