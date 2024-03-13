# 876. Middle of the Linked List 🟢

Given the ```head``` of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* slow{ head };
        ListNode* fast{ head };
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next && fast->next->next == nullptr)
            slow = slow->next;
        return slow;
    }
};
```