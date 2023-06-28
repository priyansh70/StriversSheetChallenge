// Time Complexity - O(N)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

Node *copyRandomList(Node *head)
{

    // step 1 - Create Clone Node by using next Pointer
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    // step2 - cloneNodes add in between original Nodes

    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode && cloneNode)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step3 - random pointer copy

    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            temp->next->random = temp->random ? temp->random->next : temp->random;
        }

        temp = temp->next->next;
    }

    // step 4: revert step 2 changes
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode)
        {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    // step5 return answer
    return cloneHead;
}