/*
Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1
  */


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100005];           
    int freq[100005] = {0};   
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;       
    }
    
    int printed = 0;
    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] > 0) {
            if(printed > 0) printf(" ");
            printf("%d:%d", arr[i], freq[arr[i]]);
            printed++;
            freq[arr[i]] = 0;   
        }
    }
    printf("\n");
    
    return 0;
}
