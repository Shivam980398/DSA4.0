#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BuildTree(Node *root)
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data inserting in left" << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data inserting in right" << data << endl;
    root->right = BuildTree(root->right);
    return root;
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// for returning vector<int> instead of printing
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    vector<int> val;
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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 7 -1 -1 -1
    // 1 3 5 7 -1 8 -1 -1 6 -1 -1 4 -1 -1 2 9 -1 0 -1 -1 10 -1 -1
    Node *root = NULL;
    root = BuildTree(root);

    levelOrderTraversal(root);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}