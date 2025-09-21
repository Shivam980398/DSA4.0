
// my approach
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    vector<int> val;
    bool leftToRight = true;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            // cout<<endl;
            ans.push_back(val);
            val.clear();
            leftToRight = !leftToRight;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            val.push_back(temp->val);
            if (leftToRight)
            {
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else
            {
                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
    }

    return ans;
}

// corrected Approach
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    vector<int> val;
    bool leftToRight = true;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            // cout<<endl;
            if (!leftToRight)
                reverse(val.begin(), val.end());
            ans.push_back(val);
            val.clear();
            leftToRight = !leftToRight;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            val.push_back(temp->val);

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return ans;
}