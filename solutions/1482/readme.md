# 1482. Minimum Number of Days to Make m Bouquets 🟡

You are given an integer array `bloomDay`, an integer `m` and an integer `k`.

You want to make `m` bouquets. To make a bouquet, you need to use `k` adjacent flowers from the garden.

The garden consists of `n` flowers, the `ith` flower will bloom in the `bloomDay[i]` and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make `m` bouquets from the garden. If it is impossible to make `m` bouquets return `-1`.

### Explanation

Create a left and right "pointer" to the lowest and highest days in the `bloomDay` array. Use binary search to get the mid point between the two dates. At each search, iterate over the array and see if any sets of `m` bouquets can be made. If it's less, shift right, else shift left.

```cpp
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // m is amount of boq
        // k is how many flowers required
        int r{ -1 };
        int left{ 0 };
        int right{ 0 };
        for(int& n : bloomDay)
            right = std::max(right, n);
        while(left <= right)
        {
            int mid{ left + ((right - left) / 2) };
            int adj{ 0 };
            int amount{ 0 };
            for(int& n : bloomDay)
            {
                if(n <= mid)
                {
                    adj++;
                    if(adj >= k)
                    {
                        amount++;
                        adj = 0;
                    }
                }
                else
                    adj = 0;
            }
            if(amount >= m)
            {
                r = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return r;
    }
};
```