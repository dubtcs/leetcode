# 1992. Find All Groups of Farmland 🟡

You are given a 0-indexed `m x n` binary matrix `land` where a `0` represents a hectare of forested land and a `1` represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

`land` can be represented by a coordinate system where the top left corner of `land` is `(0, 0)` and the bottom right corner of `land` is `(m-1, n-1)`. Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at `(r1, c1)` and a bottom right corner at `(r2, c2)` is represented by the 4-length array `[r1, c1, r2, c2]`.

Return a 2D array containing the 4-length arrays described above for each group of farmland in `land`. If there are no groups of farmland, return an empty array. You may return the answer in any order.

```cpp
class Solution {
public:
    struct v2
    {
        int x{ 0 };
        int y{ 0 };
    };
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        std::vector<std::vector<int>> groups{};
        for(int y{ 0 }; y < land.size(); y++)
        {
            std::vector<int>& row{ land.at(y) };
            for(int x{ 0 }; x < row.size(); x++)
            {
                if(land.at(y).at(x))
                {
                    std::vector<int> curGroup(4, 0); // range
                    curGroup[0] = y;
                    curGroup[1] = x;
                    std::queue<v2> q{};
                    q.push({x,y});
                    while(!q.empty())
                    {
                        v2 cur{ q.front() };
                        if(land.at(cur.y).at(cur.x))
                        {
                            if(cur.x + 1 < land.front().size())
                                q.push({cur.x + 1, cur.y});
                            if(cur.y + 1 < land.size())
                                q.push({cur.x, cur.y + 1});
                            curGroup[2] = std::max(curGroup[2], cur.y);
                            curGroup[3] = std::max(curGroup[3], cur.x);
                            land.at(cur.y).at(cur.x) = 0;
                        }
                        q.pop();
                    }
                    groups.push_back(curGroup);
                }
            }
        }
        return groups;
    }
};
```