#include <iostream>
#include <vector>

class TrieNode {
public:
    bool isEnd;
    std::vector<TrieNode*> next;

    TrieNode() {
        isEnd = false;
        next.resize(26, NULL);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* p = root;
        for (auto s : word) {
            if (p->next[s - 'a'] == NULL)
                p->next[s - 'a'] = new TrieNode;
            p = p->next[s - 'a'];
        }
        p->isword = true;
        return;
    }

    bool isprefix(string prefix) {
        TrieNode* p = root;
        for (auto s : prefix) {
            if (p->next[s - 'a'] == NULL)
                return false;
            p = p->next[s - 'a'];
        }
        return true;
    }
};