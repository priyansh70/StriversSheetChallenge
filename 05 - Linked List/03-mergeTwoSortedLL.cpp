// Time Complexity - O(n+m)
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    if (list1->val > list2->val)
    {
        swap(list1, list2);
    }

    ListNode *head = list1;

    while (list1 && list2)
    {
        ListNode *temp = NULL;

        while (list1 != NULL && list1->val <= list2->val)
        {
            temp = list1;
            list1 = list1->next;
        }

        temp->next = list2;
        swap(list1, list2);
    }
    return head;
}