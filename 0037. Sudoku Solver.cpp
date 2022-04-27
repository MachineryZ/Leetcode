class Solution 
{
    bool solved;
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solved = false;
        dfs(board, 0, 0);
        return;
    }
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if(solved == true)
            return;
        else if(x == 8 and y == 9)
        {
            solved = true;
            return;
        }
        else if(y == 9)
            dfs(board, x+1, 0);
        else if(board[x][y] != '.')
            dfs(board, x, y+1);
        else
        {
            for(char s = '1'; s <= '9'; s++)
            {
                if(check(board, x, y, s) == true)
                {
                    board[x][y] = s;
                    dfs(board, x, y+1);
                    if(solved == true)
                        return;
                    board[x][y] = '.';
                }
            }
        }
        return;
    }
    bool check(vector<vector<char>>& board, int x, int y, char s)
    {
        for(int i = 0; i < 9; i++)
            if(board[x][i] == s)
                return false;
        for(int i = 0; i < 9; i++)
            if(board[i][y] == s)
                return false;
        int xx = x / 3;
        int yy = y / 3;
        for(int i = 0; i < 9; i++)
        {
            if(board[3*xx + i/3][3*yy + i%3] == s)
                return false;
        }
        return true;
    }
};