# 2997. Minimum Number of Operations to Make Array XOR Equal to K 🟡

You are given a 0-indexed integer array `nums` and a positive integer `k`.

You can apply the following operation on the array any number of times:

 - Choose any element of the array and flip a bit in its binary representation. Flipping a bit means changing a `0` to `1` or vice versa.

Return the minimum number of operations required to make the bitwise `XOR` of all elements of the final array equal to `k`.

Note that you can flip leading zero bits in the binary representation of elements. For example, for the number `(101)2` you can flip the fourth bit and obtain `(1101)2`.

### Commentary

 - I did two versions of this. One uses std::bitset, another uses standard bitshifting.
 - I felt like using the std::bitset kind of defeated the purpose of the question, so I made one without
 - But, if someone already made the functionality for you, might as well make use of it.

## Using std::bitset

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::bitset<std::numeric_limits<uint>::digits> set{ static_cast<uint64_t>(k) };
        for(int& n : nums)
            set ^= n;
        return set.count();
    }
};
```

## Using loops and bitshifting

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int bruh{ k };
        for(int& n : nums)
            bruh ^= n;
        int shift{ 0 };
        int total{ 0 };
        while((1 << shift) <= bruh)
        {
            if(((1 << shift++) & bruh) != 0)
                total++;
        }
        return total;
    }
};
```
