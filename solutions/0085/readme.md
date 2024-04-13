# 85. Maximal Rectangle 🔴

Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return its area.

![image](https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg)

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix.front().empty())
            return 0;

        std::vector<int> height(matrix.front().size() + 1, 0);
        int rv{ 0 };
        for(std::vector<char>& row : matrix)
        {
            for(int x{ 0 }; x < row.size(); x++)
                height[x] = (row.at(x) == '1') ? height[x] + 1 : 0;
            
            std::stack<int> depth{};
            for(int i{ 0 }; i < height.size(); i++)
            {
                while(!depth.empty() && height.at(i) < height.at(depth.top()))
                {
                    int curH{ height.at(depth.top()) };
                    depth.pop();
                    int curW{ depth.empty() ? i : i - depth.top() - 1 };
                    rv = std::max(rv, (curW * curH));
                }
                depth.push(i);
            }
        }

        return rv;
    }
};

```