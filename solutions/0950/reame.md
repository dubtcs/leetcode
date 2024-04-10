# 950. Reveal Cards In Increasing Order 🟡

You are given an integer array `deck`. There is a deck of cards where every card has a unique integer. The integer on the `ith` card is `deck[i]`.

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

 - Take the top card of the deck, reveal it, and take it out of the deck.
 - If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
 - If there are still unrevealed cards, go back to step 1. Otherwise, stop.

Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.

```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        std::sort(deck.begin(), deck.end());
        //std::queue<int> q{std::from_range_t, std::ranges::iota(0, deck.size() - 1)};
        std::queue<int> q{};
        for(int i{ 0 }; i < deck.size(); i++)
            q.push(i);

        std::vector<int> r(deck.size(), 0);
        for(int& n : deck)
        {
            int pos{ q.front() };
            r[pos] = n;
            q.pop();
            int temp{ q.front() };
            q.pop();
            q.push(temp);
        }
        
        return r;
    }
};
```
