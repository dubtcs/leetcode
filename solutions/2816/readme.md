# 2816. Double a Number Represented as a Linked List 🟡

You are given the `head` of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the `head` of the linked list after doubling it.

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
    ListNode* doubleIt(ListNode* head) {
        ListNode* seeker{ head };
        ListNode* temp{ nullptr };
        ListNode* next{ nullptr };

        while(seeker)
        {
            next = seeker->next;
            seeker->next = temp;
            temp = seeker;

            if(!next)
                break;
            seeker = next;
        }

        temp = nullptr;

        int carry{ 0 };
        while(seeker)
        {
            next = seeker->next;
            seeker->next = temp;
            temp = seeker;

            seeker->val *= 2;
            seeker->val += carry;
            carry = (seeker->val >= 10);
            if(carry)
                seeker->val -= 10;
            
            seeker = next;
        }

        if(carry)
        {
            ListNode* node{ new ListNode{ carry } };
            node->next = head;
            head = node;
        }

        return head;
    }
};
```