# 826. Most Profit Assigning Work 🟡

You have `n` jobs and `m` workers. You are given three arrays: `difficulty`, `profit`, and `worker` where:

 - `difficulty[i]` and `profit[i]` are the difficulty and the profit of the `ith` job, and
 - `worker[j]` is the ability of `jth` worker (i.e., the `jth` worker can only complete a job with difficulty at most `worker[j]`).

Every worker can be assigned at most one job, but one job can be completed multiple times.

 - For example, if three workers attempt the same job that pays `$1`, then the total profit will be `$3`. If a worker cannot complete any job, their profit is `$0`.

Return the maximum profit we can achieve after assigning the workers to the jobs.

### Explanation

The map in my code isn't really necessary.

Iterate over both `profit` and `difficulty`, pairing them together into a common vector, `vprof` as `[difficulty, profit]` along the way. Once you have those pairs created, sort that vector in non decreasing order by difficulty. Iterate over `vprof` and keep track of the highest profit to that point. If the current pairs profit is less than the best, replace it with the best. If it is higher than the best, update bes to be this current profit. Once that `vprof` vector is sorted and updated, do a binary search for each worker `w` and add it to a total.

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::unordered_map<int, int> mostProfits{};
        for(int i{ 0 }; i < profit.size(); i++)
        {
            int& dif{ difficulty.at(i) };
            int& prof{ profit.at(i) };
            mostProfits[dif] = std::max(mostProfits[dif], prof);
        }

        std::vector<std::pair<int, int>> vprof{};
        for(std::pair<const int, int>& p : mostProfits)
            vprof.push_back(p);
        std::sort(vprof.begin(), vprof.end(), [](std::pair<int, int>& A, std::pair<int, int>& B)
        {
            return A.first < B.first;
        });
        
        int best{ 0 };
        for(std::pair<int, int>& p : vprof)
        {
            if(p.second > best)
                best = p.second;
            else
                p.second = best;
        }

        int r{ 0 };
        for(int& w : worker)
        {
            int left{ 0 };
            int right{ static_cast<int>(vprof.size() - 1) };
            int best{ 0 };
            while(left <= right)
            {
                int mid{ left + ((right - left) / 2) };
                if(vprof.at(mid).first <= w)
                {
                    best = std::max(best, vprof.at(mid).second);
                    if(vprof.at(mid).first == w)
                        break;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            r += best;
        }

        return r;
    }
};
```