# 75. Sort Colors 🟡

Given an array `nums` with `n` objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

### Explanation

Iterate over `nums`, count each occurrence of `1, 2, and 3` using a container like a vector or map. Then, loop over that container and adjust the array `nums` in place. Each time a bucket of items at `1, 2, or 3` reaches `0`, move onto the next item and so on.

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::vector<int> c(3,0);
        for(int& n : nums)
            c[n]++;
        int i{ 0 };
        int cursor{ 0 };
        while(cursor < c.size() && i < nums.size())
        {
            if(c.at(cursor) <= 0)
                cursor++;
            else
            {
                nums[i++] = cursor;
                c[cursor]--;
            }
        }
    }
};
```