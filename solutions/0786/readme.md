# 786. K-th Smallest Prime Fraction 🟡

You are given a sorted integer array `arr` containing `1` and prime numbers, where all the integers of `arr` are unique. You are also given an integer `k`.

For every `i` and `j` where `0 <= i < j < arr.length`, we consider the fraction `arr[i] / arr[j]`.

Return the `kth` smallest fraction considered. Return your answer as an array of integers of size `2`, where `answer[0] == arr[i]` and `answer[1] == arr[j]`.

```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        std::vector<std::pair<int, int>> frac{};
        for(int i{ 0 }; i < arr.size(); i++)
        {
            for(int b{ i + 1 }; b < arr.size(); b++)
            {
                frac.push_back( { arr.at(i), arr.at(b) } );
            }
        }
        
        std::sort(frac.begin(), frac.end(), [](std::pair<int,int>& A, std::pair<int,int>& B)
        {
            return (A.first * B.second) < (B.first * A.second);
        });

        return { frac.at(k - 1).first, frac.at(k - 1).second };
    }
};
```
