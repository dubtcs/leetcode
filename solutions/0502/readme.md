# 502. IPO 🔴

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most `k` distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most `k` distinct projects.

You are given `n` projects where the `ith` project has a pure profit `profits[i]` and a minimum capital of `capital[i]` is needed to start it.

Initially, you have `w` capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most `k` distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

### Explanation

Iterate through both profits and capital, and keep track of all profits mapping to each capital. You can do this with a map or a vector of pairs, whatever. Next, remove any duplicate entries from `capital` and sort it in increasing order. Keep track of the current best capital with a variable `bucket`. This variable will be the index of the limit of jobs available under that capital value. Iterate `k` times, with each time checking the current capital to the next possible capital in the `capital` array. Once the current capital meets or exceeds the next entry in `capital`, continuously loop through until `w` is below the next entry. At each iteration, add all the possible job profits to the priority queue. Then, just pop the top value of the queue for every iteration of `k`. If the queue is ever empty, it means no more jobs are possible.

```cpp
class Solution {
public:
    //                                          reward              cost to start
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        std::unordered_map<int, std::vector<int>> profmap{}; // capital costs to profits
        for(int i{ 0 }; i < capital.size(); i++)
            profmap[capital.at(i)].push_back(profits.at(i));
        capital.clear();
        for(std::pair<const int, std::vector<int>>& p : profmap)
            capital.push_back(p.first);
        std::sort(capital.begin(), capital.end());
        
        int bucket{ 0 };
        std::priority_queue<int> jobs{};
        for(int i{ 0 }; i < k; i++)
        {
            while(bucket < capital.size() && w >= capital.at(bucket))
            {
                for(int& profit : profmap.at(capital.at(bucket)))
                    jobs.push(profit);
                bucket++;
            }
            if(jobs.empty())
                break;
            w += jobs.top();
            jobs.pop();
        }

        return w;     
    }
};
```