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

void Inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }
}

void itrInorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    // inorder -> left, root, right
    stack<Node *> s;
    struct Node *temp = node;
    while (temp != NULL || s.empty() == false)
    {
        // it will iterate through all the left nodes and store it in stack
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        // from bottom of the tree we will start printing left, root and right

        // left and root node taken care
        temp = s.top();
        cout << temp->data << " ";
        s.pop();

        // for right
        temp = temp->right;
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

    cout << "Inorder recursive:" << endl;
    Inorder(root);

    cout << endl;

    cout << "Inorder iterative:" << endl;
    itrInorder(root);

    return 0;
}