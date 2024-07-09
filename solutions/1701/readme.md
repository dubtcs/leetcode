# 1701. Average Waiting Time 🟡

There is a restaurant with a single chef. You are given an array `customers`, where `customers[i] = [arrivali, timei]`:

 - `arrivali` is the arrival time of the `ith` customer. The arrival times are sorted in **non-decreasing** order.
 - `timei` is the time needed to prepare the order of the `ith` customer.

When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

Return the average waiting time of all customers. Solutions within `10-5` from the actual answer are considered accepted.

### Explanation

Iterate over `customers`. For each customer, check if the current time is less than the customers arrival time. If it is, just set the time to said arrival time. This is because we don't want to add any additional wait time if a customer shows up while the chef is idle. Then, just add the cook time to total time. Subtract the start time from current time and add it to a counter.

 - Each value can be `1 <= i <= 10^4` so do 64 bit int for time counter

```cpp
class Solution {
public:
    // customers is already sorted
    double averageWaitingTime(vector<vector<int>>& customers) {
        double r{ 0 };
        std::int64_t time{ customers.front().front() };
        for(std::vector<int>& c : customers)
        {
            if(time < c.front()) // incase customers arrives during idle time
                time = c.front();
            time += c.back();
            r += (time - c.front());
        }
        return (r / customers.size());
    }
};
```