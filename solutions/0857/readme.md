# 857. Minimum Coswt to Hire K Workers 🔴

There are `n` workers. You are given two integer arrays `quality` and `wage` where `quality[i]` is the quality of the `ith` worker and `wage[i]` is the minimum wage expectation for the `ith` worker.

We want to hire exactly `k` workers to form a paid group. To hire a group of `k` workers, we must pay them according to the following rules:

 - Every worker in the paid group must be paid at least their minimum wage expectation.
 - In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.

Given the integer `k`, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within `10-5` of the actual answer will be accepted.

```cpp
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double r{ std::numeric_limits<double>::max() };

        std::vector<std::pair<double, int>> b{};
        for(int i{ 0 }; i < quality.size(); i++)
            b.push_back({ static_cast<double>(wage.at(i)) / static_cast<double>(quality.at(i)), quality.at(i) });

        std::sort(b.begin(), b.end(), [](std::pair<double, int>& A, std::pair<double, int>& B)
        {
            return A.first < B.first;
        });
        
        int total{ 0 };
        std::priority_queue<int> q{};

        for(std::pair<double, int>& p : b)
        {
            q.push(p.second);
            total += p.second;

            if(q.size() > k)
            {
                total -= q.top();
                q.pop();
            }
            
            if(q.size() == k)
                r = std::min(r, static_cast<double>(total) * p.first);
        }

        return r;
    }
};
```