# 2958. Length of Longest Subarray With at Most K Frequency 🟡

You are given an integer array ```nums``` and an integer ```k```.

The frequency of an element ```x``` is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to ```k```.

Return the length of the longest good subarray of ```nums```.

A subarray is a contiguous non-empty sequence of elements within an array.

### Commentary

 - I originally did this with a variable tracking the length of the current window, but that ended up being like 80ms slower than pointer subtraction.

Pointer subtraction
```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts{};
        int highest{ 0 };
        int right{ 0 };
        int left{ 0 };
        while(right < nums.size())
        {
            counts[nums.at(right)]++;
            if(counts.at(nums.at(right)) > k)
            {
                while(left < nums.size() && nums.at(left) != nums.at(right))
                    counts[nums.at(left++)]--;
                if(left < nums.size())
                {
                    counts[nums.at(left)]--;
                    left++;
                }
            }
            highest = std::max(highest, (right - left) + 1);
            right++;
        }
        return highest;
    }
};
```

Length variable
```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts{};
        int highest{ 0 };
        int right{ 0 };
        int left{ 0 };
        int cur{ 0 };
        while(right < nums.size())
        {
            counts[nums.at(right)]++;
            cur++;
            if(counts.at(nums.at(right)) > k)
            {
                while(left < nums.size() && nums.at(left) != nums.at(right))
                {
                    counts[nums.at(left++)]--;
                    cur--;
                }
                if(left < nums.size())
                {
                    counts[nums.at(left)]--;
                    left++;
                    cur--;
                }
            }
            highest = std::max(highest, cur);
            right++;
        }
        return highest;
    }
};
```
