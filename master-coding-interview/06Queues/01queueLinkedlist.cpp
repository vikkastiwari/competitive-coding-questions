// Queue using Linked List

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
    int totalElements;
    Node *last, *first;

public:
    Queue()
    {
        last = NULL;
        first = NULL;
        totalElements = 0;
    }

    void preAppend(int data)
    {
        Node *newNode = new Node(data);

        if (first == NULL)
        {
            first = newNode;
            last = newNode;
            totalElements++;
            return;
        }

        newNode->next = last;
        last = newNode;
        totalElements++;
    }

    void peek()
    {
        cout << "Peek: " << first->data << endl;
        return;
    }

    void remove()
    {
        if (first == NULL)
        {
            cout << "[WARNING]Queue is empty." << endl;
            return;
        }

        Node *temp = last;
        for (int i = 1; i < totalElements - 1; i++)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        first = temp;
    }

    void display()
    {
        if (first == NULL)
        {
            cout << "[WARNING]Queue is empty." << endl;
            return;
        }
        Node *temp = last;
        for (int i = 0; i < totalElements && temp != NULL; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.preAppend(12);
    q.preAppend(32);
    q.preAppend(2);
    q.preAppend(22);
    q.display();

    q.remove();
    q.display();

    q.preAppend(36);
    q.display();

    q.peek();
    return 0;
}