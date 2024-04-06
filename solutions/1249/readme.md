# 1249. Minimum Remove to Make Valid Parentheses 🟡

Given a string s of `'('` , `')'` and lowercase English characters.

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
It can be written as `(A)`, where `A` is a valid string.

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::deque<int> opener{};
        std::deque<int> closer{};
        for(int i{ 0 }; i < s.size(); i++)
        {
            char& c { s.at(i) };
            if(c == '(')
                opener.push_back(i);
            else if(c == ')')
                if(!opener.empty())
                    opener.pop_back();
                else
                    closer.push_back(i);
        }

        std::string r{};
        for(int i{ 0 }; i < s.size(); i++)
        {
            if(!opener.empty() && opener.front() == i)
                opener.pop_front();
            else if(!closer.empty() && closer.front() == i)
                closer.pop_front();
            else
                r += s.at(i);
        }

        return r;
    }
};
```