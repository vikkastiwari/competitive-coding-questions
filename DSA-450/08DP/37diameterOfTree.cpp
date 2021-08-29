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

    int temp = max(l, r) + 1;
    int ans = max(temp, l + r + 1);
    res = max(res, ans);
    return temp;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int res = INT_MIN;
    solve(root, res);
    cout << res << endl;
    return 0;
}