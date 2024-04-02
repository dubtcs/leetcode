# 205. Isomorphic Strings 🟢

Given two strings ```s``` and ```t```, determine if they are isomorphic.

Two strings ```s``` and ```t``` are isomorphic if the characters in ```s``` can be replaced to get ```t```.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

I want to end my life so bad

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, int> sv{};
        std::unordered_map<char, int> tv{};

        if(s.size() != t.size())
            return false;
        for(int i{ 0 }; i < s.size(); i++)
        {
            if(sv[s.at(i)] != tv[t.at(i)])
                return false;
            sv[s.at(i)] = i + 1;
            tv[t.at(i)] = i + 1;
        }
        return true;
    }
};
```