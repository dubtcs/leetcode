# 260. Single Number III 🟡

Given an integer array `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2)
            return nums;
        // linear so no sorting
        // constant space so no maps
        // bruh
        int cur{ 0 };
        for(int& n : nums)
            cur ^= n;

        int sig{ 0 };
        while(!((1 << sig) & cur))
            sig++;

        int does{ 0 };
        int doesnt{ 0 };
        for(int& n : nums)
        {
            if((1 << sig) & n)
                does ^= n;
            else
                doesnt ^= n;
        }
        
        return {does, doesnt};
    }
};
```