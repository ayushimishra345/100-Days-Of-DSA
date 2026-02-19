/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
  */
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100005];  
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int k;
    scanf("%d", &k);
    
    k = k % n;
    if(k == 0) {
        for(int i = 0; i < n; i++) {
            printf("%d", arr[i]);
            if(i < n-1) printf(" ");
        }
        printf("\n");
        return 0;
    }
    
    int rotated[100005];
    
    for(int i = 0; i < k; i++) {
        rotated[i] = arr[n - k + i];
    }
    for(int i = 0; i < n - k; i++) {
        rotated[k + i] = arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d", rotated[i]);
        if(i < n-1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
