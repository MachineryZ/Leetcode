class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur = {};
        backtrack(cur, nums, 0);
        return res;
    }
    void backtrack(vector<int> cur, vector<int>& nums, int idx) {
        if (cur.size() >= 2) {
            if (s.find(cur) == s.end())
                res.push_back(cur);
            s.insert(cur);
        }
        if (idx >= nums.size())
            return;
        if (cur.size() == 0) {
            cur.push_back(nums[idx]);
            backtrack(cur, nums, idx + 1);
            cur.pop_back();
        }
        else if (cur.size() > 0 and cur.back() <= nums[idx]) {
            cur.push_back(nums[idx]);
            backtrack(cur, nums, idx + 1);
            cur.pop_back();
        }
        backtrack(cur, nums, idx + 1);
        return;
    }
};