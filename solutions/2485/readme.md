# 2485. Find the Pivot Integer 🟢

Given a positive integer ```n```, find the pivot integer ```x``` such that:

 - The sum of all elements between 1 and ```x``` inclusively equals the sum of all elements between ```x``` and ```n``` inclusively.

Return the pivot integer ```x```. If no such integer exists, return ```-1```. It is guaranteed that there will be at most one pivot index for the given input.

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        int totalSum{ (n * (n + 1)) / 2 }; // arithmetic series
        double sq{ std::sqrt(totalSum) };
        if(std::ceil(sq) == sq) // make sure the number is whole
            return static_cast<int>(sq);
        return -1;
    }
};
```
