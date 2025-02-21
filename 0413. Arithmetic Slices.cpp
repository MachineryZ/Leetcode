class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n <= 2) 
            return 0;
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            else 
                dp[i] = 2;
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] >= 3){
                ret += dp[i] - 2;
            }
        }
        return ret;
    }
};