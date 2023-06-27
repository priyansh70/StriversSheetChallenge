// Time Complexity - O(N)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
Node *merge(Node *list1, Node *list2)
{
    Node *result = new Node();
    Node *temp = result;

    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            temp->child = list1;
            temp = temp->child;
            list1 = list1->child;
        }
        else
        {
            temp->child = list2;
            temp = temp->child;
            list2 = list2->child;
        }
    }

    if (list1)
        temp->child = list1;
    if (list2)
        temp->child = list2;

    return result->child;
}
Node *flattenLinkedList(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *temp = flattenLinkedList(head->next);
    head->next = NULL;
    head = merge(head, temp);

    return head;
}