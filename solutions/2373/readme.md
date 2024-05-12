# 2373. Largest Local Values in a Matrix 🟢

You are given an `n x n` integer matrix `grid`.

Generate an integer matrix `maxLocal` of size `(n - 2) x (n - 2)` such that:

 - `maxLocal[i][j]` is equal to the largest value of the `3 x 3` matrix in `grid` centered around row `i + 1` and column `j + 1`.

In other words, we want to find the largest value in every contiguous `3 x 3` matrix in `grid`.

Return the generated matrix.

```cpp
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        std::size_t bounds{ grid.size() };
        std::vector<std::vector<int>> r(bounds - 2, std::vector<int>(bounds - 2, 0));
        for(int i{ 0 }; i <= bounds - (bounds - 2); i++)
        {
            for(int b{ 0 }; b <= bounds - (bounds - 2); b++)
            {
                
                for(int y{ 0 }; y < bounds - 2; y++)
                {
                    for(int x{ 0 }; x < bounds - 2; x++)
                    {
                        r.at(y).at(x) = std::max(r.at(y).at(x), grid.at(y + i).at(x + b));
                    }
                }
                
            }
        }
        return r;
    }
};
```