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

void preorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// void itrPreorder(struct Node *node)
// {
//     if (node == NULL)
//     {
//         return;
//     }

//     stack<Node *> s;
//     s.push(node);
//     while (s.empty() == false)
//     {
//         struct Node *temp = s.top();
//         s.pop();
//         cout << temp->data << " ";

//         if (node->right)
//         {
//             s.push(node->right);
//         }

//         if (node->left)
//         {
//             s.push(node->left);
//         }
//     }
// }

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
    preorder(root);

    cout << endl;

    // cout << "Preorder iterative:" << endl;
    // itrPreorder(root);

    return 0;
}