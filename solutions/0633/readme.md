# 633. Sum of Square Numbers 🟡

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a^2 + b^2 = c`.

### Explanation

It's just a sliding window. You can't have `a` or `b` be more than `sqrt(c)` because that would make absolutely no sense at all. So just increment or decrement left/right depending on if their sum is less/more than the target, `c`.

The hardest part about this was dealing with `2^31` values. So used to using ints for everything I didn't even think about it. Not very *robust* of me.

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0)
            return true;
        int left{ 0 };
        int right{ 0 };
        if(std::ceil(std::sqrt(c)) == std::sqrt(c))
            right = static_cast<int>(std::sqrt(c));
        else
            right = std::ceil(std::sqrt(c));
        while(left <= right)
        {
            std::int64_t total{ static_cast<std::int64_t>(left) * static_cast<std::int64_t>(left) + static_cast<std::int64_t>(right) * static_cast<std::int64_t>(right) };
            if(total == c)
                return true;
            if(total < c)
                left++;
            else
                right--;
        }
        return false;
    }
};
```