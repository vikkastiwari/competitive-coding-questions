// question link: https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void postorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder recursive:" << endl;
    postorder(root);

    return 0;
}