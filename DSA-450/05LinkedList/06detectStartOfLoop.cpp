// Link: https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *next;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

Node *detectCycle(Node *node)
{
    unordered_set<Node *> set;
    if (node == NULL)
    {
        return NULL;
    }
    while (node != NULL)
    {
        if (set.find(node) != set.end())
        {
            return node;
        }
        else
        {
            set.insert(node);
        }
        node = node->next;
    }
    return NULL;
}

int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    Node *res = detectCycle(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;

    return 0;
}
