# 200. Number of Islands 🟡

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

### Commentary

 - I wanted to use a queue, so I did.

```cpp
class Solution {
public:
    struct v2
    {
        int x{ 0 };
        int y{ 0 };
    };
    int numIslands(vector<vector<char>>& grid) {
        int total{ 0 };
        for(int y{ 0 }; y < grid.size(); y++)
        {
            std::vector<char>& row{ grid.at(y) };
            for(int x{ 0 }; x < row.size(); x++)
            {
                if(grid.at(y).at(x) == '1')
                {
                    total++;
                    std::queue<v2> q{};
                    q.push({x,y});
                    while(!q.empty())
                    {
                        v2 cur{ q.front() };
                        if(grid.at(cur.y).at(cur.x) == '1')
                        {
                            grid.at(cur.y).at(cur.x) = 'F';
                            if(cur.x + 1 < grid.at(cur.y).size())
                                q.push({cur.x + 1, cur.y});
                            if(cur.x - 1 >= 0)
                                q.push({cur.x - 1, cur.y});
                            if(cur.y + 1 < grid.size())
                                q.push({cur.x, cur.y + 1});
                            if(cur.y - 1 >= 0)
                                q.push({cur.x, cur.y - 1});
                        }
                        q.pop();
                    }
                }
            }
        }
        return total;
    }
};
```