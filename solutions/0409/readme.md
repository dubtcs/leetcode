# 409. Longest Palindrome 🟢

Given a string `s` which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, `"Aa"` is not considered a palindrome.

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1)
            return 1;
            
        std::unordered_map<char, int> counts{};
        int r{ 0 };
        for(char& c : s)
        {
            counts[c]++;
            if((counts[c] % 2) == 0)
                r += 2;
        }

        return r + (r < s.size());
    }
};
```