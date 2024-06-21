# 1552. Magnetic Force Between Two Balls 🟡

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has `n` empty baskets, the ith basket is at `position[i]`, Morty has `m` balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions `x` and `y` is `|x - y|`.

Given the integer array `position` and the integer `m`. Return the required force.

### Explanation

Similar to [1482.](../1482) Use binary search. Set the left pointer to 1 as that's the minimum, and the right pointer to the difference of the last and first elements of `position` divided by `m - 1`. 1 is subtracted from m because there will be m - 1 gaps. Say you need 3 balls, then there will be two gaps between those 3 balls. At each search, iterate the array and see if the gap can be minimized.

```cpp
class Solution {
public:
    bool CanUse(const std::vector<int>& position, const int& m, const int& gap)
    {
        int prevIndex{ 0 };
        int count{ 1 };
        for(int i{ 1 }; i < position.size(); i++)
        {
            if(position.at(i) - position.at(prevIndex) >= gap)
            {
                prevIndex = i;
                count++;
            }
        }
        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        int lowest{ 1 };
        int highest{ (position.back() - position.front()) / (m - 1) }; // most amount of gaps. m = 3 will have 2 gaps, so 3 - 1
        int r{ 0 };
        while(lowest <= highest)
        {
            int gap{ lowest + ((highest - lowest) / 2) };
            if(CanUse(position, m, gap))
            {
                r = gap;
                lowest = gap + 1;
            }
            else
            {
                highest = gap - 1;
            }
        }
        return r;
    }
};
```