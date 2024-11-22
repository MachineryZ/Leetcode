class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> index;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                index.push_back(i);
            }
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (queries[i] > index.size())
                ret.push_back(-1);
            else
                ret.push_back(index[queries[i] - 1]);
        } 
        return ret;
    }
};