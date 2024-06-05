# 1002. Find Common Characters 🟢

Given a string array `words`, return an array of all characters that show up in all strings within the `words` (including duplicates). You may return the answer in any order.

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        std::vector<int> bank(26, 0);

        for(char& c : words.front())
            bank[c-'a']++;

        for(int i{ 1 }; i < words.size(); i++)
        {
            std::string& w{ words.at(i) };
            std::vector<int> cache(26, 0);
            for(char& c : w)
            {
                if(bank.at(c-'a') > 0)
                {
                    cache[c-'a']++;
                    bank[c-'a']--;
                }
            }
            bank = cache;
        }

        std::vector<std::string> r{};
        for(int i{ 0 }; i < bank.size(); i++)
        {
            if(bank.at(i) > 0)
            {
                for(int c{ 0 }; c < bank.at(i); c++)
                    r.push_back( std::string{static_cast<char>(i + 'a')} );
            }
        }
        
        return r;
    }
};
```