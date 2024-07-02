# 350. Intersection of Two Arrays II 🟢

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

### Explanation

Pick either array as a baseline and iterate over it. On each iteration, keep track of the current values appearance count with either a map or vector. Iterate over the second array, and for each value, decrement its appearance counter in the same appearance vector as the other vector. For any value that is `>= 0` after decrement, append it to a return array. Once the value goes negative, it means the current vector has more of this value than the other vector, so it can't be used.

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> c(1001, 0);
        std::vector<int> r{};
        for(int& n : nums2)
            c[n]++;
        for(int& n : nums1)
        {
            c[n]--;
            if(c.at(n) >= 0)
                r.push_back(n);
        }
        return r;
    }
};
```