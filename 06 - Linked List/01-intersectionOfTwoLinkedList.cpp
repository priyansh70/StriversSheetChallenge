// Time Complexity - O(2*max(m,n))
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *l1 = headA;
    ListNode *l2 = headB;
    while (l1 != l2)
    {
        l1 = l1 == NULL ? headB : l1->next;
        l2 = l2 == NULL ? headA : l2->next;
    }
    return l1;
}