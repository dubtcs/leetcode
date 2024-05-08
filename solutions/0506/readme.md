# 506. Relative Ranks 🟢

You are given an integer array `score` of size `n`, where `score[i]` is the score of the `ith` athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the `1st` place athlete has the highest score, the `2nd` place athlete has the `2nd` highest score, and so on. The placement of each athlete determines their rank:

 - The `1st` place athlete's rank is `"Gold Medal"`.
 - The `2nd` place athlete's rank is `"Silver Medal"`.
 - The `3rd` place athlete's rank is `"Bronze Medal"`.
 - For the `4th` place to the `nth` place athlete, their rank is their placement number (i.e., the `xth` place athlete's rank is `"x"`).

Return an array `answer` of size `n` where `answer[i]` is the rank of the `ith` athlete.

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::vector<std::pair<int, int>> indices{};
        for(int i{ 0 }; i < score.size(); i++)
            indices.push_back({score.at(i), i});

        std::sort(indices.begin(), indices.end(), 
        [](std::pair<int, int>& A, std::pair<int, int>& B)
        {
            return A.first > B.first;
        });
        std::vector<std::string> r(score.size(), "");
        for(int i{ 0 }; (i < 3) && (i < score.size()); i++)
        {
            if(i == 0)
                r.at(indices.at(i).second) = "Gold Medal";
            else if(i == 1)
                r.at(indices.at(i).second) = "Silver Medal";
            else if(i == 2)
                r.at(indices.at(i).second) = "Bronze Medal";
        }
        for(int i{ 3 }; i < score.size(); i++)
            r.at(indices.at(i).second) = std::to_string(i + 1);
        return r;
    }
};
```