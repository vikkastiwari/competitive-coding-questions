// question link: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#

#include <bits/stdc++.h>
using namespace std;
#define bool int

class node
{
public:
    int data;
    node *left;
    node *right;
};

// we are only checking for root node
bool isBalanced(node *root)
{
    if (root == NULL)
        return 1;
    int lh = isBalanced(root->left);
    if (lh == -1)
    {
        return 0;
    }
    int rh = isBalanced(root->right);
    if (rh == -1)
    {
        return 0;
    }

    if (abs(lh - rh) > 1)
        return 0;

    return 1;
}

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int main()
{
    int height = 0;

    /* 
			1
			/ \
			2 3
			/ \ /
			4 5 6
			/
			7
	*/
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(7);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";

    return 0;
}
