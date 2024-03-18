# 452. Minimum Number of Arrows to Burst Balloons 🟡

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array ```points``` where ```points[i] = [xstart, xend]``` denotes a balloon whose horizontal diameter stretches between ```xstart``` and ```xend```. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with ```xstart``` and ```xend``` is burst by an arrow shot at ```x``` if ```xstart <= x <= xend```. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array ```points```, return the minimum number of arrows that must be shot to burst all balloons.

### Commentary

 - I tried making a more convoluted mess of a solution before this one because I was afraid of sorting n(log(n)). I need to remember to just get a simple and straight forward solution down first, then try making changes.
 - I come up with a solution and immediately convince myself its wrong because I figure it would be too easy or it can't be that simple.
 - Sometimes the straightforward and easy solution is the best.


```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count{ 1 };
        std::pair<int, int> cur{ points.front().front(), points.front().back() };
        std::sort(points.begin(), points.end()); //, [](std::vector<int>& a, std::vector<int>& b){return a.front() < b.front();}
        for(std::vector<int>& p : points)
        {
            if(p.front() <= cur.second)
            {
                cur.first = std::max(p.front(), cur.first);
                cur.second = std::min(p.back(), cur.second);
            }
            else
            {
                count++;
                cur = { p.front(), p.back() };
            }
        }
        return count;
    }
};
```