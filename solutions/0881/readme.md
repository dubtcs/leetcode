# 881. Boats to Save People 🟡

You are given an array `people` where `people[i]` is the weight of the `ith` person, and an infinite number of boats where each boat can carry a maximum weight of `limit`. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most `limit`.

Return the minimum number of boats to carry every given person.

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int left{ 0 };
        int right{ static_cast<int>(people.size() - 1) };
        int total{ 0 };
        while(left <= right)
        {
            if(people.at(left) <= (limit - people.at(right--)))
                left++;
            total++;
        }
        return total;
    }
};
```
