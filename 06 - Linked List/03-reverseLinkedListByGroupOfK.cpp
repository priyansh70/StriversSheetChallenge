// Time Complexity - O(N)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || !head->next || k == 1)
    {
        return head;
    }
    // Create a dummy node. Point next to this node to head of the linked list provided.
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    // Create three pointer pre,cur and nex to reverse each group.
    // Why? If we observe output, we can see that we have to reverse each group,
    //  apart from modifying links of group.

    ListNode *curr = head;
    ListNode *prev = dummy;
    ListNode *next = dummy;
    int count = 0;

    // Iterate through the given linked list to get the length of the list.
    while (curr)
    {
        count++;
        curr = curr->next;
    }

    // Iterate through the linked list until the length of list to be
    //  processed is greater than and equal to given k.
    while (count >= k)
    {
        // For each iteration, point cur to pre->next and nex to nex->next.
        curr = prev->next;
        next = curr->next;

        // Start nested iteration for length of k.
        for (int i = 1; i < k; i++)
        {
            // For each iteration, modify links as following steps:-
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }

        // Move pre to cur and reduce length by k.
        prev = curr;
        count -= k;
    }

    return dummy->next;
}