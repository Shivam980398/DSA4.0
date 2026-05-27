struct trieNode
{
    bool endOfWord;
    trieNode *children[26];

    string word;
};

trieNode *getNode()
{
    trieNode *newNode = new trieNode;
    newNode->endOfWord = false;

    for (int i = 0; i < 26; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(trieNode *root.string word)
{
    trieNode *crawler = root;
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        if (crawler->children[ch - 'a'] == NULL)
            crawler->children[ch - 'a'] = getNode();

        crawler = crawler->children[ch - 'a'];
    }
    crawler->endOfWord = true;
    crawler->word = word;
}
bool serach(trieNode *root, string word)
{
    trieNode *crawler = root;

    for (auto ch : word)
    {
        int idx = ch - 'a';

        if (crawler->children[idx] == NULL)
            return false;

        crawler = crawler->children[idx];
    }

    return crawler->endOfWord == true;
}

bool startWith(trieNode *root, string prefix)
{
    trieNode *crawler = trieNode;
    int i = 0;

    for (; i < prefix.size(); i++)
    {
        char ch = prefix[i];

        int idx = ch - 'a';

        if (crawler->children[idx] == NULL)
            return false;
        crawler = crawler->children[idx];
    }

    if (i == prefix.size())
        return true;

    return false;
}
