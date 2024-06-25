# 1038. Binary Search Tree to Greater Sum Tree 🟡

Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

 - The left subtree of a node contains only nodes with keys less than the node's key.
 - The right subtree of a node contains only nodes with keys greater than the node's key.
 - Both the left and right subtrees must also be binary search trees.

### Explanation

Use DFS to navigate down the right side of each subtree. Use inorder traversal on the right side, meaning `right->root->left`, to adjust the sum and change the current nodes value. You want to add each nodes value to the sum, then set the nodes value to that sum.

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void GetSum(TreeNode* root, int& sum)
    {
        if(root->right)
            GetSum(root->right, sum);
        sum += root->val;
        root->val = sum;
        if(root->left)
            GetSum(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum{ 0 };
        GetSum(root, sum);
        return root;
    }
};
```