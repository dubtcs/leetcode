# 3068. Find the Maximum Sum of Node Values 🔴

There exists an undirected tree with `n` nodes numbered `0` to `n - 1`. You are given a 0-indexed 2D integer array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates that there is an edge between nodes `ui` and `vi` in the tree. You are also given a positive integer `k`, and a 0-indexed array of non-negative integers `nums` of length `n`, where `nums[i]` represents the value of the node numbered `i`.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

Choose any edge `[u, v]` connecting the nodes `u` and `v`, and update their values as follows:

 - `nums[u] = nums[u] XOR k`
 - `nums[v] = nums[v] XOR k`

Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.

```cpp
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int mods{ 0 };
        int mins{ std::numeric_limits<int>::max() };
        long long r{ 0 };
        for(int& n : nums)
        {
            int xorx{ n ^ k };
            if(xorx > n)
            {
                r += xorx;
                mods++;
                mins = std::min(mins, xorx - n);
            }
            else
            {
                r += n;
                mins = std::min(mins, n - xorx);
            }
        }
        if(mods % 2)
            r -= mins;
        return r;
    }
};
```