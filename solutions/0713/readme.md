# 713. Subarray Product Less Than K 🟡

Given an array of integers ```nums``` and an integer ```k```, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than ```k```.

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count{ 0 };
        int left{ 0 };
        int right{ 0 };
        int product{ 1 };
        for(; right < nums.size(); right++)
        {
            int& n{ nums.at(right) };
            product *= n;
            while(product >= k && left <= right)
                product /= nums.at(left++);
            count += (right - left + 1);
        }
        return count;
    }
};
```