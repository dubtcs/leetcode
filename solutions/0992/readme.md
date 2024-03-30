# 992. Subarrays with K Different Integers 🔴

Given an integer array ```nums``` and an integer ```k```, return the number of good subarrays of ```nums```.

A good array is an array where the number of different integers in that array is exactly ```k```.

For example, ```[1,2,3,1,2]``` has ```3``` different integers: ```1```, ```2```, and ```3```.
A subarray is a contiguous part of an array.

### Coemmentary

 - I had the basic idea down for so long, just trying to find where to adjust the starter pointer was killing me lol

```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // nums[i] always <= nums.size()
        std::unordered_map<int, int> found{};

        int left{ 0 };
        int right{ 0 };
        int starter{ 0 };

        int count{ 0 };
        while(right < nums.size())
        {
            found[nums.at(right++)]++;
            //starter = left;
            while(found.size() > k)
            {
                found[nums.at(left)]--;
                if(found.at(nums.at(left)) <= 0)
                    found.erase(nums.at(left));
                left++;
                starter = left;
            }
            while(found[nums.at(left)] > 1)
                found[nums.at(left++)]--;
            if(found.size() == k)
                count += (left - starter) + 1;
        }
        return count;
    }
};
```
