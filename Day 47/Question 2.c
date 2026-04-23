
/*Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100*/

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int depth = 0;

    while (front < rear) {
        int size = rear - front;

        // Process one level
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        depth++;
    }

    return depth;
}
