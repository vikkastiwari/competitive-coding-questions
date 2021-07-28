// https://www.geeksforgeeks.org/reverse-a-linked-list/

#include <iostream>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL, *next = NULL;

        while (curr != NULL)
        {
            // updating our next pointer
            next = curr->next;
            curr->next = prev;

            // updating our prev pointer
            prev = curr;
            // updating our curr pointer
            curr = next;
        }
        // assign reversed linkedlists first node(prev) to head
        head = prev;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
