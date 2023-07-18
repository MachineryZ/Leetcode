class Solution 
{
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        int n_size = nums.size();
        vector<int> cnt(1005, 0);
        for(int i = 0; i < n_size; i++)
            for(int j = 0; j < nums[i].size(); j++)
                cnt[nums[i][j]]++;
        vector<int> ret;
        for(int i = 1; i <= 1000; i++)
            if(cnt[i] == n_size)
                ret.push_back(i);
        sort(ret.begin(), ret.end());
        return ret;
    }
};