# 752. Open the Lock 🟡

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: `'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'`. The wheels can rotate freely and wrap around: for example we can turn `'9'` to be `'0'`, or `'0'` to be `'9'`. Each move consists of turning one wheel one slot.

The lock initially starts at `'0000'`, a string representing the state of the 4 wheels.

You are given a list of `deadends` dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a `target` representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

```cpp
class Solution {
public:
    struct mp
    {
        std::string combo{};
        int turn{ 0 };
    };
    const int comboLength{ 4 };
    int openLock(vector<string>& deadends, string target) {
        std::queue<mp> q{};
        std::unordered_set<std::string> deads{ deadends.begin(), deadends.end() };
        if(deads.contains(target))
            return (-1);

        q.push( { "0000", 0 } );
        while(!q.empty())
        {
            mp& cur{ q.front() };
            if(cur.combo == target)
                return cur.turn;
            if(!deads.contains(cur.combo))
            {
                cur.turn++;
                deads.insert(cur.combo);
                for(int i{ 0 }; i < comboLength; i++)
                {
                    std::string s{ cur.combo };
                    char c{ s.at(i) };

                    s[i] = ((c - 1) < '0') ? '9' : (c - 1);
                    if(!deads.contains(s))
                        q.push({s, cur.turn});

                    s[i] = cur.combo[i];

                    s[i] = ((c + 1) > '9') ? '0' : (c + 1);
                    if(!deads.contains(s))
                        q.push({s, cur.turn});
                }
            }
            q.pop();
        }
        return (-1);
    }
};
```