class TrieNode {
public:
    bool isend;
    vector<TrieNode*> next;

    TrieNode() {
        isend = false;
        next.resize(26, NULL);
    }
};

bool isprefix(TrieNode* p, string prefix) {
    for (auto s : prefix) {
        if (p->next[s - 'a'] == NULL)
            return false;
        p = p->next[s - 'a'];
    }
    return true;
}

void check(TrieNode* p, string str, vector<string>& ret) {
    if (ret.size() == 3)
        return;
    if (p == NULL)
        return;
    if (p->isend == true) {
        ret.push_back(str);
    }
    for (char s = 'a'; s <= 'z'; s++) {
        if (p->next[s - 'a'] != NULL) {
            check(p->next[s - 'a'], str + s, ret);
        }
    }
    return;
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        TrieNode* root = new TrieNode;
        // build trie tree
        for (auto product : products) {
            TrieNode* p = root;
            for (auto s : product) {
                if (p->next[s - 'a'] == NULL) {
                    p->next[s - 'a'] = new TrieNode;
                    p = p->next[s - 'a'];
                }
                else 
                    p = p->next[s - 'a'];
            }
            p->isend = true;
        }

        // check every prefix in searchWord
        for (int i = 1; i <= searchWord.size(); i++) {
            string tmp_str = searchWord.substr(0, i);
            vector<string> tmp_ret;
            // check if it is a prefix
            if (isprefix(root, tmp_str) == false) {
                ret.push_back(tmp_ret);
                continue;
            }
            TrieNode* p = root;
            for (auto s : tmp_str)
                p = p->next[s - 'a'];
            check(p, tmp_str, tmp_ret);
            ret.push_back(tmp_ret);
        }
        return ret;
    }
};