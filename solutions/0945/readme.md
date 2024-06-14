# 945. Minimum Increment to Make Array Unique 🟡

You are given an integer array `nums`. In one move, you can pick an index `i` where `0 <= i < nums.length` and increment `nums[i]` by `1`.

Return the minimum number of moves to make every value in `nums` unique.

The test cases are generated so that the answer fits in a 32-bit integer.

### Explanation

Sort the input array to be in increasing order. Because all numbers to the left of a given index are less and all number to the right are greater, we can tell if a number has been modified or not. Iterate through the array. If the previous entry matches the current, increment the current index by one and increase the count. If the previous entry is GREATER than the current, it means there have been previous conflicts and we must go greater than the previous entry and accumulate all the moves between. So, if the current entry is 1, and the previous value was 6, it means that all values from 1-6 are taken, and this current 1 entry is a duplicate because we sorted it at the start. Then, just take the difference between the values + 1, and add that to the move total.

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count{ 0 };
        std::sort(nums.begin(), nums.end());
        int prev{ -1 }; // values are [ 0, 10^5 ] so -1 will always work
        for(int i{ 0 }; i < nums.size(); i++)
        {
            int& n{ nums.at(i) };
            if(prev > n)
            {
                count += (prev - n) + 1;
                n = prev + 1;
            }
            else if(n == prev)
            {
                n++;
                count++;
            }
            prev = n;
        }
        return count;
    }
};
```