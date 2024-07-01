# 1550. Three Consecutive Odds🟢

Given an integer array `arr`, return `true` if there are three consecutive odd numbers in the array. Otherwise, return `false`.

### Explanation

Just create a pointer for atleast the third element onward, and check the previous three for each one. If the array is less than 3 length, the loop wont even run and return false.

```cpp
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i{ 2 }; i < arr.size(); i++)
        {
            if((arr.at(i) % 2) && (arr.at(i - 1) % 2) && (arr.at(i - 2) % 2))
                return true;
        }
        return false;
    }
};
```