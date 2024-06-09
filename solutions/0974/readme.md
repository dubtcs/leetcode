# 974. Subarray Sums Divisible by K 🟡

Given an integer array `nums` and an integer `k`, return the number of non-empty subarrays that have a sum divisible by `k`.

A subarray is a contiguous part of an array.

### Explanation

*Very* similar to [523.](/solutions/0523)

Loop through `nums`. For each number, add it to `sum`. Check the remainder of this sum. If `rem` is negative, add k to it, to get the real remainder offset. Then, just add the entry of `found` at index `rem` to `count`. Then, increment that entry by one. Every time an existing entry is found, it's added to the counter again because each subarray between those points is also valid.

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum{ 0 };
        int count{ 0 };
        std::unordered_map<int, int> found{};
        found[0] = 1;
        for(int i{ 0 }; i < nums.size(); i++)
        {
            sum += nums.at(i);
            int rem{ sum % k };
            if(rem < 0)
                rem += k;
            count += found[rem];
            found[rem]++;
        }
        return count;
    }
};
```