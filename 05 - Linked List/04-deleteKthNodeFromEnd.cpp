// Time Complexity - O(n)
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    for (int i = 1; i <= n; i++)
    {
        fast = fast->next;
    }

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
}