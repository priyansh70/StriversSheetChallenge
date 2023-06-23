// Time Complexity - O(n)
// Space complexity - O(1)

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;
ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}