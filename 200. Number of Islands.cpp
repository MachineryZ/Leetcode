class Solution {
public:
    int n;
    int m;
    int numIslands(vector<vector<char>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        int ret = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    ret += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        if(x < 0 or x >= n or y < 0 or y >= m or grid[x][y] != '1')
            return;
        grid[x][y] = '0';
        dfs(grid, x+1, y);
        dfs(grid, x, y+1);
        dfs(grid, x-1, y);
        dfs(grid, x, y-1);
        return;
    }
};