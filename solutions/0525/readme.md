# 525. Contiguous Array 🟡

Given a binary array ```nums```, return the maximum length of a contiguous subarray with an equal number of ```0``` and ```1```.

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> strides{};
        int sum{ 0 };
        int stride{ 0 };
        for(int i{ 0 }; i < nums.size(); i++)
        {
            sum += nums.at(i) ? 1 : (-1);
            if(sum == 0)
                stride = i + 1;
            else if(strides.contains(sum))
                stride = std::max(stride, i - strides[sum]);
            else
                strides[sum] = i; // need this here so we don't overwrite it constantly
        }
        return stride;
    }
};
```

 **Incorrect solution first try, this only works for arrays starting with 1**
```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::vector<int> sums(nums.size(), 0);
        int sum{ 0 };
        for(int i{ 0 }; i < nums.size(); i++)
        {
            sum += nums.at(i) ? 1 : (-1);
            sums[i] = sum;
        }
        std::unordered_map<int, int> found{};
        int longestStride{ 0 };
        int lastIndex{ 0 };
        for(int i{ 0 }; i < sums.size(); i++)
        {
            int& total{ sums.at(i) };
            if(found.contains(total))
            {
                int dif{ i - found.at(total) };
                longestStride = std::max(longestStride, dif);
            }
            else
            {
                found.insert({ total, i });
            }
        }
        return longestStride;
    }
};
```