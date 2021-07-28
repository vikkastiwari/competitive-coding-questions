vector<int> leftView(Node *node)
{
    // Your code here
    vector<int> left;

    if (!node)
        return left;

    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 1)
            {
                left.push_back(temp->data);
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    return left;
}