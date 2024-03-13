# 1750. Minimum Length of String After Deleting Similar Ends 🟡

Given a string ```s``` consisting only of characters ```'a'```, ```'b'```, and ```'c'```. You are asked to apply the following algorithm on the string any number of times:

1. Pick a non-empty prefix from the string ```s``` where all the characters in the prefix are equal.

2. Pick a non-empty suffix from the string ```s``` where all the characters in this suffix are equal.

3. The prefix and the suffix should not intersect at any index.

4. The characters from the prefix and suffix must be the same.

5. Delete both the prefix and the suffix.

Return the minimum length of ```s``` after performing the above operation any number of times (possibly zero times).

```cpp
class Solution {
public:
    int minimumLength(string s) {
        int len{ static_cast<int>(s.size()) };
        std::size_t left{ 0 };
        std::size_t right{ s.size() - 1 };
        bool removing{ false };
        char removal{ '\0' };
        while(left < right)
        {
            removing = (s.at(left) == s.at(right));
            if(!removing)
                return len;
            removal = s.at(left);

            while(removing && (left < right))
            {
                if(s.at(left) == removal)
                {
                    len--;
                    left++;
                }
                if(s.at(right) == removal)
                {
                    len--;
                    right--;
                }
                if(s.at(right) != removal && s.at(left) != removal)
                    break;
            }
        }
        if(removing && s.at(left) == removal) // check for break on (left < right) remaining character
            len--;

        return std::max(0, len);
    }
};
```
