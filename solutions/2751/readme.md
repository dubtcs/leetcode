# 2751. Robot Collisions 🔴

There are `n` 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays `positions`, `healths`, and a string `directions` (`directions[i]` is either `'L'` for left or `'R'` for right). All integers in `positions` are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.

### Explanation

Make a structure to keep track of a robots position, direction, and corresponding index. Sort a vector of this structure by position from least to greatest. So robots at lower positions are at the front of the array, and greater positions are in the back. Since the start of the array represents the lowest possible position of the robots, we need to keep track of how many robots are going against that, eg going right. Reasoning for this is if a robot is going left and there are no robots going right in front of it, we just move onto the next robot and forget about it.

To do this, create a stack to hold the indices of all right moving robots. Iterate over the array made earlier and if a robot moving **right** is found, add it to the stack. If a robot is moving **left**, check if the right-stack is empty. If it is, just move on. Otherwise, check to see which robot survives per the question description. If the left moving robot survives, keep checking the stack until its either empty or the left moving robot dies.

Once that iteration is complete, just loop over the health array and only add values greater than 0 to a return vector.

```cpp
static constexpr bool DIR_RIGHT{ true };
static constexpr bool DIR_LEFT{ false };
class Solution {
public:
    struct robot{
        int pos{ 0 };
        int index{ 0 };
        bool dir{ DIR_RIGHT };
    };
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // robots 1 indexed <-----
        // unique positions
        std::vector<robot> bots{};
        for(int i{ 0 }; i < positions.size(); i++)
            bots.push_back({positions.at(i), i, directions.at(i) == 'R'});
        std::sort(bots.begin(), bots.end(), [](robot& A, robot& B){return A.pos < B.pos;});

        std::stack<int> rights{};
        for(int i{ 0 }; i < bots.size(); i++)
        {
            robot& cur{ bots.at(i) };
            if(cur.dir == DIR_LEFT)
            {
                while(!rights.empty())
                {
                    robot& top{ bots.at(rights.top()) };
                    int& curh{ healths.at(cur.index) };
                    int& toph{ healths.at(top.index) };
                    if(curh < toph) // top moves one
                    {
                        toph--;
                        curh = 0;
                        break;
                    }
                    else if(curh > toph) // cur moves on
                    {
                        curh--;
                        toph = 0;
                        rights.pop();
                    }
                    else // they both die
                    {
                        curh = 0;
                        toph = 0;
                        rights.pop();
                        break;
                    }
                }
            }
            else
            {
                rights.push(i);
            }
        }
        
        std::vector<int> r{};
        for(int& i : healths)
        {
            if(i > 0)
                r.push_back(i);
        }

        return r;
    }
};
```