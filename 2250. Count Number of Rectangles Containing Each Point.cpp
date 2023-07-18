class Solution 
{
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points)
    {
        int n_size = rectangles.size();
        vector<vector<int>> hi(105);
        vector<int> ret;
        for(int i = 0; i < n_size; i++)
            hi[rectangles[i][1]].push_back(rectangles[i][0]);
        for(int i = 1; i <= 100; i++)
            sort(hi[i].begin(), hi[i].end());
        for(auto& p : points)
        {
            int sum = 0;
            for(int h = p[1]; h <= 100; h++)
            {
                auto lower_h = lower_bound(hi[h].begin(), hi[h].end(), p[0]);
                sum += hi[h].end() - lower_h; 
            }
            ret.push_back(sum);
        }
        return ret;
    }
};