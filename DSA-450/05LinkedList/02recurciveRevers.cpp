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

    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        // this will take us at the end of the ll and the nodes except head will be reversed
        Node *newHead = reverse(head->next);
        // now we have to change only one link
        //1->2<-3<-4<-5
        // 1 is our head and 5 is our newhead

        head->next->next = head;
        // 1<-2<-3<-4<-5

        head->next = NULL;
        // Null<-1<-2<-3<-4<-5

        return newHead;
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

    ll.head = ll.reverse(ll.head);

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
