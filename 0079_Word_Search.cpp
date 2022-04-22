class Solution 
{
    bool solved;
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        solved = false;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dfs(board, i, j, word, 0) == true)
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int x, int y, string word, int len)
    {
        if(solved == true)
            return true;
        if(len == word.size())
        {
            solved = true;
            return true;
        }
        int n = board.size();
        int m = board[0].size();
        if(x < 0 or x >= n or y < 0 or y >= m or board[x][y] != word[len])
            return false;
        if(board[x][y] == word[len])
        {
            board[x][y] = '.';
            bool res = dfs(board, x+1, y, word, len+1)
                || dfs(board, x, y+1, word, len+1)
                || dfs(board, x-1, y, word, len+1)
                || dfs(board, x, y-1, word, len+1);
            if(solved == true)
                return true;
            board[x][y] = word[len];
        }
        return false;
    }
};