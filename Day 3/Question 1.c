/* Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)   
*/
  def linear_search():
    # Input handling
    try:
        n = int(input().strip())
        arr = list(map(int, input().split()))
        k = int(input().strip())
    except ValueError:
        return
    comparisons = 0
    found_index = -1
    for i in range(n):
        comparisons += 1
        if arr[i] == k:
            found_index = i
            break
    if found_index != -1:
        print(f"Found at index {found_index}")
    else:
        print("Not Found")
    print(f"Comparisons = {comparisons}")
if __name__ == "__main__":
    linear_search()
