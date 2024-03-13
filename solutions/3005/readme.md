# 3005. Count Elements With Maximum Frequency 🟢

You are given an array ```nums``` consisting of positive integers.

Return the total frequencies of elements in ```nums``` such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

```cpp
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq{ 0 };
        int count{ 0 };
        std::unordered_map<int,int> counts{};
        for(int& n : nums)
        {
            counts[n]++;
            maxFreq = std::max(maxFreq, counts.at(n));
        }
        for(std::pair<int,int> n : counts)
        {
            if(n.second == maxFreq)
                count++;
        }
        return count * maxFreq;
    }
};
```
