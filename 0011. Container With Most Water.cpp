// TLE Anwser
class Solution
{
public:
    int maxArea(vector<int>& height) 
    {
        int h_size = height.size();
        int ret = 0;
        for(int i1 = 0; i1 < h_size; i1++)
        {
            for(int i2 = i1+1; i2 < h_size; i2++)
            {
                ret = max(ret, (i2 - i1) * min(height[i2], height[i1]));
            }
        }
        return ret;
    }
};

// Greedy
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0, right = height.size() - 1, ret = 0;
        while(left < right)
        {
            ret = max(ret, min(height[left], height[right]) * (right - left));
            height[left] > height[right] ? right-- : left++;
        }
        return ret;
    }
};