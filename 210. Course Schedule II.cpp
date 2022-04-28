class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> ret;
        queue<int> q;
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> out_degree(numCourses, vector<int>(0));
        for(int j = 0; j < prerequisites.size(); j++)
        {
            int pre = prerequisites[j][1];
            int next = prerequisites[j][0];
            in_degree[next] += 1;
            out_degree[pre].push_back(next);
        }
        for(int i = 0; i < in_degree.size(); i++)
            if(in_degree[i] == 0)
                q.push(i);
        while(!q.empty())
        {
            int cur = q.front();
            ret.push_back(cur);
            q.pop();
            for(int i = 0; i < out_degree[cur].size(); i++)
            {
                int next = out_degree[cur][i];
                in_degree[next]--;
                if(in_degree[next] == 0)
                    q.push(next);
            }
        }
        return ret.size() == numCourses ? ret : vector<int>{};
    }
};