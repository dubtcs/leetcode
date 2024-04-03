# 79. Word Search 🟡

Given an ```m x n``` grid of characters ```board``` and a string ```word```, return ```true``` if ```word``` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

### Commentary

 - I originally used a map of sets to keep track of visited cells, but it took too long and would cause false flags

```cpp
class Solution {
public:
    using fset = std::unordered_map<int, std::unordered_set<int>>;
    bool dive(int x, int y, int index, std::string& word, std::vector<std::vector<char>>& board)
    {
        if(index == word.size())
            return true;

        bool contains{ false };
        if((y >= board.size()) || (x >= board.front().size()) || (y < 0) || (x < 0))
            return false;
        if(word.at(index) != board.at(y).at(x))
            return false;

        index++;
        char t{ board[y][x] };
        board[y][x] = '\0';
        contains = dive(x + 1, y, index, word, board) ||
                    dive(x - 1, y, index, word, board) ||
                    dive(x, y + 1, index, word, board) ||
                    dive(x, y - 1, index, word, board);
        board[y][x] = t;
        return contains;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool contains{ false };
        for(int y{ 0 }; y < board.size(); y++)
        {
            for(int x { 0 }; x < board.front().size(); x++)
            {
                contains = dive(x, y, 0, word, board);
                if(contains)
                    return contains;
            }
        }
        return contains;
    }

};
```