# N-th Tribonacci Number 🟢

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given `n`, return the value of Tn.

```cpp
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        int n1{ 1 }; // n - 1 
        int n2{ 1 }; // n - 2
        int n3{ 0 }; // n - 3
        for(int i{ 3 }; i <= n; i++)
        {
            int temp{ n1 };
            n1 += n2 + n3;
            n3 = n2;
            n2 = temp;
        }
        return n1;
    }
};
```