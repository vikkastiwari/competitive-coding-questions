#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int solve(node *root, int &res)
{
    if (root == nullptr)
        return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp;
    if (root->left && root->right)
    {
        res = max(res, l + r + root->data);
        temp = root->data + max(l, r);
    }
    else if (root->left)
        temp = root->data + l;
    else if (root->right)
        temp = root->data + r;
    else
        temp = root->data;

    return temp;
}

int main()
{
    /*
            10
          /    \
        2       10
       / \       \
     20   1      -25
                 /  \
                3    4
    */
    struct node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    int res = INT_MIN;
    solve(root, res);
    // 42
    cout << res << endl;
    return 0;
}