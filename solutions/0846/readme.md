# 846. Hand of Straights 🟡

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size `groupSize`, and consists of `groupSize` consecutive cards.

Given an integer array `hand` where `hand[i]` is the value written on the `ith` card and an integer `groupSize`, return `true` if she can rearrange the cards, or `false` otherwise.

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::unordered_map<int, int> counts{};
        std::sort(hand.begin(), hand.end());
        for(int& n : hand)
            counts[n]++;

        int totalSets{ 0 };
        for(int i{ 0 }; i < hand.size(); i++)
        {
            int& n { hand.at(i) };
            if(counts.at(n))
            {
                std::vector<int> cache{};
                for(int c{ 0 }; c < groupSize; c++)
                {
                    int temp{ n + c };
                    if(counts.contains(temp))
                    {
                        if(counts.at(temp))
                        {
                            cache.push_back(temp);
                            continue;
                        }
                    }
                    break;
                }
                if(cache.size() == groupSize)
                {
                    totalSets++;
                    for(int& n : cache)
                    {
                        counts[n]--;
                    }
                }
            }
        }

        float ratio{ static_cast<float>(hand.size()) / static_cast<float>(groupSize) };
        if(ratio == std::ceil(ratio))
            return (hand.size() / groupSize) == totalSets;
        return false;
    }
};
```