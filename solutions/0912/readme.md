# 912. Sort an Array 🟡

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.

## Explanation

Merge sort. I did all the extra template stuff because I wanted to get more exposure to lambdas as parameters

```cpp
class Solution {
public:
    template<typename T, typename Compare>
    std::vector<T> splitv(std::vector<T>& toSort, int start, int end, Compare&& comparator)
    {
        if(start >= end)
            return { toSort.at(end) };

        int mid{ start + ((end - start) / 2) };
        std::vector<T> left{ splitv(toSort, start, mid, comparator) };
        std::vector<T> right{ splitv(toSort, mid + 1, end, comparator) };

        int lptr{ 0 };
        int rptr{ 0 };
        std::vector<T> r{};
        while(lptr < left.size() && rptr < right.size())
        {
            if(comparator(left.at(lptr), right.at(rptr)))
                r.push_back(left.at(lptr++));
            else
                r.push_back(right.at(rptr++));
        }
        while(lptr < left.size())
            r.push_back(left.at(lptr++));
        while(rptr < right.size())
            r.push_back(right.at(rptr++));
        return r;
    }
    template<typename T, typename Compare>
    void sortc(std::vector<T>& toSort, Compare&& cmp)
    {
        toSort = splitv(toSort, 0, toSort.size() - 1, cmp);
    }
    vector<int> sortArray(vector<int>& nums) {
        sortc<int>(nums, [](int& A, int& B){return A < B;});
        return nums;
    }
};
```