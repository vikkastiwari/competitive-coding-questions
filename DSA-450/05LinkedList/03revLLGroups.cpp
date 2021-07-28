// C++ program to reverse a linked list in groups
// of given size
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
};

struct Node *reverse(struct Node *head, int k)
{
    // Complete this method
    stack<Node *> s;
    struct Node *curr = head;
    struct Node *prev = NULL;

    while (curr != NULL)
    {
        int count = 0;
        while (curr != NULL && count < k)
        {
            s.push(curr);
            curr = curr->next;
            count++;
        }

        while (!s.empty())
        {
            // for the first node only
            if (prev == NULL)
            {
                prev = s.top();
                head = prev;
                s.pop();
            }
            else
            {
                prev->next = s.top();
                prev = prev->next;
                s.pop();
            }
        }
    }
    prev->next = NULL;
    return head;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(void)
{
    struct Node *head = NULL;

    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("\nGiven linked list \n");
    printList(head);
    head = reverse(head, 3);

    printf("\nReversed Linked list \n");
    printList(head);

    return 0;
}
