# 345. Reverse Vowels of a String 🟢

Given a string ```s```, reverse only all the vowels in the string and return it.

The vowels are ```'a', 'e', 'i', 'o', and 'u'```, and they can appear in both lower and upper cases, more than once.

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int left{ 0 };
        int right{ static_cast<int>(s.size()) - 1};
        std::unordered_set<char> vowels{'a','e','i','o','u'};
        while(left < right)
        {
            if(vowels.contains(std::tolower(s.at(left))))
                while(!vowels.contains(std::tolower(s.at(right))))
                    right--;
            if(vowels.contains(std::tolower(s.at(right))))
                while(!vowels.contains(std::tolower(s.at(left))))
                    left++;
            if(vowels.contains(std::tolower(s.at(left))) && vowels.contains(std::tolower(s.at(right))))
                std::swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
```