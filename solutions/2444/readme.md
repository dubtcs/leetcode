# 2444. Count Subarrays With Fixed Bounds 🔴

You are given an integer array ```nums``` and two integers ```minK``` and ```maxK```.

A fixed-bound subarray of ```nums``` is a subarray that satisfies the following conditions:

 - The minimum value in the subarray is equal to ```minK```.
 - The maximum value in the subarray is equal to ```maxK```.

Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

### Commentary

 - This was a similar problem to [992](../0992) in that 3 pointers are need to be used to min and max windows for valid subarrays. I got messed up on the fine details again.

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count{ 0 };

        int left{ -1 };
        int right{ -1 };
        int starter{ -1 };

        for(int i{ 0 }; i < nums.size(); i++)
        {
            int& n{ nums.at(i) };
            if(n < minK || n > maxK)
                starter = i;
            else
            {
                if(n == minK)
                    left = i;
                if(n == maxK)
                    right = i;
            }
            count += std::max(0, std::min(left, right) - starter);
        }
        
        return count;
    }
};
```

First attempt
```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count{ 0 };

        int left{ -1 };
        int right{ -1 };
        int starter{ 0 };

        for(int i{ 0 }; i < nums.size(); i++)
        {
            int& n{ nums.at(i) };
            //std::cout << n << ": " << left << ", " << right << '\n';
            if(n > maxK || n < minK)
            {
                if(right >= 0 && left >= 0)
                    count += (i - starter) - (right - left); // difference between the two extremes
                left = -1;
                right = -1;
                starter = i;
            }
            else
            {
                if(n == minK && left < 0)
                    left = i;
                if(n == maxK && right < 0)
                    right = i;
            }
        }

        // the final element fits
        if(left >= 0 && right >= 0)
        {
            //std::cout << left << ", " << right << "\n";
            count += (nums.size() - starter) - (right - left);
        }
        
        return count;
    }
}
```
