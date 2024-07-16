# 2096. Step-By-Step Directions From a Binary Tree Node to Another 🟡

You are given the `root` of a binary tree with `n` nodes. Each node is uniquely assigned a value from `1` to `n`. You are also given an integer `startValue` representing the value of the start node `s`, and a different integer `destValue` representing the value of the destination node `t`.

Find the shortest path starting from node `s` and ending at node `t`. Generate step-by-step directions of such path as a string consisting of only the uppercase letters `'L'`, `'R'`, and `'U'`. Each letter indicates a specific direction:

 - `'L'` means to go from a node to its left child node.
 - `'R'` means to go from a node to its right child node.
 - `'U'` means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node `s` to node `t`.

## Explanation

Dive through the tree keeping track of the current path. When either the start or end values are seen, save the path for later. Once you're done traversing, iterator over each path and remove similar steps. If both nodes have a common path up to a point, it can be ignored. If the path to the starting node is `LLR` and the destination is `LLL` you can remove the first two `L` steps as they are just getting to the path from root, not start. Once that is done, just convert all steps in the remainder of the `start` path to `U`, as the path must go up from that node, never left or right.

### NOTE

Use backtracking and recursion or you will encounter memory issues. Keep track of the path as a string refernce and push/pop after each call.

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
    std::string startPath{};
    std::string endPath{};
    bool sfound{ false };
    bool efound{ false };
    void FindNode(TreeNode*& cur, std::string& str, const int& start, const int& dest)
    {
        if(cur->val == start)
        {
            startPath = str;
            sfound = true;
        }
        else if(cur->val == dest)
        {
            endPath = str;
            efound = true;
        }
        if(efound && sfound)
            return;
        
        if(cur->right)
        {
            str.push_back('R');
            FindNode(cur->right, str, start, dest);
            str.pop_back();
        }
        if(cur->left)
        {
            str.push_back('L');
            FindNode(cur->left, str, start, dest);
            str.pop_back();
        }

        return;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string path{};
        FindNode(root, path, startValue, destValue);
        if(startPath.empty())
            return endPath;
        int commonIndex{ 0 };
        while(commonIndex < startPath.size() && commonIndex < endPath.size() && (startPath.at(commonIndex) == endPath.at(commonIndex)))
            commonIndex++;
        for(int i{ commonIndex }; i < startPath.size(); i++)
            startPath.at(i) = 'U';

        std::string r{ startPath.begin() + commonIndex, startPath.end() };
        r += {endPath.begin() + commonIndex, endPath.end()};
        return r;
    }
};
```