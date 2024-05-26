# 552. Student Attendance Record II 🔴

An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

 - `'A'`: Absent.
 - `'L'`: Late.
 - `'P'`: Present.

Any student is eligible for an attendance award if they meet both of the following criteria:

 - The student was absent (`'A'`) for strictly fewer than 2 days total.
 - The student was never late (`'L'`) for 3 or more consecutive days.

 Given an integer `n`, return the number of possible attendance records of length `n` that make a student eligible for an attendance award. The answer may be very large, so return it modulo `10^9 + 7`.

```cpp
inline constexpr int MOD_LIM{ 1'000'000'007 };
class Solution {
public:
    int CheckFor(int length, int abs, int lates, std::vector<std::vector<std::vector<int>>>& data, int& k)
    {
        if(length >= k)
            return 1;
        
        if(data.at(length).at(abs).at(lates))
            return data.at(length).at(abs).at(lates);
        
        length++;
        
        int r{ 0 };
        if(!abs)
            r += CheckFor(length, abs + 1, 0, data, k);
        if(lates < 2)
            r += CheckFor(length, abs, lates + 1, data, k);

        r %= MOD_LIM;
        r += CheckFor(length, abs, 0, data, k);
        r %= MOD_LIM;
        
        length--;

        data.at(length).at(abs).at(lates) = r;

        return r;
    }
    int checkRecord(int n) {
        // current length [ current absences ] [ consecutive late ]
        //      n,                  2,                  3
        // required length,    max absence,    max consecutive late
        std::vector<std::vector<std::vector<int>>> data(n, std::vector<std::vector<int>>(2, std::vector<int>(3, 0)));
        return CheckFor(0, 0, 0, data, n);
    }
};
```