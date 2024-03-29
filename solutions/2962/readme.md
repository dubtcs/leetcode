# 2962. Count Subarrays Where Max Element Appears at Least K Times 🟡

You are given an integer array ```nums``` and a positive integer ```k```.

Return the number of subarrays where the maximum element of ```nums``` appears at least ```k``` times in that subarray.

A subarray is a contiguous sequence of elements within an array.

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int most{ *std::max_element(nums.begin(), nums.end()) };
        
        // window param
        int amount{ 0 };
        // ptrs
        int left{ 0 };
        int right{ 0 };

        // keep the window at exactly k occurrences
        // use the left pointer as a counter
        // this will shrink and expand adding arrays until the left pointer shrinks to less than k
        // the left pointer will then be at index of the amount of subarrays for that pass
        long long count{ 0 };
        while(right < nums.size())
        {
            if(nums.at(right++) == most)
                amount++;
            while(amount == k)
            {
                if(nums.at(left++) == most)
                    amount--;
            }
            count += left;
        }
        
        return count;
    }
};
```