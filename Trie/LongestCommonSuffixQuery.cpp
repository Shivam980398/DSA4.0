#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    int idx;

    TrieNode *children[26];
};

TrieNode *
getNode(int i)
{

    TrieNode *newNode = new TrieNode();
    newNode->idx = i;

    for (int i = 0; i < 26; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(TrieNode *root, int i, vector<string> &WordContainer)
{
    string word = WordContainer[i];
    int n = word.length();

    for (int j = n - 1; j >= 0; j--)
    {
        char ch = word[j];
        int ch_idx = ch - 'a';

        if (root->children[ch_idx] == NULL)
        {
            root->children[ch_idx] = getNode(i);
        }
        root = root->children[ch_idx];

        if (WordContainer[root->idx].length() > n)
        {
            root->idx = i;
        }
    }
}

int searchTrie(TrieNode *root, string &word)
{
    int n = word.length();
    int result_idx = root->idx;
    for (int j = n - 1; j >= 0; j--)
    {
        char ch = word[j];
        char ch_idx = ch - 'a';

        root = root->children[ch_idx];
        if (root == NULL)
            return result_idx;

        result_idx = root->idx;
    }
    return result_idx;
}

int main()
{

    // jaha search krna hai humko usko trie mai dalenge

    vector<string> WordContainer = {"abcdefgh", "poiuygh", "ghghgh"};
    vector<string> WordQuery = {"gh", "acbfgh", "acbfegh"};

    int m = WordContainer.size();
    int n = WordQuery.size();
    vector<int> result(n);

    TrieNode *root = getNode(0);

    for (int i = 0; i < m; i++)
    {

        int rootIdx = root->idx;
        if (WordContainer[rootIdx].length() > WordContainer[i].length())
        {
            root->idx = i;
        }
        insert(root, i, WordContainer);
    }
    for (int i = 0; i < n; i++)
    {

        result[i] = searchTrie(root, WordQuery[i]);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
}