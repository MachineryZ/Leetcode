class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        string res;
        int group_size = 2 * numRows - 2;
        int s_size = s.size();
        if(numRows <= 1)
            return s;
        for(int start = 0; start < numRows; start++)
        {
            for(int idx = start; idx < s_size; idx += group_size)
            {
                res += s[idx];
                int pos = idx + group_size - 2 * start;
                if(start != 0 and start != numRows - 1 and pos < s_size)
                    res += s[pos];
            }
        }
        return res;
    }
};