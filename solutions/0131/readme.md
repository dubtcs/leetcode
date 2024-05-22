# 131. Palindrome Partitioning 🟡

Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of `s`.

```cpp
class Solution {
public:
    void sha(const std::string& s, int left, std::vector<std::string>& cur, std::vector<std::vector<std::string>>& r)
    {
        if(left >= s.size())
        {
            r.push_back(cur);
            return;
        }

        for(int i{ left }; i < s.size(); i++)
        {
            int cl{ left };
            int cr{ i };
            bool ispal{ true };
            while(cl <= cr)
            {
                if(s.at(cl++) != s.at(cr--))
                {
                    ispal = false;
                    break;
                }
            }
            if(ispal)
            {
                cur.push_back(s.substr(left, (i - left) + 1));
                sha(s, i + 1, cur, r);
                cur.pop_back();
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> r{};
        std::vector<std::string> cur{};

        sha(s, 0, cur, r);

        return r;
    }
};
```