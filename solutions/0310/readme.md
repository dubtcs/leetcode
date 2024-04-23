# Minimum Height Trees 🟡

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of `n` nodes labelled from `0` to `n - 1`, and an array of `n - 1` edges where e`dges[i] = [ai, bi]` indicates that there is an undirected edge between the two nodes `ai` and `bi` in the tree, you can choose any node of the tree as the root. When you select a node `x` as the root, the result tree has height `h`. Among all possible rooted trees, those with minimum height (i.e. `min(h)`)  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

```cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return { 0 }; // bruh
        
        std::vector<int> sib(n, 0);
        std::unordered_map<int, std::vector<int>> con{};
        for(std::vector<int>& v : edges)
        {
            con[v.front()].push_back(v.back());
            con[v.back()].push_back(v.front());
            sib[v.front()]++;
            sib[v.back()]++;
        }

        std::deque<int> q{};
        for(int i{ 0 }; i < n; i++)
        {
            if(sib.at(i) == 1)
                q.push_back(i);
        }

        while(n > 2)
        {
            std::size_t si{ q.size() };
            n -= si;
            for(int i{ 0 }; i < si; i++)
            {
                int front{ q.front() };
                for(int& n : con.at(front))
                {
                    sib.at(n)--;
                    if(sib.at(n) == 1)
                        q.push_back(n);
                }
                q.pop_front();
            }
        }
        
        return { q.begin(), q.end() };
    }
};
```