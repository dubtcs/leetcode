class Solution {
public:
    int pivotInteger(int n) {
        int totalSum{ (n * (n + 1)) / 2 }; // arithmetic series
        double sq{ std::sqrt(totalSum) };
        if(std::ceil(sq) == sq)
            return static_cast<int>(sq);
        return -1;
    }
};