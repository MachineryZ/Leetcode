class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        int c = 0;
        int r = 0;
        int o = 0;
        int a = 0;
        int k = 0;
        int ret = 0;
        for(int i = 0; i < croakOfFrogs.size(); i++)
        {
            if(croakOfFrogs[i] == 'c')
            {
                c += 1;
                ret = max(ret, c);
            }
            else if(croakOfFrogs[i] == 'r')
            {
                if(c <= r)
                    return -1;
                r += 1;
            }
            else if(croakOfFrogs[i] == 'o')
            {
                if(r <= o)
                    return -1;
                o += 1;
            }
            else if(croakOfFrogs[i] == 'a')
            {
                if(o <= a)
                    return -1;
                a += 1;
            }
            else if(croakOfFrogs[i] == 'k')
            {
                if(a <= k)
                    return -1;
                c--;
                r--;
                o--;
                a--;
            }
        }
        if(not(c == r and r == o and o == a and a == k))
            return -1;
            
        return ret;
    }
};