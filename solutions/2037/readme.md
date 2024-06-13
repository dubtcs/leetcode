# 2037. Minimum Number of Moves to Seat Everyone 🟢

There are `n` seats and `n` students in a room. You are given an array `seats` of length `n`, where `seats[i]` is the position of the `ith` seat. You are also given the array students of length `n`, where `students[j]` is the position of the `jth` student.

You may perform the following move any number of times:

Increase or decrease the position of the `ith` student by `1` (i.e., moving the `ith` student from position `x to x + 1` or `x - 1`)
Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

Note that there may be multiple seats or students in the same position at the beginning.

### Explanation

The hardest part of this question was understanding what tf it was actually asking

Example:
```
Input: seats = [3, 1, 5], students = [2, 7, 4]

            Positions
Seats:      [ ] [x] [ ] [x] [ ] [x] [ ] [ ]
Students:   [ ] [ ] [x] [ ] [x] [ ] [ ] [x]
```

Problem is asking how many moves it would take for each sutdent to be moved to a position that has a seat.

Sort both input arrays. Because they are guaranteed to be equal size, you can then iterate from `[0, size()]` and take the absolute value of the difference between the two entries of each array. This works because they are now in sorted order, meaning the student with the lowest value is closest to the seat with the lowest value, so just take that difference and put them there.

```cpp
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        int count{ 0 };
        for(int i{ 0 }; i < seats.size(); i++)
            count += std::abs(seats.at(i) - students.at(i));
        return count;
    }
};
```