// question link: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

/*
Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10
*/

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> rev;
    if (root == NULL)
        return rev;

    queue<Node *> q;
    stack<Node *> s;

    q.push(root);

    while (q.empty() == false)
    {
        root = q.front();
        q.pop();
        s.push(root);

        // here we will visit right node first wrt to screen
        if (root->right != NULL)
        {
            q.push(root->right);
        }

        if (root->left != NULL)
        {
            q.push(root->left);
        }
    }

    while (s.empty() == false)
    {
        Node *el = s.top();
        rev.push_back(el->data);
        s.pop();
    }

    return rev;
}