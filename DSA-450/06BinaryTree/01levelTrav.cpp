// question link: https://practice.geeksforgeeks.org/problems/level-order-traversal/1#

// Input:
//         10
//      /      \
//     20       30
//   /   \
//  40   60
// Output:10 20 30 40 60 N N

class Solution
{
public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *root)
    {
        //Your code here
        vector<int> levelOrder;
        if (root == NULL)
            return levelOrder;
        queue<Node *> q;
        q.push(root);
        while (q.empty() == false)
        {
            Node *node = q.front();
            levelOrder.push_back(node->data);
            q.pop();

            if (node->left != NULL)
            {
                q.push(node->left);
            }

            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        return levelOrder;
    }
};
