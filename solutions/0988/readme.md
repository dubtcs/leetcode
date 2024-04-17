# 988. Smallest String Starting From Leaf 🟡

You are given the `root` of a binary tree where each node has a value in the range `[0, 25]` representing the letters `'a'` to `'z'`.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

 - For example, `"ab"` is lexicographically smaller than `"aba"`.

A leaf of a node is a node that has no children.

### Commentary

 - I tired using a simple (temp < best) condition, but it would always return just shortest of the two rather than alphbetical, so I just did some shitass while loop instead

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
    void dive(TreeNode* ptr, std::string& cur, std::string& best)
    {
        if(ptr == nullptr)
            return;

        cur.push_back('a' + ptr->val);
        if(ptr->left || ptr->right)
        {
            dive(ptr->left, cur, best);
            dive(ptr->right, cur, best);
        }
        else
        {
            std::string temp{ cur.rbegin(), cur.rend() };
            if(best.empty())
                best = temp;
            else
            {
                int b{ 0 };
                int t{ 0 };
                while(t < temp.size() && b < best.size())
                {
                    if(temp.at(t) < best.at(b))
                    {
                        best = temp;
                        cur.pop_back();
                        return;
                    }
                    if(temp.at(t) > best.at(b))
                    {
                        cur.pop_back();
                        return;
                    }
                    t++;
                    b++;
                }
                // they both match up to this point
                if(temp.size() < best.size() && temp.back() <= best.at(b - 1))
                    best = temp;
            }
        }
        cur.pop_back();

    }
    string smallestFromLeaf(TreeNode* root) {
        std::string bruh{};
        std::string best{};
        dive(root, bruh, best);
        return best;
    }
};
```