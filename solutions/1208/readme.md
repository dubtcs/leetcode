# 1208. Get Equal Substrings Within Budget 🟡

You are given two strings `s` and `t` of the same length and an integer maxCost.

You want to change `s` to `t`. Changing the `ith` character of `s` to `ith` character of `t` costs `|s[i] - t[i]|` (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of `s` that can be changed to be the same as the corresponding substring of `t` with a cost less than or equal to `maxCost`. If there is no substring from `s` that can be changed to its corresponding substring from `t`, return `0`.

### Commentary

 - I initially wanted to do a backtracking solution because the last few days have all been backtracking. I need to not do that.

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cursor{ 0 };
        int best{ 0 };
        for(int i{ 0 }; i < s.size(); i++)
        {
            maxCost -= std::abs(s.at(i) - t.at(i));
            while(maxCost < 0)
                maxCost += std::abs(s.at(cursor) - t.at(cursor++));
            if(maxCost >= 0)
                best = std::max(best, (i - cursor) + 1);
        }
        return best;
    }
};
```