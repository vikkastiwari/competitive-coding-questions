// question link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// C++ implementation of a O(n) time method for
// Zigzag order traversal
#include <iostream>
#include <stack>
using namespace std;

// Binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void zizagtraversal(struct Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> curr;
    stack<Node *> next;

    // to keep track of direction
    bool leftToRight = true;
    curr.push(root);
    while (!curr.empty())
    {
        Node *temp = curr.top();
        curr.pop();

        if (temp) // check whether temp is empty or not
        {
            // printing output
            cout << temp->data << " ";

            // leftToRight = true
            // from stack we will print right to left
            if (leftToRight)
            {
                if (temp->left != NULL)
                {
                    next.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    next.push(temp->right);
                }
            }
            else // leftToRight = false
            // from stack we will print left to right
            {
                if (temp->right != NULL)
                {
                    next.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    next.push(temp->left);
                }
            }
        }
        if (curr.empty())
        {
            leftToRight = !leftToRight;
            swap(curr, next);
        }
    }
}

int main()
{
    // create tree
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);

    zizagtraversal(root);

    return 0;
}
