// question link:https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

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
    while (q.size())
    {
        hd = root->hd;
        // if map already holds hd position then till never update that position again
        if (map.count(hd) == 0)
        {
            map[hd] = root->data;
        }
        if (root->left != NULL)
        {
            // we are updating hd for left of root with hd - 1
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right != NULL)
        {
            // we are updating hd for left of root with hd + 1
            root->right->hd = hd + 1;
            q.push(root->right);
        }
    }
    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << i->second << " ";
    }
}

int main()
{

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topview(root);
    return 0;
}
