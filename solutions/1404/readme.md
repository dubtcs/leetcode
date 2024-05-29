# 1404. Number of Steps to Reduce a Number in Binary Representation to One 🟡

Given the binary representation of an integer as a string `s`, return the number of steps to reduce it to `1` under the following rules:

 - If the current number is even, you have to divide it by `2`.

 - If the current number is odd, you have to add `1` to it.

It is guaranteed that you can always reach one for all test cases.

```cpp
class Solution {
public:
    int numSteps(string s) {
        // s can be 500 length so no int representation
        int steps{ 0 };
        int carry{ 0 };
        // loop through, always add 1 step
        // after the first 1, each 0 is then counted as 2
        for(int i{ static_cast<int>(s.size() - 1) }; i > 0; i--)
        {
            steps++;
            if((s.at(i) == '1') + carry == 1)
            {
                steps++;
                carry = 1;
            }
        }
        return steps + carry;
     }
};
/*
if(carry == 0 && s.at(i) == '1')
{
    steps++;
    carry = 1;
}
if(s.at(i) == '0' && carry)
    steps++;
*/
```

- This one I find a little easier to understand but it looks ugly
```cpp
class Solution {
public:
    int numSteps(string s) {
        // s can be 500 length so no int representation
        int steps{ 0 };
        int carry{ 0 };
        // loop through, always add 1 step
        // after the first 1, each 0 is then counted as 2
        int i{ static_cast<int>(s.size() - 1) };
        while(i > 0)
        {
            steps++;
            if(s.at(i--) == '1')
            {
                steps++;
                carry = 1;
                break;
            }
        }
        
        while(i > 0)
            steps += (s.at(i--) == '0') + 1;
        
        return steps + carry;
     }
};
```