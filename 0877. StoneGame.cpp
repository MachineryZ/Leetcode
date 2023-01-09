class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        vector<int> sum(n + 1, 0);
        sum[0] = piles[0];
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + piles[i];
        }
        for(int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        for(int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = max(piles[i], piles[i+1]);
        }
        for(int j = 2; j < n; j++) {
            for(int i = 0; i < n - j; i++) {
                dp[i][i + j] = max(
                    piles[i] + sum[i+j] - sum[i] - dp[i+1][i+j],
                    piles[i + j] + sum[i+j] - sum[i] - dp[i][i+j-1]
                );
            }
        }
        if(dp[0][n-1] * 2 >= sum[n])
            return true;
        else
            return false;
    }
};