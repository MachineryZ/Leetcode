// AC
class Solution {
    struct TrieNode {
        TrieNode *children[26];
        string word;

        TrieNode() : word("") {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++) {
            string word = words[j];
            TrieNode *curr = root;
            for (int i = 0; i < word.length(); i++) {
                char c = word[i] - 'a';
                if (curr->children[c] == nullptr) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a']) return;
        p = p->children[c - 'a'];
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
};

// TLE
class Trie
{
public:
    bool isEnd;
    char val;
    unordered_map<char, Trie*> next;
    Trie(char s)
    {
        val = s;
        isEnd = false;
    }
};

class Solution {
public:
    set<string> ret;
    Trie* root;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        ret.clear();
        root = new Trie(' ');
        for(int i = 0; i < words.size(); i++)
            insert(words[i]);
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dfs(board, i, j, "");
        vector<string> res;
        for(auto it = ret.begin(); it != ret.end(); it++)
            res.push_back(*it);
        return res;
    }
    void insert(string word)
    {
        Trie* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(node->next.find(word[i]) == node->next.end())
                node->next[word[i]] = new Trie(word[i]);
            node = node->next[word[i]];
        }
        node->isEnd = true;
        return;
    }
    bool search(string word)
    {
        Trie* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(node->next.find(word[i]) == node->next.end())
                return false;
            node = node->next[word[i]];
        }
        if(node->isEnd == true)
            ret.insert(word);
        return true;
    }
    void dfs(vector<vector<char>>& board, int x, int y, string word)
    {
        int n = board.size();
        int m = board[0].size();
        if(board[x][y] == '.')
            return;
        if(search(word + board[x][y]) == false)
            return;
        char val = board[x][y];
        board[x][y] = '.';
        if(x+1 < n)
            dfs(board, x+1, y, word+val);
        if(y+1 < m)
            dfs(board, x, y+1, word+val);
        if(x > 0)
            dfs(board, x-1, y, word+val);
        if(y > 0)
            dfs(board, x, y-1, word+val);
        board[x][y] = val;
        return;
    }
};