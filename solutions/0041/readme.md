# 41. First Missing Positive 🔴

Given an unsorted integer array ```nums```. Return the smallest positive integer that is not present in ```nums```.

You must implement an algorithm that runs in ```O(n)``` time and uses ```O(1)``` auxiliary space.

### Commentary

 - This problem made me want to peel me eyelids off

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // smallest that isn't present
        int limit{ static_cast<int>(nums.size()) };
        
        if(limit == 1)
            return nums.front() == 1 ? 2 : 1;
        
        for(int& n : nums)
        {
            if(n <= 0 || n > limit) // useless
                n = limit + 1;
        }

        for(int& n : nums)
        {
            int ptr{ std::abs(n) };
            if(ptr <= limit)
            {
                ptr--; // treat as 1 indexed
                if(nums.at(ptr) > 0)
                    nums.at(ptr) *= -1;
            }
        }

        for(int i{ 0 }; i < limit; i++)
        {
            if(nums.at(i) > 0)
                return i + 1;
        }
        
        return limit + 1;
    }
};
```
