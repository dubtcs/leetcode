# 402. Remove K Digits 🟡

Given string num representing a non-negative integer `num`, and an integer `k`, return the smallest possible integer after removing `k` digits from `num`.

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        std::deque<char> st{};

        for(char& c : num)
        {
            while(!st.empty() && k > 0)
            {
                if(c < st.back())
                {
                    st.pop_back();
                    k--;
                }
                else
                    break;
            }
            st.push_back(c);
        }

        for(; k > 0; k--)
            st.pop_back();

        while((st.size() > 1) && st.front() == '0')
            st.pop_front();

        std::string r{};
        while(!st.empty())
        {
            r += st.front();
            st.pop_front();
        }
        
        if(r.empty())
            return "0";
            
        return r;
    }
};
```
