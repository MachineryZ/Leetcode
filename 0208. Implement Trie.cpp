class TrieNode
{
public:
    bool isword;
    vector<TrieNode*> next;
    TrieNode()
    {
        isword = false;
        next.resize(26, NULL);
    }
};

class Trie 
{
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();   
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode* p = root;
        for(auto s : word)
        {
            if(p->next[s - 'a'] == NULL)
                p->next[s - 'a'] = new TrieNode;
            p = p->next[s - 'a'];
        }
        p->isword = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* p = root;
        for(auto s : word)
        {
            if(p->next[s - 'a'] == NULL)
                return false;
            p = p->next[s - 'a'];
        }
        return p->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        TrieNode* p = root;
        for(auto s : prefix)
        {
            if(p->next[s - 'a'] == NULL)
                return false;
            p = p->next[s - 'a'];
        }
        return true;
    }
};