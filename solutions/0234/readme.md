# 234. Palindrome Linked List 🟢

Given the ```head``` of a singly linked list, return ```true``` if it is a 
palindrome or ```false``` otherwise.

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
    bool isPalindrome(ListNode* head) {
        ListNode* seeker{ head };
        ListNode* faster{ head };

        while(faster != nullptr)
        {
            if(faster->next != nullptr && faster->next->next != nullptr)
            {
                faster = faster->next->next;
                seeker = seeker->next;
            }
            else
                break;
        }

        ListNode* prev{ nullptr };
        while(seeker != nullptr)
        {
            faster = seeker->next;
            seeker->next = prev;
            prev = seeker;
            if(faster != nullptr)
                seeker = faster;
            else
                break;
        }

        faster = head;
        while(faster != nullptr && seeker != nullptr)
        {
            if(faster->val != seeker->val)
                return false;
            seeker = seeker->next;
            faster = faster->next;
        }

        return true;
    }
};
```