// Time Complexity - O(N)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
LinkedListNode<int> *getMiddle(LinkedListNode<int> *node)
{
    LinkedListNode<int> *slow = node;
    LinkedListNode<int> *fast = node;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

LinkedListNode<int> *reverseLL(LinkedListNode<int> *node)
{
    LinkedListNode<int> *curr = node;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    if (!head || !head->next)
        return true;

    LinkedListNode<int> *mid = getMiddle(head);
    LinkedListNode<int> *reverse = reverseLL(mid->next);
    LinkedListNode<int> *temp = reverse;
    LinkedListNode<int> *curr = head;

    while (temp)
    {
        if (curr->data != temp->data)
            return false;
        temp = temp->next;
        curr = curr->next;
    }
    mid->next = reverseLL(reverse);
    return true;
}