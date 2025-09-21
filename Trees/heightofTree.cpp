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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}
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

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 7 -1 -1 -1
    // 1 3 5 7 -1 8 -1 -1 6 -1 -1 4 -1 -1 2 9 -1 0 -1 -1 10 -1 -1
    Node *root = NULL;
    root = BuildTree(root);

    levelOrderTraversal(root);

    cout << "Height of tree is " << height(root) << endl;
}