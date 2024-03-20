# 1669. Merge In Between Linked Lists 🟡

You are given two linked lists: ```list1``` and ```list2``` of sizes ```n``` and ```m``` respectively.

Remove ```list1```'s nodes from the ```ath``` node to the ```bth``` node, and put ```list2``` in their place.

The blue edges and nodes in the following figure indicate the result:

![demo](https://assets.leetcode.com/uploads/2020/11/05/fig1.png)

Build the result list and return its head.

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* seeker{ list1 };
        ListNode* seeker2{ list2 };

        // find start
        int index{ 0 };
        while((index < (a - 1)) && (seeker != nullptr))
        {
            seeker = seeker->next;
            index++;
        }
        ListNode* putAt{ seeker };
        
        // find list2 end
        while(seeker2 != nullptr)
        {
            if(seeker2->next == nullptr)
            {
                //std::cout << "Monday left me broken\n";
                break;
            }
            seeker2 = seeker2->next;
        }

        // skip to insertion end
        while((index <= b) && (seeker != nullptr))
        {
            seeker = seeker->next;
            index++;
        }

        putAt->next = list2;
        seeker2->next = seeker;

        return list1; // always (a >= 1) so list1 will always be returned
    }
};
```
