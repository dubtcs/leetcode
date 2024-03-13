class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq{ 0 };
        int count{ 0 };
        std::unordered_map<int,int> counts{};
        for(int& n : nums)
        {
            counts[n]++;
            maxFreq = std::max(maxFreq, counts.at(n));
        }
        for(std::pair<int,int> n : counts)
        {
            if(n.second == maxFreq)
                count++;
        }
        return count * maxFreq;
    }
};