// link: https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void moveToFront(Node **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    struct Node *secLast = NULL;
    struct Node *last = *head_ref;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }

    secLast = NULL;
    last->next = *head_ref;
    *head_ref = last;
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node *start = NULL;

    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout << "Linked list before moving last to front\n";
    printList(start);

    moveToFront(&start);

    cout << "\nLinked list after removing last to front\n";
    printList(start);

    return 0;
}