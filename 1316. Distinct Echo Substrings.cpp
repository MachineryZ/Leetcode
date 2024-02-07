// TLE:
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> s;
        int n = text.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; i + 2 * j - 1 < n; j += 1) {
                string substr = text.substr(i, j);
                if (s.find(substr) == s.end() and text.substr(i, j) == text.substr(i+j, j)) {
                    s.insert(substr); 
                }
            }
        }
        return s.size();
    }
};

// DP accepted
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        if (text.size() <= 1)
            return 0;
        int N = text.size();

        vector<vector<int>> dp (N + 1, vector<int> (N + 1, 0));
        unordered_set<string> res;
        auto &ch = text;
        for (int j = N - 1; j > 0; j--) {
            for (int i = j - 1; i >= 0; i--) {
                dp[i][j] = ch[i] == ch[j] ? 1 + dp[i + 1][j + 1] : 0;
                if (dp[i][j] >= j - i)
                    res.insert(ch.substr(i, j-i));
            }
        }
        return res.size();
    }
};
/*
dp[i][j] = k stands for two sub strings 
that start from text[i] and text[j] respectively, 
are same to at most k characters
*/

