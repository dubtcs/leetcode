# 2812. Find the Safest Path in a Grid 🟡 (but really a 🔴)

You are given a 0-indexed 2D matrix `grid` of size `n x n`, where `(r, c)` represents:

 - A cell containing a thief if `grid[r][c] = 1`
 - An empty cell if `grid[r][c] = 0`

You are initially positioned at cell `(0, 0)`. In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell `(n - 1, n - 1)`.

An adjacent cell of cell `(r, c)`, is one of the cells `(r, c + 1)`, `(r, c - 1)`, `(r + 1, c)` and `(r - 1, c)` if it exists.

The Manhattan distance between two cells `(a, b)` and `(x, y)` is equal to `|a - x| + |b - y|`, where `|val|` denotes the absolute value of val.

### Commentary

 - Jesus Christ

```cpp
class Solution {
public:
    struct v2{
        int x{ 0 };
        int y{ 0 };
    };
    const std::vector<v2> dirs{
        {-1,  0},
        { 1,  0},
        { 0, -1},
        { 0,  1}
    };
    void thedollar(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& s, std::size_t& bounds)
    {
        std::queue<v2> q{};

        for(int y{ 0 }; y < bounds; y++)
        {
            for(int x{ 0 }; x < bounds; x++)
            {
                if(grid.at(y).at(x))
                {
                    s[y][x] = 0;
                    q.push({x,y});
                }
            }
        }

        while(!q.empty())
        {
            v2& cur{ q.front() };

            for(const v2& v : dirs)
            {
                v2 other{ cur.x + v.x, cur.y + v.y };
                int target{ s.at(cur.y).at(cur.x) + 1 };
                if(other.x >= 0 && other.x < bounds && other.y >= 0 && other.y < bounds && s.at(other.y).at(other.x) > target)
                {
                    s[other.y][other.x] = target;
                    q.push(other);
                }
            }

            q.pop();
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if(grid.front().front() || grid.back().back())
            return 0;

        std::size_t bounds{ grid.size() };
        std::vector<std::vector<int>> s(bounds, std::vector<int>(bounds, std::numeric_limits<int>::max()));
        std::vector<std::vector<bool>> v(bounds, std::vector<bool>(bounds, false));
        
        thedollar(grid, s, bounds);

        //std::priority_queue<std::pair<int, v2>> q{};
        std::priority_queue<std::pair<int, std::pair<int, int>>> q{};
        q.push({s.front().front(), {0, 0}});

        while(!q.empty())
        {
            int cur{ q.top().first };
            v2 cpos{ q.top().second.first, q.top().second.second };
            q.pop();

            if(cpos.x == (bounds - 1) && cpos.y == (bounds - 1))
                return cur;
            
            v.at(cpos.y).at(cpos.x) = true;

            for(const v2& vo : dirs)
            {
                v2 other{ cpos.x + vo.x, cpos.y + vo.y };
                if(other.x >= 0 && other.x < bounds && other.y >= 0 && other.y < bounds && !v.at(other.y).at(other.x))
                {
                    v.at(other.y).at(other.x) = true;
                    int sc{ std::min(cur, s.at(other.y).at(other.x)) };
                    q.push({sc, {other.x, other.y}});
                }
            }
            
        }

        return 0;
    }
};
```