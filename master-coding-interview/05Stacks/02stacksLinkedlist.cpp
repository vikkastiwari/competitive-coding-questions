// stacks using Linked List

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

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "[WARNING]Stack is empty." << endl;
            return;
        }
        Node *current = top;
        cout << "[INFO]Popped Element: " << top->data << endl;
        top = top->next;
        free(current);
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "[WARNING]Stack is empty." << endl;
            return;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(12);
    s.push(11);
    s.push(21);
    s.push(32);
    s.push(2);
    s.display();

    s.pop();
    s.display();
    return 0;
}