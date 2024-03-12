
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
