# 1051. Height Checker 🟢

A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array `expected` where `expected[i]` is the expected height of the `ith` student in line.

You are given an integer array `heights` representing the current order that the students are standing in. Each `heights[i]` is the height of the `ith` student in line (0-indexed).

Return the number of indices where `heights[i] != expected[i]`.

### Explanation

Create a copy of the input array, `temp`. Sort the `temp` array. This sorted array will now be the expected height order. Then compare each value `temp[i]` to `height[i]`. If they don't match, increment the counter.

```cpp
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> temp{ heights };
        std::sort(temp.begin(), temp.end());
        int misses{ 0 };
        for(int i{ 0 }; i < heights.size(); i++)
        {
            if(heights.at(i) != temp.at(i))
                misses++;
        }
        return misses;
    }
};
```