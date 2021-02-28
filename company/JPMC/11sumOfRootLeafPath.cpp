#include <bits/stdc++.h>
#define ll long long
using namespace std;

class node  
{  
    public: 
    int data;  
    node *left, *right;  
}; 

// function to allocate new node with given data  
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = Node->right = NULL;  
    return (Node);  
}  
  

int treePathsSumUtil(node *root, int val){
    if(root==NULL) return 0;

    // udate val
    val = val*10 + root->data;

    // when current node is leaf 
    if(root->left == NULL && root->right == NULL){
        return val;
    }

    // recur sum of values for left and right subtree  
    return(treePathsSumUtil(root->left,val)+treePathsSumUtil(root->right,val));
}

int treePathsSum(node *root)
{
    return treePathsSumUtil(root, 0);
}


int main()  
{  
    node *root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4);  
    cout<<"Sum of all paths is "<<treePathsSum(root);  
    return 0;  
} 