# 1544. Make The String Great 🟢

Given a string ```s``` of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters `s[i]` and `s[i + 1]` where:

 - `0 <= i <= s.length - 2`
 - `s[i]` is a lower-case letter and `s[i + 1]` is the same letter but in upper-case or vice-versa.
 
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

```cpp
class Solution {
public:
    string makeGood(string s) {
        std::stack<char> st{};
        for(char& c : s)
        {
            if(!st.empty() && std::abs(c - st.top()) == 32)//((st.top() - 32 == c) || (st.top() + 32 == c)))
                st.pop();
            else
                st.push(c);
        }
        std::string r(st.size(), '\n');
        int i{ static_cast<int>(st.size() - 1) };
        while(!st.empty())
        {
            r[i--] = st.top();
            st.pop();
        }
        return r;
    }
};
```

First attempt -  Doesn't work bc once a pair is removed, it has no idea of what the previous char was
```cpp
class Solution {
public:
    string makeGood(string s) {
        char prev{ '\0' };
        std::string r{};
        int removal{ 0 };
        for(int i{ 0 }; i < s.size() - 1; i++)
        {
            char& c{ s.at(i) };
            if(c == (prev - 32) || c == (prev + 32)) // stinky
            {
                i++;
                prev = '\0';
            }
            else
            {
                r += c;
                prev = c;
            }
        }
        return r;
    }
};
```