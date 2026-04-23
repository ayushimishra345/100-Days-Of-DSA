"""Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 

The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.
Constraints:
1 ≤ size of linked list ≤ 105"""

class Node:
    def __init__(self, val):
        self.data = val
        self.next = None

class Solution:
    def removeLoop(self, head: Node) -> None:
        if head is None or head.next is None:
            return

        slow = head
        fast = head

        # Step 1: Detect cycle using Floyd’s algorithm
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break

        # If no cycle
        if fast is None or fast.next is None:
            return

        # Step 2: Find start of cycle
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        # Step 3: Break the cycle
        cycle_start = slow
        temp = cycle_start
        while temp.next != cycle_start:
            temp = temp.next
        temp.next = None