class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<bool> mem(10005, false);
        vector<int> in_degree(10005, 0);
        vector<vector<int>> out_degree(10005);
        int pre_size = prerequisites.size();
        for(int i = 0; i < pre_size; i++)
        {
            in_degree[prerequisites[i][0]] += 1;
            out_degree[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(in_degree[i] == 0)
            {
                q.push(i);
                mem[i] = true;
                cout << i << endl;
            }
        }
        while(q.size() > 0)
        {
            int index = q.front();
            for(int i = 0; i < out_degree[index].size(); i++)
            {
                int next = out_degree[index][i];
                in_degree[next]--;
                if(in_degree[next] == 0)
                {
                    q.push(next);
                    mem[next] = true;
                    cout << next << endl;
                }
            }
            q.pop();
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(mem[i] == false)
                return false;
        }
        return true;
    }
};