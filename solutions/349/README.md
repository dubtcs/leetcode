# 349. Intersection of Two Arrays 🟢

Given two integer arrays ```nums1``` and ```nums2```, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> n1{};
        for(int& n : nums1)
            n1.insert(n);
        std::vector<int> r{};
        for(int& n : nums2)
            if(n1.contains(n))
            {
                n1.erase(n);
                r.push_back(n);
            }
        return r;
    }
};
```
