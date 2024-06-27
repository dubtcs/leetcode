# 1791. Find Center of Star Graph 🟢

There is an undirected star graph consisting of `n` nodes labeled from `1 to n`. A star graph is a graph where there is one center node and exactly `n - 1` edges that connect the center node with every other node.

You are given a 2D integer array `edges` where each `edges[i] = [ui, vi]` indicates that there is an edge between the nodes `ui` and `vi`. Return the center of the given star graph.

### Explanation

They explain a star graph has a single center node, and all other nodes extend outward in branches. Using this, it's a simple statement that any node with more than 1 connection will be the center. Simple loop through each connection and increment a total connection counter in a structure such as a map or vector. Once one of them has a value greater than 1, you've found the center.

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::unordered_map<int, int> connections{};
        for(std::vector<int>& v : edges)
        {
            connections[v.front()]++;
            connections[v.back()]++;
            if(connections.at(v.front()) >= 2)
                return v.front();
            if(connections.at(v.back()) >= 2)
                return v.back();
        }
        return -1;
    }
};
```