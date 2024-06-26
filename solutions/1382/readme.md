# 1382. Balance a Binary Search Tree 🟡

Given the `root` of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

![example](https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg)

### Explanation

The given tree is already in order, it's just not balanced. Using this, you can create a divide and conquer method to balance it in place. Do an in order traversal through the tree on the left side, as in `left->root->right` and store each pointer in a vector. This will be sorted as the tree is a non balanced BST. Then, loop through that vector and set each nodes left pointer to the midpoint array left of itself, and the right pointer to the midpoint of the right array.

```
[ 1 , 2 , 3 , 4 ]
Dive(0, 3) // 0 being start, 3 being last
[(1), 2 , 3 ,(4)]
Divide left side
    Mid point is index 0, as both left and right are 0
    [(1), 2 , 3 , 4 ]
    Set left pointer to index 1
Divide right side
    Mid point is index 2
    [ 1 , 2 ,(3),(4)]
    Divide right side
        Mid point is index 3
        [ 1 , 2 , 3 ,(4)]
        Set right pointer to pointer at index 3
    Divide left side
        Mid point is index 2
        [ 1 ,(2),(3), 4 ]
        Left is less than right, so return nullptr
```

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
    void SetStorage(TreeNode* root, std::vector<TreeNode*>& storage)
    {
        if(root->left)
            SetStorage(root->left, storage);
        storage.push_back(root);
        if(root->right)
            SetStorage(root->right, storage);
        return;
    }
    TreeNode* BalanceNodes(std::vector<TreeNode*>& storage, int left, int right)
    {
        if(right < left)
            return nullptr;
        int mid{ left + ((right - left) / 2) };
        TreeNode*& root{ storage.at(mid) };
        root->left = BalanceNodes(storage, left, mid - 1);
        root->right = BalanceNodes(storage, mid + 1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<TreeNode*> storage{};
        SetStorage(root, storage);
        return BalanceNodes(storage, 0, static_cast<int>(storage.size() - 1));
    }
};
```