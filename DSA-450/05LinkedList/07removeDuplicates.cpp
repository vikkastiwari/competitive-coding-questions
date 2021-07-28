// Link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
    int data;
    Node *next;
};

void removeDuplicates(struct Node *head)
{
    while (head->next != NULL)
    {
        if (head->data == head->next->data)
        {
            struct Node *next = head->next->next;
            free(head->next);
            head->next = next;
        }
        else
        {
            head = head->next;
        }
    }
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

int main()
{
    Node *head = NULL;

    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    cout << "Linked list before duplicate removal ";
    printList(head);

    removeDuplicates(head);

    cout << "\nLinked list after duplicate removal ";
    printList(head);

    return 0;
}