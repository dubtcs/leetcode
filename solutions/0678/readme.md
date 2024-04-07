# 678. Valid Parenthesis String 🟡

Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` if `s` is valid.

The following rules define a valid string:

 - Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
 - Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
 - Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
 - `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

### Commentary

 - Stubbornly tried to do this with only 1 variable called offset, but I don't think it's possible.

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int open{ 0 };
        int close{ 0 };
        for(char& c : s)
        {
            if(c == '(')
            {
                open++;
                close++;
            }
            else if(c == ')')
            {
                open--;
                close--;
            }
            else
            {
                open++;
                close--;
            }
            if(open < 0)
                return false;
            if(close < 0)
                close = 0;
        }
        return (close == 0);
    }
};
```
