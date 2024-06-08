# 523. Continuous Subarray Sum 🟡

Given an integer array nums and an integer k, return `true` if `nums` has a good subarray or `false` otherwise.

A good subarray is a subarray where:

 - its length is at least two, and
 - the sum of the elements of the subarray is a multiple of `k`.

Note that:

 - A subarray is a contiguous part of the array.
 - An integer `x` is a multiple of `k` if there exists an integer `n` such that `x = n * k`. `0` is always a multiple of `k`.

### Explanation

Loop through `nums`. For each item, add it to the counter `sums`. Take the remainder of `sums` and `k`, and store it in a variable `dif`. If the `sums` map contains `dif`, that means the subarray between `i` and `sums.at(dif)` is a multiple of `k`. Then, just make sure the length of that subarray is greater than 2.

```
Array: [23   2   4   6   7]
Sum:    23  25  29
Dif:     5   1   5
                 ^
                 5 already exists in dif at index 0.
                 Meaning 23 + ... + 4 is a multiple of 6.
                 Now, just make sure that length is >= 2
```

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum{ 0 };
        std::unordered_map<int, int> sums{};
        sums[0] = -1; // need this -1, bc 0 makes it look like index 0 has the asnwer oops
        for(int i{ 0 }; i < nums.size(); i++)
        {
            sum += nums.at(i);
            int dif{ sum % k };
            if(sums.contains(dif))
            {
                if(i - sums.at(dif) >= 2)
                    return true;
            }
            else
                sums[dif] = i;
        }
        return false;
    }
};
```