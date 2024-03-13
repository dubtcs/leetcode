
class Solution {
public:
    string customSortString(string order, string s) {
        std::unordered_map<char, int> cont{};
        for(char& c : s)
            cont[c]++;

        std::string r{};
        for(char& c : order) // order is sorted the way we want, so use it as a guide
        {
            if(cont.contains(c))
            {
                while(cont.at(c)--) // while non zero
                    r += c;
            }
        }

        for(char& c : s)
            if(cont[c]-- > 0)
                r += c;

        return r;
    }
};
