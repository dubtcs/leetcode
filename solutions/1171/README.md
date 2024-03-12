
# 1171. Remove Zero Sum Consecutive Nodes from Linked List 🟡

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

```cpp
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy{ new ListNode{ 0, head } };
        ListNode* seeker{ dummy };
        std::unordered_map<int, ListNode*> sums{};

        int sum{ 0 };
        while(seeker)
        {
            sum += seeker->val;
            sums[sum] = seeker; // this will replace existing entries and end up skipping them in second pass
            seeker = seeker->next;
        }

        sum = 0;
        seeker = dummy;
        while(seeker)
        {
            sum += seeker->val;
            seeker->next = sums[sum]->next;
            seeker = seeker->next;
        }

        return dummy->next;
    }
};
```
