#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int priority;
    int data;
    Node *next;
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = NULL;
    }
};

class PriorityQueue
{
    Node *first;

public:
    PriorityQueue()
    {
        first = NULL;
    }

    void enqueue(int data, int elemPriority)
    {
        // we are checking for first if it is null or not
        // if it is null we are assigning the newnode  to it
        // or we are also checking the element priority of newnode
        // if it is less than the priority of first node
        // we create newnode and assign first pointer to it
        // further we check the priority and place that newnode accordingly
        Node *newNode = new Node(data, elemPriority);
        if (first == NULL || elemPriority < first->priority)
        {
            newNode->next = first;
            first = newNode;
            return;
        }
        Node *temp = first;
        while (temp->next != NULL && temp->next->priority <= elemPriority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void dequeue()
    {
        if (first == NULL)
        {
            cout << "Queue is empty, Please insert element first." << endl;
            return;
        }
        // deleting from behind by making check on next pointer of last node
        Node *temp = first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

    void display()
    {
        if (first == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        // traversing from first element to last
        Node *temp = first;
        while (temp != NULL)
        {
            cout << temp->priority << " " << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;
    pq.enqueue(10, 3);
    pq.enqueue(40, 1);
    pq.enqueue(50, 4);
    pq.enqueue(20, 5);
    pq.enqueue(60, 8);
    pq.enqueue(5, 6);
    pq.enqueue(15, 9);

    pq.dequeue();

    pq.display();
}