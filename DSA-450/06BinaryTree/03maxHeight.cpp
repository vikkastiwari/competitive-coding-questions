// question link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#

/*
Input:
  2
   \
    1
   /
 3
Output: 3
*/

int height(struct Node *node)
{
    //code here
    if (node == NULL)
        return 0;
    else
    {
        int ldepth = height(node->left);
        int rdepth = height(node->right);

        if (ldepth > rdepth)
        {
            return (ldepth + 1); // +1 for current root node
        }
        else
        {
            return (rdepth + 1); // +1 for current root node
        }
    }
}