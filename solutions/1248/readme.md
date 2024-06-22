# 1248. Count Number of Nice Subarrays 🟡

Given an array of integers `nums` and an integer `k`. A continuous subarray is called nice if there are `k` odd numbers on it.

Return the number of nice sub-arrays.

### Explanation

*Main idea: Prefix Sum*

Create a container, like a vector or map, to keep track of existing odd counts. The idea will be to store the amount of subarrays at the index of the corresponding odd element count for easy lookup. Just iterate over each element in `nums` and if the number is odd, add it the a counter. Once the counter is incremented, check the container for an existing entry with that total and add it to the return value. The `odds - k` is to make sure that only subarrays with greater than or equal to `k` elements are accepted.

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        std::vector<int> counts(nums.size() + 1, 0);
        counts.front() = 1;
        int r{ 0 };
        int odds{ 0 };
        for(int i{ 0 }; i < nums.size(); i++)
        {
            int& n{ nums.at(i) };
            odds += (n % 2); // 0 or 1
            if(odds >= k && counts.at(odds - k))
                r += counts.at(odds - k);
            counts[odds]++;
        }
        return r;
    }
};
```