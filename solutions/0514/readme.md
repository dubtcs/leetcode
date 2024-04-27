# 514. Freedom Trail 🔴

In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.

Given a string `ring` that represents the code engraved on the outer ring and another string `key` that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the `"12:00"` direction. You should spell all the characters in `key` one by one by rotating `ring` clockwise or anticlockwise to make each character of the string key aligned at the `"12:00"` direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character `key[i]`:

1. You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the `"12:00"` direction, where this character must equal `key[i]`.

2. If the character `key[i]` has been aligned at the `"12:00"` direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.

```cpp
class Solution {
public:
    int jittleyang(std::string& ring, std::string& key, int ringIndex, int keyIndex, std::unordered_map<int, std::unordered_map<int, int>>& found)
    {
        if(keyIndex == key.size())
            return 0;
        if(found[ringIndex].contains(keyIndex))
            return found[ringIndex].at(keyIndex);

        int r{ std::numeric_limits<int>::max() };
        for(int i{ 0 }; i < ring.size(); i++)
        {
            char& c{ ring.at(i) };
            if(c == key.at(keyIndex))
            {
                int cur{ std::abs(ringIndex - i) };
                cur = std::min(cur, static_cast<int>(ring.size()) - cur);
                r = std::min(r, cur + jittleyang(ring, key, i, keyIndex + 1, found) + 1);
            }
        }
        found[ringIndex][keyIndex] = r;
        return r;
    }
    int findRotateSteps(string ring, string key) {
        std::unordered_map<int, std::unordered_map<int, int>> found{};
        return jittleyang(ring, key, 0, 0, found);
    }
};
```
