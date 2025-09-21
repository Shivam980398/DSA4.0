int minDepth(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    return 1 + min(lh, rh);
}