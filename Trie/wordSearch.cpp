#include <bits/stdc++.h>
using namespace std;

struct trieNode
{
    string word;
    bool endOfWord;
    trieNode *children[26];
};

trieNode *getNode()
{
    trieNode *newNode = new trieNode();

    newNode->endOfWord = false;
    newNode->word = "";

    for (int i = 0; i < 26; i++)
    {
        newNode->children[i] = NULL;
    }

    return newNode;
}

void insert(trieNode *root, string word)
{
    trieNode *crawler = root;

    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];

        if (crawler->children[ch - 'a'] == NULL)
        {
            crawler->children[ch - 'a'] = getNode();
        }

        crawler = crawler->children[ch - 'a'];
    }

    crawler->endOfWord = true;
    crawler->word = word;
}

void findTrieWords(vector<vector<char>> &board, int i, int j, trieNode *root, vector<string> &result, vector<vector<int>> &directions)
{
    int m = board.size();
    int n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n)
        return;

    if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL)
        return;
    char ch = board[i][j];

    trieNode *crawler = root->children[ch - 'a'];
    if (crawler->endOfWord)
    {
        result.push_back(crawler->word);
        crawler->endOfWord = false;
    }
    board[i][j] = '$';

    for (auto dir : directions)
    {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        findTrieWords(board, new_i, new_j, crawler, result, directions);
    }
    board[i][j] = ch;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words, vector<vector<int>> &directions)
{
    trieNode *root = getNode();

    for (auto word : words)
    {
        insert(root, word);
    }
    vector<string> result;

    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch = board[i][j];

            if (root->children[ch - 'a'] != NULL)
            {
                findTrieWords(board, i, j, root, result, directions);
            }
        }
    }
    return result;
}

int main()
{

    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (auto word : findWords(board, words, directions))
        cout << word << " ";
}