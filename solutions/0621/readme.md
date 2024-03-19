# 621. Task Scheduler 🟡

You are given an array of CPU ```tasks```, each represented by letters A to Z, and a cooling time, ```n```. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least ```n``` intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> counts{};
        // this is just math based round robin scheduling with cooldowns
        int common{ 0 };
        int freq{ 0 };
        for(char& c : tasks)
        {
            counts[c]++;
            common = std::max(common, counts[c]);
        }
        for(std::pair<char, int> p : counts)
            if(p.second == common)
                freq++;
        int count{ ((common - 1) * (n + 1)) + freq };
        return std::max(count, static_cast<int>(tasks.size())); // either all of them are unique, which is tasks.size(), or not
    }
};
```
