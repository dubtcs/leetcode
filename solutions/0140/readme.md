# 140. Word Break II 🔴

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

```cpp
class Solution {
public:
    void CheckWord(int start, std::vector<std::string>& cur, std::string& s, std::unordered_set<std::string>& words, std::vector<std::string>& r)
    {
        if(start >= s.size())
        {
            int i{ 0 };
            std::string temp{};
            for(; i < (cur.size() - 1); i++)
                temp += (cur.at(i) + " ");
            temp += cur.at(i);
            r.push_back(temp);
            return;
        }

        std::string temp{};
        for(int i{ start }; i < s.size(); i++)
        {
            temp.push_back(s.at(i));
            if(words.contains(temp))
            {
                cur.push_back(temp);
                CheckWord(i + 1, cur, s, words, r);
                cur.pop_back();
            }
        }

        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> words{};
        for(std::string& w : wordDict)
            words.insert(w);
        
        // keep adding char to entry word, every time a word is valid, seek to the next valid word
        std::vector<std::string> r{};
        std::vector<std::string> cur{};
        
        CheckWord(0, cur, s, words, r);
        
        return r;
    }
};
```