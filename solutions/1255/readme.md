# 1255. Maximum Score Words Formed by Letters 🔴

Given a list of `words`, list of single `letters` (might be repeating) and `score` of every character.

Return the maximum score of any valid set of words formed by using the given letters (`words[i]` cannot be used two or more times).

It is not necessary to use all characters in `letters` and each letter can only be used once. Score of letters `'a'`, `'b'`, `'c'`, ... ,`'z'` is given by `score[0]`, `score[1]`, ... , `score[25]` respectively.

### Commentary

 - It feels good to solve a hard problem completely independently, even though I think it should be a medium 🟡

```cpp
class Solution {
public:
    int dive(int index, std::vector<std::string>& words, std::vector<int>& wordScores, std::vector<int> bank)
    {
        if(index >= wordScores.size())
            return 0;

        std::string& cur{ words.at(index) };
        for(int i{ 0 }; i < cur.size(); i++)
        {
            int& co{ bank[cur.at(i) - 'a'] };
            co--;
            if(co < 0)
                return 0;
        }

        int total{ wordScores.at(index) };
        int smax{ 0 };
        for(int i{ index + 1 }; i < words.size(); i++)
            smax = std::max(smax, dive(i, words, wordScores, bank));
        total += smax;
            
        return total;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        std::vector<int> bank(26, 0); // char usage amount
        for(char& c : letters)
            bank[c - 'a']++;
        
        std::vector<int> wordScores{};
        for(std::string& s : words)
        {
            int cur{ 0 };
            for(char& c : s)
                cur += score.at(c - 'a');
            wordScores.push_back(cur);
        }

        int best{ 0 };
        for(int i{ 0 }; i < words.size(); i++)
            best = std::max(best, dive(i, words, wordScores, bank));
        
        return best;
    }
};
```