# 1915. Number of Wonderful Substrings 🟡

A wonderful string is a string where at most one letter appears an odd number of times.

 - For example, `"ccjjc"` and `"abab"` are wonderful, but `"ab"` is not.

Given a string `word` that consists of the first ten lowercase English letters (`'a'` through `'j'`), return the number of wonderful non-empty substrings in `word`. If the same substring appears multiple times in `word`, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

```cpp
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long r{ 0 };
        std::vector<int> counts((1 << 10), 0);
        counts.front() = 1;
        int mask{ 0 };
        for(char& c : word)
        {
            mask ^= (1 << (c - 'a'));
            r += counts.at(mask);
            for(int i{ 0 }; i < 10; i++)
                r += counts.at(mask ^ (1 << i));
            counts[mask]++;
        }
        return r;
    }
};
```