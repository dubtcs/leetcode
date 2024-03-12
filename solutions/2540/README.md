# 2540. Minimum Common Value 🟢

Given two integer arrays ```nums1``` and ```nums2```, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst ```nums1``` and ```nums2```, return -1.

Note that an integer is said to be common to ```nums1``` and ```nums2``` if both arrays have at least one occurrence of that integer.

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p1{ 0 };
        int p2{ 0 };
        while(p1 < nums1.size() && p2 < nums2.size())
        {
            int& n1{ nums1.at(p1) };
            int& n2{ nums2.at(p2) };
            if(n1 == n2)
                return n1;
            if(n1 < n2)
                p1++;
            else
                p2++;
        }
        return (-1);
    }
};
```