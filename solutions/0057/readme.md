# 57. Insert Interval 🟡

You are given an array of non-overlapping intervals ```intervals``` where ```intervals[i]``` = ```[starti, endi]``` represent the start and the end of the ```ith``` interval and ```intervals``` is sorted in ascending order by ```starti```. You are also given an interval ```newInterval = [start, end]``` that represents the start and end of another interval.

Insert ```newInterval``` into ```intervals``` such that ```intervals``` is still sorted in ascending order by starti and ```intervals``` still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return ```intervals``` after the insertion.

Note that you don't need to modify ```intervals``` in-place. You can make a new array and return it.


 - Side note: I REALLY HATE this question. The wording is infuriating.
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> r{};
        for(int i{ 0 }; i < intervals.size(); i++)
        {
            std::vector<int>& cur{ intervals.at(i) };
            if(newInterval.back() < cur.front())
            {
                r.push_back(newInterval);
                r.insert(r.end(), intervals.begin() + i, intervals.end());
                return r;
            }
            else if(newInterval.front() > cur.back())
            {
                r.push_back(cur);
            }
            else
            {
                newInterval = { std::min(newInterval.front(), cur.front()), std::max(newInterval.back(), cur.back()) };
            }
        }
        r.push_back(newInterval);
        return r;
    }
};
```