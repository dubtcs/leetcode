# 861. Score After Flipping Matrix 🟡

You are given an `m x n` binary matrix `grid`.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all `0`'s to `1`'s, and all `1`'s to `0`'s).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

![image](https://assets.leetcode.com/uploads/2021/07/23/lc-toogle1.jpg)

```cpp
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int best{ (1 << (static_cast<int>(grid.front().size()) - 1)) * static_cast<int>(grid.size()) };

        for(int i{ 1 }; i < grid.front().size(); i++)
        {
            int temp{ 0 };
            for(int b{ 0 }; b < grid.size(); b++)
            {
                if(grid.at(b).at(i) == grid.at(b).front())
                    temp++;
            }
            best += (1 << (grid.front().size() - i - 1)) * std::max(temp, static_cast<int>(grid.size()) - temp);
        }
        
        return best;
    }
};
```
