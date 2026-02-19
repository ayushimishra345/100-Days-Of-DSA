/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100005];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);
    
    int left = 0;
    int right = n - 1;
    
    int min_sum = INT_MAX;     
    int best_left = -1;
    int best_right = -1;
    
    while(left < right) {
        int current_sum = arr[left] + arr[right];
        int abs_sum = abs(current_sum);
        
        if(abs_sum < min_sum) {
            min_sum = abs_sum;
            best_left = left;
            best_right = right;
        }
        
        if(current_sum < 0) {
            left++;
        } else if(current_sum > 0) {
            right--;
        } else {

            best_left = left;
            best_right = right;
            break;
        }
    }
    
    printf("%d %d\n", arr[best_left], arr[best_right]);
    
    return 0;
}
