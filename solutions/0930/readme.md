# 930. Binary Subarrays With Sum 🟡

Given a binary array ```nums``` and an integer ```goal```, return the number of non-empty subarrays with a sum ```goal```.

A **subarray** is a contiguous part of the array.

```cpp
class Solution {
public:
    int bruh(std::vector<int>& nums, int goal)
    {
        int r{ 0 };
        int left{ 0 };
        int right{ 0 };
        int sum{ 0 };
        for(; right < nums.size(); right++)
        {
            sum += nums[right];
            while(sum > goal && left <= right)
            {
                sum -= nums[left];
                left++;
            }
            r += right - left + 1;
        }
        return r;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return bruh(nums, goal) - bruh(nums, goal - 1);
    }
};
```
