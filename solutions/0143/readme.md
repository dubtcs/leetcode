# 143. Reorder List 🟡

You are given the head of a singly linked-list. The list can be represented as:

> L0 → L1 → … → L(n - 1) → Ln

Reorder the list to be on the following form:

> L0 → Ln → L1 → L(n - 1) → L2 → L(n - 2) → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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
    void reorderList(ListNode* head) {
        ListNode* fast{ head };
        ListNode* slow{ head };
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid{ slow };

        ListNode* prev{ nullptr };
        ListNode* next{ nullptr };
        while(mid != nullptr)
        {
            next = mid->next;
            mid->next = prev;
            prev = mid;
            if(next != nullptr)
                mid = next;
            else
                break;
        }

        ListNode* last{ mid };
        ListNode* seeker{ head };
        while(seeker != nullptr)
        {
            next = seeker->next;
            seeker->next = mid;
            seeker = next;
            if(mid != nullptr)
            {
                next = mid->next;
                mid->next = seeker;
                mid = next;
            }
        }

        if(mid != nullptr)
            mid->next = nullptr;
        
        return;
    }
};
```
