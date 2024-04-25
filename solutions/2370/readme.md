2370. Longest Ideal Subsequence 🟡

You are given a string `s` consisting of lowercase letters and an integer `k`. We call a string `t` ideal if the following conditions are satisfied:

 - `t` is a subsequence of the string `s`.
 - The absolute difference in the alphabet order of every two adjacent letters in `t` is less than or equal to `k`.

Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of `'a'` and `'z'` is `25`, not `1`.

```cpp
class Solution {
public:
    int longestIdealString(string s, int k) {
        int r{ 0 };
        std::vector<int> possible(26, 0);
        for(char& c : s)
        {
            int cur{ c - 'a' };
            int L{ 1 };
            for(int i{ 0 }; i < 26; i++)
            {
                if(std::abs(cur - i) <= k)
                    L = std::max(L, possible[i] + 1);
            }
            possible[cur] = std::max(possible[cur], L);
            r = std::max(r, possible[cur]);
        }
        return r;
    }
};
```