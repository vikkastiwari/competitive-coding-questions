// question link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// Structure of binary tree
struct Node
{
    Node *left;
    Node *right;
    int hd;
    int data;
};

// function to create a new node
Node *newNode(int key)
{
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    node->hd = INT_MAX;
    return node;
}

void topview(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    map<int, int> map;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        hd = temp->hd;

        map[hd] = temp->data;
        if (temp->left != NULL)
        {
            // we are updating hd for left of root with hd - 1
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            // we are updating hd for left of root with hd + 1
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }
    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << i->second << " ";
    }
}

int main()
{
    Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    topview(root);
    return 0;
}
