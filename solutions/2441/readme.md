# 2441. Largest Positive Integer That Exists With Its Negative 🟢

Given an integer array `nums` that does not contain any zeros, find the largest positive integer `k` such that `-k` also exists in the array.

Return the positive integer `k`. If there is no such integer, return `-1`.

```cpp
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int left{ 0 };
        int right{ static_cast<int>(nums.size() - 1) };
        while(left < right)
        {
            int total{ nums.at(left) + nums.at(right) };
            if(total == 0)
                return nums.at(right);
            else if(total < 0)
                left++;
            else
                right--;
        }
        return (-1);
    }
};
```