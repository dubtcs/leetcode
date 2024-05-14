# 1219. Path with Maximum Gold 🟡

In a gold mine `grid` of size `m x n`, each cell in this mine has an integer representing the amount of gold in that cell, `0` if it is empty.

Return the maximum amount of gold you can collect under the conditions:

 - Every time you are located in a cell you will collect all the gold in that cell.
 - From your position, you can walk one step to the left, right, up, or down.
 - You can't visit the same cell more than once.
 - Never visit a cell with `0` gold.
 - You can start and stop collecting gold from any position in the grid that has some gold.

```cpp
class Solution {
public:
    int dive(int x, int y, std::vector<std::vector<int>>& grid)
    {
        int temp{ grid.at(y).at(x) };
        if(temp == 0)
            return 0;

        grid.at(y).at(x) = 0;

        int best{ 0 };
        if(x > 0)
            best = dive(x - 1, y, grid);
        if(x < grid.front().size() - 1)
            best = std::max(best, dive(x + 1, y, grid));
        if(y > 0)
            best = std::max(best, dive(x, y - 1, grid));
        if(y < grid.size() - 1)
            best = std::max(best, dive(x, y + 1, grid));
        
        grid.at(y).at(x) = temp;

        return best + temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int best{ 0 };
        for(int y{ 0 }; y < grid.size(); y++)
            for(int x{ 0 }; x < grid.front().size(); x++)
                best = std::max(best, dive(x, y, grid));
        return best;
    }
};
```