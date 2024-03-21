# 206. Reverse Linked List 🟢

Given the ```head``` of a singly linked list, reverse the list, and return the reversed list.

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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev{ nullptr };

        while(head != nullptr)
        {
            ListNode* next{ head->next };
            head->next = prev;
            prev = head;
            if(next == nullptr)
                break;
            head = next;
        }

        return head;
    }
};
```
