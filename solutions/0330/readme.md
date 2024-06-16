
### Explanation

We need numbers in the range of `[1,n]` to be formed by the sum of elements in the array. We need atleast a 1, so keeping track of a variable `goal` initialized at 1, you can slowly increase it and add it to the array if it's required. While that goal is below the desired `n`, check if the current index of the array is above the goal. If `nums[i]` is above the goal, you need to double the goal and increase the total replacements required. This addition/replacement basically means that this value is required, but it doesn't exist in the array, so you need to add it.

```cpp
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int r{ 0 };
        int index{ 0 };
        std::int64_t goal{ 1 };
        while(goal <= n)
        {
            if(index < nums.size() && nums.at(index) <= goal)
            {
                goal += nums.at(index);
                index++;
            }
            else
            {
                goal += goal;
                r++;
            }
        }
        return r;
    }
};
```