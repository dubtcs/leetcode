# 1122. Relative Sort Array 🟢

Given two arrays `arr1` and `arr2`, the elements of `arr2` are distinct, and all elements in `arr2` are also in `arr1`.

Sort the elements of `arr1` such that the relative ordering of items in `arr1` are the same as in `arr2`. Elements that do not appear in `arr2` should be placed at the end of `arr1` in ascending order.

### Explanation

Iterate through `arr1` and use a map to keep track of the amount of each element found in the vector. Then, iterate through `arr2` and repeatedly add that number to a return vector, `r`, until the total stored in the map reaches 0. For any remaining elements in `arr1` not found in `arr2`, just save the current size of the return vector and use that as an offset for sorting.

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        std::unordered_map<int, int> counts{};
        for(int& n : arr1)
            counts[n]++;

        std::vector<int> r{};
        r.reserve(arr1.size());
        for(int& n : arr2)
        {
            while(counts[n] > 0)
            {
                r.push_back(n);
                counts[n]--;
            }
        }

        std::size_t cursor{ r.size() };
        for(int& n : arr1)
        {
            while(counts[n] > 0)
            {
                r.push_back(n);
                counts[n]--;
            }
        }
        std::sort(r.begin() + cursor, r.end());

        return r;
    }
};
```