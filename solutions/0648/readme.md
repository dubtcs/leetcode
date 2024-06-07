# 648. Replace Words 🟡

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root `"help"` is followed by the word `"ful"`, we can form a derivative `"helpful"`.

Given a `dictionary` consisting of many roots and a `sentence` consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the `sentence` after the replacement.

```cpp
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::string r{};
        std::unordered_set<std::string> words{};
        for(std::string& s : dictionary)
            words.insert(s);
            
        int cursor{ 0 };

        std::string cur{};
        while(cursor < sentence.size())
        {
            char& c{ sentence.at(cursor) };
            if(c != ' ')
            {
                cur += c;
                if(words.contains(cur))
                {
                    r += cur;
                    r += " ";
                    while(cursor < sentence.size() && sentence.at(cursor) != ' ')
                        cursor++;
                    cur = "";
                }
            }
            else
            {
                if(!cur.empty())
                    r += cur + " ";
                cur = "";
            }
            cursor++;
        }

        if(!cur.empty())
            r += cur;
        else if(!r.empty())
            r.pop_back(); // remove space
        return r;
    }
};
```