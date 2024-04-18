# 463. Island Perimeter 🟢

You are given `row x col` `grid` representing a map where `grid[i][j] = 1` represents land and `grid[i][j] = 0` represents water.

Grid cells are connected horizontally/vertically (not diagonally). The `grid` is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int per{ 0 };
        for(int y{ 0 }; y < grid.size(); y++)
        {
            std::vector<int>& row{ grid.at(y) };
            for(int x{ 0 }; x < row.size(); x++)
            {
                if(row.at(x))
                {
                    per += ((x - 1) < 0)            ? 1 : !row.at(x - 1);
                    per += ((x + 1) >= row.size())  ? 1 : !row.at(x + 1);
                    per += ((y - 1) < 0)            ? 1 : !grid.at(y - 1).at(x);
                    per += ((y + 1) >= grid.size()) ? 1 : !grid.at(y + 1).at(x);
                }
            }
        }
        return per;
    }
};
```
