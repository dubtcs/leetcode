# 623. Add One Row to Tree 🟡

Given the root of a binary tree and two integers `val` and `depth`, add a row of nodes with value `val` at the given depth de`pth.

Note that the `root` node is at depth `1`.

The adding rule is:

 - Given the integer `depth`, for each not null tree node cur at the depth `depth - 1`, create two tree nodes with value `val` as `cur`'s left subtree root and right subtree root.
 - `cur`'s original left subtree should be the left subtree of the new left subtree root.
 - `cur`'s original right subtree should be the right subtree of the new right subtree root.
 - If `depth == 1` that means there is no depth `depth - 1` at all, then create a tree node with value `val` as the new root of the whole original tree, and the original tree is the new root's left subtree.

### Commentary

 -  I wanted to use a queue, but recursion was easier to read

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
    void dive(TreeNode* cur, int level, int& val, int& depth)
    {
        if(cur == nullptr)
            return;
        if(level == (depth - 1))
        {
            TreeNode* L{ cur->left };
            TreeNode* R{ cur->right };
            cur->left = new TreeNode{ val };
            cur->left->left = L;
            cur->right = new TreeNode{ val };
            cur->right->right = R;
            return;
        }
        else
        {
            level++;
            dive(cur->left, level, val, depth);
            dive(cur->right, level, val, depth);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr)
            return nullptr;

        if(depth == 1)
        {
            TreeNode* bruh{ new TreeNode{ val} };
            bruh->left = root;
            return bruh;
        }
        
        dive(root, 1, val, depth);

        return root;
    }
};
```