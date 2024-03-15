# 

Given an integer array ```nums```, return an array answer such that ```answer[i]``` is equal to the product of all the elements of ```nums``` except ```nums[i]```.

The product of any prefix or suffix of ```nums``` is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in ```O(n)``` time and without using the division operation.


 - side note; I have no idea why I switch between [] and .at()
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // NO DIVISION
        std::vector<int> prefix{ nums };
        std::vector<int> suffix{ nums };
        int s{ static_cast<int>(nums.size() - 1) };
        for(int i{ 1 }; i < nums.size(); i++)
        {
            prefix[i] *= prefix[i - 1];
            suffix[s - i] *= suffix[s - (i - 1)];
        }

        std::vector<int> r(nums.size(), 0);
        r.front() = suffix[1];
        r.back() = prefix[s - 1];

        for(int i{ 1 }; i < s; i++)
        {
            r.at(i) = prefix.at(i - 1) * suffix.at(i + 1);
        }
        
        return r;
    }
};
```