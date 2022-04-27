class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        if(n == 1)
            return s;
        string ret = "";
        vector<vector<bool>> dp(1005, vector<bool>(1005, false));
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            ret = s.substr(i, 1);
        }
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                ret = s.substr(i, 2);
            }
        }
        for(int len = 3; len <= n; len++)
        {
            for(int start = 0; start + len <= n; start++)
            {
                if(s[start] == s[start + len - 1] and dp[start + 1][start + len - 2] == true)
                {
                    dp[start][start + len - 1] = true;
                    if(len > ret.size())
                        ret = s.substr(start, len);
                }
            }
        }
        return ret;
    }
};