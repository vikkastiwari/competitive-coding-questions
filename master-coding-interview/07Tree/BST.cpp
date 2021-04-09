// Binary Search Tree Implementation

/*
Tree Structure 

         20 --- Root Node
        /  \
      10   30 --- Child Nodes
     /    /  \
    1    25  40 --- Leaf Nodes
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class binarySearchTree
{
    Node *root;

public:
    // Initialized root to null
    binarySearchTree()
    {
        root = NULL;
    }

    // Insert Function
    void insertNode(int data)
    {
        Node *newNode = new Node(data);

        /*  
        temp Pointer to start traversing from root 
        and traverses downward path to search
        where the new node to be inserted     
        */
        Node *temp = root;

        // with the help of leaf node we will understand where the node has to be inserted
        Node *leaf = NULL;

        // Traverse upto the leaf node w.r.t to data
        while (temp != NULL)
        {
            leaf = temp;
            if (data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        // Assign the newNode
        if (leaf == NULL) // When tree is empty
        {
            root = newNode;
        }
        else if (data < leaf->data) // Assign newNode to the left of leaf node
        {
            leaf->left = newNode;
        }
        else // Assign newNode to the left of leaf node
        {
            leaf->right = newNode;
        }
    }

    // int deleteNode(int data)
    // {
    //     if (root == NULL)
    //     {
    //         cout << "[WARNING]Tree is empty." << endl;
    //         return;
    //     }

    //     // pointer for traversing data if present
    //     Node *temp = root; // currentNode
    //     // trailing pointer that points to the parent node(intermediate nodes)
    //     Node *parent = NULL;

    //     while (temp)
    //     {
    //         if (data < temp->data)
    //         {
    //             parent = temp;
    //             temp = temp->left;
    //         }
    //         else if (data > temp->data)
    //         {
    //             parent = temp;
    //             temp = temp->right;
    //         }
    //         else if (temp->data == data)
    //         { //We have a match, get to work!

    //             //Option 1: No right child:
    //             if (temp->right == NULL)
    //             {
    //                 if (parent == NULL)
    //                 {
    //                     root = temp->left;
    //                 }
    //                 else
    //                 {
    //                     //if parent > current value, make current left child a child of parentif (temp->data < parent->data)
    //                     {
    //                         parent->left = temp->left;
    //                     }
    //                     //if parent < current value, make left child a right child of parent
    //                     else if (temp->data > parent->data)
    //                     {
    //                         parent->right = temp->left;
    //                     }
    //                 }
    //             }
    //             //Option 2: Right child which doesnt have a left child
    //             else if (temp->right->left == NULL)
    //             {
    //                 temp->right->left = temp->left;
    //                 if (parent == NULL)
    //                 {
    //                     root = temp->right;
    //                 }
    //                 else
    //                 {
    //                     //if parent > current, make right child of the left the parent
    //                     if (temp->data < parent->data)
    //                     {
    //                         parent->left = temp->right;
    //                         //if parent < current, make right child a right child of the parent
    //                     }
    //                     else if (temp->data > parent->data)
    //                     {
    //                         parent->right = temp->right;
    //                     }
    //                 }
    //             }
    //             //Option 3: Right child that has a left child
    //             else
    //             {
    //                 //find the Right child's left most child
    //                 Node *leftmost = temp->right->left;
    //                 Node *leftmostParent = temp->right;
    //                 while (leftmost->left != NULL)
    //                 {
    //                     leftmostParent = leftmost;
    //                     leftmost = leftmost->left;
    //                 }

    //                 //Parent's left subtree is now leftmost's right subtree
    //                 leftmostParent->left = leftmost->right;
    //                 leftmost->left = temp->left;
    //                 leftmostParent->right = temp->right;

    //                 if (parent == NULL)
    //                 {
    //                     root = leftmost;
    //                 }
    //                 else
    //                 {
    //                     if (temp->data < parent->data)
    //                     {
    //                         parent->left = leftmost;
    //                     }
    //                     else if (temp->data > parent->data)
    //                     {
    //                         parent->right = leftmost;
    //                     }
    //                 }
    //             }
    //         }
    //         return true;
    //     }
    //     // cout << "No Nodes Found to delete" << endl;
    // }

    // Find particular value/data in tree
    bool lookup(int data)
    {
        if (root == NULL)
        {
            cout << "Oops! Tree Is Empty :(" << endl;
        }
        Node *temp = root;
        // traversing throughout the tree
        while (temp != NULL)
        {
            if (temp->data > data) // goto left of node w.r.t to data
            {
                temp = temp->left;
            }
            else if (temp->data < data) // goto right of node w.r.t to data
            {
                temp = temp->right;
            }
            else if (temp->data == data) // if data matches then return true
            {
                return true;
            }
        }
        return false;
    }

    // Display the tree
    void display()
    {
        stack<Node *> s;
        Node *temp = root;

        while (temp != NULL || s.empty() == false)
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left; // going towards left first
            }
            temp = s.top();
            cout << temp->data << "  "; // printing the left most data.
            s.pop();

            temp = temp->right;
        }
        cout << endl;
    }
};

int main()
{
    binarySearchTree bst;

    bst.insertNode(20);
    bst.insertNode(10);
    bst.insertNode(30);
    bst.insertNode(25);
    bst.insertNode(40);
    bst.insertNode(1);

    bst.display();

    bst.deleteNode(25);

    bst.display();

    cout << bst.lookup(20) << endl;
    cout << bst.lookup(100) << endl;

    bst.display();

    return 0;
}