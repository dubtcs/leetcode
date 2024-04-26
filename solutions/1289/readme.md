# 1289 Minimim Falling Path Sum II 🔴

Given an `n x n` integer matrix `grid`, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of `grid` such that no two elements chosen in adjacent rows are in the same column.

~[img](https://assets.leetcode.com/uploads/2021/08/10/falling-grid.jpg)

### Commentary

 - For a while, I thought the previous choice had to be +/- 1 from the current column. Didn't realize it could be any column that isn't the current one for a bit :\

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        std::vector<int> prev{ grid.front() };
        std::vector<int> cur(prev.size(), 0);

        for(int y{ 1 }; y < grid.size(); y++)
        {
            cur = grid.at(y);
            for(int x{ 0 }; x < prev.size(); x++)
            {
                int best{ std::numeric_limits<int>::max() };
                for(int x2{ 0 }; x2 < prev.size(); x2++)
                {
                    if(x2 != x)
                        best = std::min(best, prev.at(x2));
                }
                cur.at(x) = grid.at(y).at(x) + best;
            }
            prev = cur;
        }

        return *std::min_element(prev.begin(), prev.end());
    }
};
```