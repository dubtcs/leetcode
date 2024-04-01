# 58. Length of Last Word 🟢

Given a string ```s``` consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int right{ static_cast<int>(s.size()) - 1 };
        bool found{ false };
        int l{ 0 };
        for(; right >= 0; right--)
        {
            if(s.at(right) != ' ')
            {
                found = true;
                l++;
            }
            else if(found)
                return l;
        }
        return l;
    }
};
```