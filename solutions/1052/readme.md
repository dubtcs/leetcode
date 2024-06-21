# 1052. Grumpy Bookstore Owner 🟡

There is a bookstore owner that has a store open for `n` minutes. Every minute, some number of customers enter the store. You are given an integer array `customers` of length `n` where `customers[i]` is the number of the customer that enters the store at the start of the `ith` minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where `grumpy[i]` is `1` if the bookstore owner is grumpy during the `ith` minute, and is `0` otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for `minutes` consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

### Explanation

Iterate the array and for each `grumpy[i]` that is 0 and add the associated `customers[i]` to a counter `r`. Replace each of those `customers[i]` that are found with a 0. These customers will never be bothered by the manager, so this is just adding them and ignoring them. Iterate over the arrays again, but this time, make a window of size `minutes`. Then, just move that window over the modified `customers` array and keep track of the highest sum of all remaining customers. Once that is done, just return `r` and the highest sum that was found.

```
minutes     = 2;
customers   = [1,2,3,4,5];
grumpy      = [0,1,0,1,1];

first loop:
customers   = [0,2,0,4,5];
r           = 4 (index 0 + index 2)

second loop:
customers   = [0,2,0,4,5];
window         x-x          (0 + 2) = 2;
                 x-x        (2 + 0) = 2;
                   x-x      (0 + 4) = 4;
                     x-x    (4 + 5) = 9;

return r + 9;

```

```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int r{ 0 };
        for(int i{ 0 }; i < customers.size(); i++)
        {
            if(!grumpy.at(i))
            {
                r += customers.at(i);
                customers[i] = 0;
            }
        }
        if(minutes == 1)
            return r + *std::max_element(customers.begin(), customers.end());

        int left{ 0 };
        int right{ 0 };
        int potential{ 0 };
        while(right < customers.size() && right < minutes)
            potential += customers.at(right++);

        int best{ potential };
        while(right < customers.size())
        {
            potential -= customers.at(left++);
            potential += customers.at(right++);
            best = std::max(best, potential);
        }
        r += best;

        return r;
    }
};
```