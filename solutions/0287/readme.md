# 287. Find the Duplicate Number 🟡

Given an array of integers ```nums``` containing ```n + 1``` integers where each integer is in the range ```[1, n]``` inclusive.

There is only one repeated number in ```nums```, return this repeated number.

You must solve the problem **without** modifying the array ```nums``` and uses only constant extra space.

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // no mod, constant space
        int fast{ nums.at(0) };
        int slow{ nums.at(0) };

        // use values as indices, bc eventually, two values will be the same and point to the same index
        while(true) // bruh
        {
            fast = nums.at(nums.at(fast)); // 2 steps
            slow = nums.at(slow);
            if(fast == slow)
                break;
        }

        
        slow = nums.front();
        while(slow != fast)
        {
            fast = nums.at(fast);
            slow = nums.at(slow);
        }
        return fast;
    }
};
```
