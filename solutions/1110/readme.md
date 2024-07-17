# 1110. Delete Nodes And Return Forest 🟡

Given the `root` of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in `to_delete`, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

## Explanation

Do a recursive dive on the root node. At each node, check to see if it is a deleted value. If it is, dive the child nodes, but supply a parent node as nullptr. If the value is not in the deletion list, check to see if the supplied parent is null. If it is, it means this node is the start of a new tree and you can add it to the return list. If not, its just a regular node on an already existing tree.

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
    void CheckTree(TreeNode*& cur, TreeNode* parent, std::vector<TreeNode*>& r, const std::vector<bool>& dels)
    {
        if(dels.at(cur->val))
        {
            if(cur->right)
                CheckTree(cur->right, nullptr, r, dels);
            if(cur->left)
                CheckTree(cur->left, nullptr, r, dels);
            if(parent)
            {
                if(parent->left == cur)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
            delete cur;
        }
        else
        {
            if(parent == nullptr)
                r.push_back(cur);
            if(cur->right)
                CheckTree(cur->right, cur, r, dels);
            if(cur->left)
                CheckTree(cur->left, cur, r, dels);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::vector<TreeNode*> r{};
        std::vector<bool> dels(1001, false);
        for(int& n : to_delete)
            dels[n] = true;
        CheckTree(root, nullptr, r, dels);
        return r;
    }
};
```