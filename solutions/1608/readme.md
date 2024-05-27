# 1608. Special Array With X Elements Greater Than or Equal X 🟢

You are given an array `nums` of non-negative integers. `nums` is considered special if there exists a number `x` such that there are exactly `x` numbers in `nums` that are greater than or equal to `x`.

Notice that `x` does not have to be an element in `nums`.

Return `x` if the array is special, otherwise, return `-1`. It can be proven that if `nums` is special, the value for `x` is unique.

```cpp
class Solution {
public:
    int specialArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>()); // nlogn

        if(nums.back() >= nums.size())
            return nums.size();

        int left{ 0 };
        int right{ static_cast<int>(nums.size() - 1) };
        int mid{ 0 };
        while(left <= right)
        {
            mid = left + ((right - left) / 2);
            if(nums.at(mid) > mid)
                left = mid + 1;
            else if(nums.at(mid) < mid)
                right = mid - 1;
            else
                return (-1);
        }

        return mid + (nums.at(mid) > mid);
    }
};
```