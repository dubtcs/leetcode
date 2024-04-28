# 834. Sum of Distances in Tree 🔴

There is an undirected connected tree with `n` nodes labeled from `0` to `n - 1` and `n - 1` edges.

You are given the integer `n` and the array `edges` where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the tree.

Return an array `answer` of length `n` where `answer[i]` is the sum of the distances between the `ith` node in the tree and all other nodes.

### Commentary

 - I want to check out so bad

```cpp
class Solution {
public:
    using adjlist = std::unordered_map<int, std::vector<int>>;
    void MakeRelations(int index, int parent, std::unordered_map<int, std::vector<int>>& adj, std::vector<int>& connections, std::vector<int>& distances)
    {
        for(int& i : adj.at(index))
        {
            if(i != parent)
            {
                MakeRelations(i, index, adj, connections, distances);
                connections[index] += connections[i];
                distances[index] += connections[i] + distances[i];
            }
        }
    }
    void CheckAsRoot(int index, int parent, int& n, std::unordered_map<int, std::vector<int>>& adj, std::vector<int>& connections, std::vector<int>& distances)
    {
        for(int& i : adj.at(index))
        {
            if(i != parent)
            {
                distances[i] = distances[index] + n - (2 * connections[i]);
                CheckAsRoot(i, index, n, adj, connections, distances);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(edges.empty())
            return { 0 };

        std::vector<int> distances(n, 0);
        std::vector<int> connections(n, 1);

        std::unordered_map<int, std::vector<int>> adj{};
        for(std::vector<int>& edge : edges)
        {
            adj[edge.front()].push_back(edge.back());
            adj[edge.back()].push_back(edge.front());
        }

        MakeRelations(0, -456, adj, connections, distances);
        // for(int& n : connections)
        //     std::cout << n << " ";
        // std::cout << '\n';
        // for(int& n : distances)
        //     std::cout << n << " ";
        CheckAsRoot(0, -234, n, adj, connections, distances);
        
        return distances;
    }
};
```