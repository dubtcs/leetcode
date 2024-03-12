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