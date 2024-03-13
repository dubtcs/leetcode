class Solution {
public:
    int minimumLength(string s) {
        int len{ static_cast<int>(s.size()) };
        std::size_t left{ 0 };
        std::size_t right{ s.size() - 1 };
        bool removing{ false };
        char removal{ '\0' };
        while(left < right)
        {
            removing = (s.at(left) == s.at(right));
            if(!removing)
                return len;
            removal = s.at(left);

            while(removing && (left < right))
            {
                if(s.at(left) == removal)
                {
                    len--;
                    left++;
                }
                if(s.at(right) == removal)
                {
                    len--;
                    right--;
                }
                if(s.at(right) != removal && s.at(left) != removal)
                    break;
            }
        }
        if(removing && s.at(left) == removal) // check for break on (left < right) remaining character
            len--;

        return std::max(0, len);
    }
};