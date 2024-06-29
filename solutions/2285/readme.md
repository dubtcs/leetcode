2285. Maximum Total Importance of Roads 🟡

You are given an integer `n` denoting the number of cities in a country. The cities are numbered from `0` to `n - 1`.

You are also given a 2D integer array roads where `roads[i] = [ai, bi]` denotes that there exists a bidirectional road connecting cities `ai` and `bi`.

You need to assign each city with an integer value from `1` to `n`, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

Return the maximum total importance of all roads possible after assigning the values optimally.

### Explanation

Iterate through each road in `roads` and for each one, increment a connection counter for each city it connects in something like a vector, `best`. After iterating over `roads`, just sort the counter vector `best` and each entry to largest to least by n, decreasing n by one each time. Because the cities are `[1,n]`, you need to subtract 1 to get the actual index.

```cpp
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long r{ 0 };
        long long n2{ static_cast<long long>(n) };
        
        std::vector<long long> best(n2, 0);
        for(std::vector<int>& v : roads)
        {
            best[v.front()]++;
            best[v.back()]++;
        }
        std::sort(best.begin(), best.end());
        for(; n2 > 0; n2--)
            r += n2 * (best.at(n2 - 1));

        return r;
    }
};
```