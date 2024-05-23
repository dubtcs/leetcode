# 2597. The Number of Beautiful Subsets 🟡

You are given an array `nums` of positive integers and a positive integer `k`.

A subset of `nums` is beautiful if it does not contain two integers with an absolute difference equal to `k`.

Return the number of non-empty beautiful subsets of the array `nums`.

A subset of `nums` is an array that can be obtained by deleting some (possibly none) elements from `nums`. Two subsets are different if and only if the chosen indices to delete are different.

### Commentary

 - It's slow but it works. I'll probably come back to see how the faster solutions work

```cpp
class Solution {
public:
    void dive(std::vector<int>& nums, int& k, int start, std::unordered_map<int, int>& found, int& count)
    {
        if(start >= nums.size())
        {
            count++;
            return;
        }
        
        if(!found[nums.at(start) - k] && !found[nums.at(start) + k]) // dont need found[nums.at(start) + k] if input array is sorted in beautifulSUbsets
        {
            found[nums.at(start)]++;
            dive(nums, k, start + 1, found, count);
            found[nums.at(start)]--;
        }
        dive(nums, k, start + 1, found, count);

        return;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        // use a map bs a set will potentially remove duplicates 
        // ex [2,2,4] will remove 2 from the set after 1 recursion, leaving the second 2 in without checking
        std::unordered_map<int, int> found{};
        //std::sort(nums.begin(), nums.end());

        int count{ 0 };
        dive(nums, k, 0, found, count);

        return count - 1;
    }
};
```