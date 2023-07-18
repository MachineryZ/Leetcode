class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) 
    {
        int lower_x = 105;
        int upper_x = -105;
        int lower_y = 105;
        int upper_y = -105;
        for(int i = 0; i < circles.size(); i++)
        {
            lower_x = min(lower_x, circles[i][0] - circles[i][2]);
            upper_x = max(upper_x, circles[i][0] + circles[i][2]);
            lower_y = min(lower_y, circles[i][1] - circles[i][2]);
            upper_y = max(upper_y, circles[i][1] + circles[i][2]);
        }
        int ret = 0;
        for(int x = lower_x; x <= upper_x; x++)
        {
            for(int y = lower_y; y <= upper_y; y++)
            {
                for(int i = 0; i < circles.size(); i++)
                {
                    if(dist(x, y, circles[i][0], circles[i][1]) <= circles[i][2] * circles[i][2])
                    {
                        ret++;
                        break;                
                    }
                }
            }
        }
        return ret;
    }
    int dist(int x, int y, int xx, int yy)
    {
        return (x - xx) * (x - xx) + (y - yy) * (y - yy);
    }
    
};