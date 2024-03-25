# 442. Find All Duplicates in an Array 🟡

Given an integer array ```nums``` of length ```n``` where all the integers of ```nums``` are in the range ```[1, n]``` and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in ```O(n)``` time and uses only constant extra space.

### Commentary

 - I really like this question

 - Use the value at each index as a pointer to another index. Just negate the value at THAT index. If the value is already negative, you know a value has already pointed there.

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // linear, constant space
        // everything appears either once or twice, nothing more, nothing less
        std::vector<int> r{};
        for(int& n : nums)
        {
            int& ptr{ nums.at(std::abs(n) - 1) };
            if(ptr < 0)
                r.push_back(std::abs(n));
            ptr *= (-1);
        }

        return r;
    }
};
```