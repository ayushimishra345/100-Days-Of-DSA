/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. 
For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: 
[1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], 
and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.
*/
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

long long countZeroSumSubarrays(int n, int arr[]) {
    long long *prefix_sums = (long long *)malloc((n + 1) * sizeof(long long));
    prefix_sums[0] = 0;
    
    for (int i = 0; i < n; i++) {
        prefix_sums[i + 1] = prefix_sums[i] + arr[i];
    }

    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    long long total_count = 0;
    long long current_freq = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            current_freq++;
        } else {
            total_count += (current_freq * (current_freq - 1)) / 2;
            current_freq = 1;
        }
    }
    total_count += (current_freq * (current_freq - 1)) / 2;

    free(prefix_sums);
    return total_count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", countZeroSumSubarrays(n, arr));

    free(arr);
    return 0;
}
