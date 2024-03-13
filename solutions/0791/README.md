
# 791. Custom Sort String 🟡

You are given two strings ```order``` and ```s```. All the characters of ```order``` are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that ```order``` was sorted. More specifically, if a character ```x``` occurs before a character ```y``` in ```order```, then ```x``` should occur before ```y``` in the permuted string.

Return any permutation of s that satisfies this property.

```cpp
class Solution {
public:
    string customSortString(string order, string s) {
        std::unordered_map<char, int> cont{};
        for(char& c : s)
            cont[c]++;

        std::string r{};
        for(char& c : order) // order is sorted the way we want, so use it as a guide
        {
            if(cont.contains(c))
            {
                while(cont.at(c)--) // while non zero
                    r += c;
            }
        }

        for(char& c : s)
            if(cont[c]-- > 0)
                r += c;

        return r;
    }
};
```
