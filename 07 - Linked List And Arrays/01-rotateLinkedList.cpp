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
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    ListNode *curr = head;
    int len = 1;

    // Get Length
    while (curr->next)
    {
        len++;
        curr = curr->next;
    }

    // Last Node Point to Head
    curr->next = head;

    // Iterate to cut the link of the last node and start
    // a node of k%length of the list rotated list.
    k = k % len;
    k = len - k;

    while (k--)
    {
        curr = curr->next;
    }

    // Set Head To New Head
    head = curr->next;
    // Last Node to Null
    curr->next = NULL;

    return head;
}