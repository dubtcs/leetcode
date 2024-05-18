# 979. Distribute Coins in Binary Tree 🟡

You are given the `root` of a binary tree with `n` nodes where each `node` in the tree has `node.val` coins. There are `n` coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

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
    int dc(TreeNode* root, int& tot)
    {
        int moves{ 0 };
        if(root->left)
        {
            int t{ dc(root->left, tot) };
            tot += std::abs(t);
            moves += t;
        }
        if(root->right)
        {
            int t{ dc(root->right, tot) };
            tot += std::abs(t);
            moves += t;
        }
        return ((root->val - 1) + moves);
    }
    int distributeCoins(TreeNode* root) {
        int moves{ 0 };
        dc(root, moves);
        return moves;
    }
};
```