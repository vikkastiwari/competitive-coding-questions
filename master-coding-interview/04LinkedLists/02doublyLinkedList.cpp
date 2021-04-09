#include <bits/stdc++.h>
using namespace std;

/*
Doubly Linked List
It has two pointer reference prev and next 
Node = [Prev | Data | Next]
*/

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
    // Two pointers of class node
    Node *head, *tail;
    int totalNodes;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        totalNodes = 0;
    }

    void append(int data)
    {
        // function appends the newly created node at the end
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = newNode->prev = NULL;

        if (totalNodes == 0)
        {
            // if the DLL is empty then head and tail is assgined to newNode
            head = newNode;
            tail = newNode;
            totalNodes++;
        }
        else
        {
            // set the pointer reference and make the newNode as tail respectively
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = NULL;
            tail = newNode;
            totalNodes++;
        }
    }

    void prepend(int data)
    {
        // function which appends the data at the beginning of the DLL
        //O(1) time complexity
        if (totalNodes == 0)
        {
            append(data);
        }
        else
        {
            // new node created
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = newNode->prev = NULL;

            // set the pointer reference and make the newly created node as head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            totalNodes++;
        }
    }

    void insertBetween(int data, int pos)
    {
        // insert nodes anywhere in the LL
        if (pos < 1 || pos > totalNodes + 1)
        {
            cout << "[WARNING]Invalid Position" << endl;
            return;
        }
        else if (pos == 1)
        {
            // for first position
            prepend(data);
        }
        else if (pos == totalNodes + 1)
        {
            // for last position
            append(data);
        }
        else
        {
            // node created and data & pointers assigned
            Node *newNode = new Node;
            newNode->data = data;
            newNode->prev = NULL;
            newNode->next = NULL;

            // here we start from tail and goto the exact position where we have to insert the node
            Node *temp = tail;
            for (int i = totalNodes - 1; i >= pos; i--)
            {
                // updating temp one at a time to move from tail to required pos
                temp = temp->prev;
            }
            // updating the reference pointers of newly created node
            // so it points correctly to prev and next node
            newNode->next = temp;
            newNode->prev = temp->prev;
            // we are pointing to the previous nodes, next pointer reference's block to store the reference of newly created node
            temp->prev->next = newNode;
            totalNodes++;
        }
    }

    void removeElement(int pos)
    {
        if (pos < 1 || pos > totalNodes)
        {
            cout << "[WARNING]Invalid positon" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            Node *ptr;
            if (pos == 1)
            {
                head = head->next;
                free(temp);
                totalNodes--;
                return;
            }
            // traverse through the list and stop just before the element that is to be deleted
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
                totalNodes--;
            }
            else
            {
                temp->prev->next = NULL;
                // as tail is being deleted so assign the new previous node as new tail
                tail = tail->prev;
                free(temp);
                totalNodes--;
            }
        }
    }

    void reverse()
    {
        Node *temp = NULL;
        Node *current = head;

        while (current != NULL)
        {
            // swapping
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // updating current
            current = current->prev;
        }
        /* 
        Before changing the head, check for the cases like empty 
        list and list with only one node 
        */
        if (temp != NULL)
        {
            // we are updating head
            head = temp->prev;
        }
    }

    void count()
    {
        cout << "Total Nodes: " << totalNodes << endl;
    }

    void display()
    {
        // function to print the DLL
        if (head == NULL)
        {
            cout << "Please Create a Doubly Linked List" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "--->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList DLL;

    DLL.prepend(5);
    DLL.display();

    DLL.append(25);
    DLL.append(20);
    DLL.append(15);
    DLL.append(10);
    DLL.display();

    DLL.insertBetween(13, 5);
    DLL.display();
    DLL.insertBetween(16, 1);
    DLL.display();
    DLL.insertBetween(19, 8);
    DLL.display();
    DLL.insertBetween(14, 10);
    DLL.display();

    DLL.removeElement(1);
    DLL.display();
    DLL.removeElement(7);
    DLL.display();
    DLL.removeElement(8);
    DLL.display();

    DLL.reverse();
    DLL.display();

    DLL.count();

    return 0;
}
