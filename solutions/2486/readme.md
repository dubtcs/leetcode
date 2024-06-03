# 2486. Append Characters to String to Make Subsequence 🟡

You are given two strings `s` and `t` consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of `s` so that `t` becomes a subsequence of `s`.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

```cpp
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i{ 0 };
        for(char& c : s)
        {
            if(c == t.at(i))
            {
                i++;
                if(i >= t.size())
                    break;
            }
        }
        return (t.size() - i);
    }
};
```