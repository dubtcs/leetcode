# 3110. Score of a String 🟢

You are given a string `s`. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

Return the score of `s`.

### Commentary

 - This has to be a joke

```cpp
class Solution {
public:
    int scoreOfString(string s) {
        int r{ 0 };
        for(int i{ 1 }; i < s.size(); i++)
            r += std::abs(s.at(i) - s.at(i - 1));
        return r;
    }
};
```