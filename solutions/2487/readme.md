# 2487. Remove Nodes From Linked List 🟡

You are given the `head` of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the `head` of the modified linked list.

![image](https://assets.leetcode.com/uploads/2022/10/02/drawio.png)

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
    ListNode* removeNodes(ListNode* head) {
        // always atleast 1 node
        int localMin{ head->val };
        ListNode* seeker{ head };
        ListNode* root{ head };
        while(seeker)
        {
            if(seeker->val > localMin)
            {
                ListNode* rem{ root };
                ListNode* lastGood{ root };
                while(rem != seeker)
                {
                    if(rem->val < seeker->val)
                    {
                        if(rem == root)
                            root = root->next;
                        else
                            lastGood->next = rem->next;
                    }
                    else
                        lastGood = rem;
                    rem = rem->next;
                }
            }
            localMin = seeker->val;
            seeker = seeker->next;
        }
        return root;
    }
};
```