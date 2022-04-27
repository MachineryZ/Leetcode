class Solution {
public:
    bool flag;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        flag = false;
        queue<string> q;
        unordered_set<string> visited;
        unordered_set<string> wordset;
        for(string str : wordList)
            wordset.insert(str);
        if(wordset.count(endWord) == 0)
            return 0;
        int num_trans = 1;
        int word_size = beginWord.size();
        q.push(beginWord);
        visited.insert(beginWord);
        while(!q.empty())
        {
            int q_size = q.size();
            for(int i = q_size - 1; i >= 0; i--)
            {
                string new_word = q.front();
                q.pop();
                if(new_word == endWord)
                    return num_trans;
                for(int j = 0; j < word_size; j++)
                {
                    for(char s = 'a'; s <= 'z'; s++)
                    {
                        if(new_word[j] == s)
                            continue;
                        string t = new_word;
                        t[j] = s;
                        if(visited.count(t) == 0 and wordset.count(t) > 0)
                        {
                            q.push(t);
                            visited.insert(t);
                        }
                    }
                }
            }
            num_trans++;
        }
        return 0;
    }
};