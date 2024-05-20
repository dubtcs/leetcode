# 1863. Sum of All Subset XOR Totals 🟢

The XOR total of an array is defined as the bitwise `XOR` of all its elements, or `0` if the array is empty.

 - For example, the XOR total of the array `[2,5,6]` is `2 XOR 5 XOR 6 = 1`.

Given an array `nums`, return the sum of all XOR totals for every subset of `nums`. 

Note: Subsets with the same elements should be counted multiple times.

An array `a` is a subset of an array `b` if `a` can be obtained from `b` by deleting some (possibly zero) elements of `b`.

```cpp
class Solution {
public:
    int A__J_tmcm_rupn_gt_epmf_yq_lhybi_cgkbun(std::vector<int>& nums, int cursor, int total)
    {
        if(cursor == nums.size())
            return total;
        int temp{ 0 };
        temp = A__J_tmcm_rupn_gt_epmf_yq_lhybi_cgkbun(nums, cursor + 1, total ^ nums.at(cursor));
        temp += A__J_tmcm_rupn_gt_epmf_yq_lhybi_cgkbun(nums, cursor + 1, total);
        return temp;
    }
    int subsetXORSum(vector<int>& nums) {
        return A__J_tmcm_rupn_gt_epmf_yq_lhybi_cgkbun(nums, 0, 0);
    }
};
```