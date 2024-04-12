# 42. Trapping Rain Water 🔴

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

![image](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left{ 0 };
        int right{ static_cast<int>(height.size() - 1) };
        int leftMost{ height.front() };
        int rightMost{ height.back() };
        int total{ 0 };
        while(left < right)
        {
            if(leftMost <= rightMost)
            {
                total += (leftMost - height.at(left++)); // adjust left ptr before next line
                leftMost = std::max(leftMost, height.at(left));
            }
            else
            {
                total += (rightMost - height.at(right--)); // adjust right ptr before next line
                rightMost = std::max(rightMost, height.at(right));
            }
        }
        return total;
    }
};
```