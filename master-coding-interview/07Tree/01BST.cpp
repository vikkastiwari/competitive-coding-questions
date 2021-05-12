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

    void deleteNode(int data)
    {
        if (root == NULL)
        {
            cout << "Tree is empty, Please insert values.";
        }
        Node *temp = root;
        Node *parent = NULL;
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                parent = temp;
                temp = temp->left;
            }
            else if (data > temp->data)
            {
                parent = temp;
                temp = temp->right;
            }
            else
            {
                if (temp->left == NULL && temp->right == NULL)
                {
                    cout << "--Deleting Leaf Node--" << endl;
                    if (parent->left == temp)
                    {
                        parent->left = NULL;
                    }
                    else
                    {
                        parent->right = NULL;
                    }
                    free(temp);
                    return;
                }
                else if (temp->left == NULL || temp->right == NULL)
                {
                    cout << "--Deleting Parent Node--" << endl;
                    if (temp->left != NULL)
                    {
                        parent->left = temp->left;
                    }
                    else
                    {
                        parent->right = temp->right;
                    }
                    free(temp);
                    return;
                }
                else
                {
                    cout << "--Deleting node which has two child--" << endl;
                    Node *t = temp->right;
                    if (t->left == NULL && t->right == NULL)
                    {
                        temp->data = t->data;
                        temp->right = NULL;
                        free(t);
                        return;
                    }
                    else if (t->left == NULL && t->right != NULL)
                    {
                        temp->data = t->data;
                        temp->right = t->right;
                        free(t);
                        return;
                    }
                    while (t->left != NULL)
                    {
                        parent = t;
                        t = t->left;
                    }
                    temp->data = t->data;
                    parent->left = NULL;
                    free(t);
                    return;
                    /*
The first line t = temp-> right already gives us idea that whatever number we choose to replace temp with will be greater then temp. where temp is the node we want to delete/remove.

Note t is the same variable used in the first line of the code segment

Also, we don't care about left children of temp afterall we have to preserve rules of BST 😉

Now,
in the first case we have something like this

temp
 /    \
x      t
      /  \
   null null
hence we have,
t is the right child node of temp and t doesn't have any children so we take the data of t and replace with data of temp and remove t.

In the second case t has only child node at the right and it can be of any number something like this

temp
 /   \
x      t
         \
           a
             \
               blah blah
so now in the above we are replacing temp data with t data and linking temp of right to t of right. that is temp right is pointing to a. and then free t

In the last condition that is the while loop we have,

temp
 /   \
x      t
      /   \
    b      a
   /         \
 c             blah blah
that is there is some children nodes on the left of t so then we traverse till the last left child in this case c and the swap the data of c and temp and deleting c in this way we are still preserving the rules ofBST.
                    
                    */
                }
            }
        }
        cout << "No Nodes Found to Delete" << endl;
    }

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
