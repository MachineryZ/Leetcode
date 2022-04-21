class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0, right = 1;
        if(s.size() == 0)
            return 0;
        int ret = 1;
        unordered_map<char, int> m;
        m[s[left]]++;
        while(right < s.size())
        {
            if(m[s[right]] == 0)
            {
                m[s[right++]]++;
                ret = max(ret, right - left);
            }
            else if(m[s[right]] > 0)
            {
                while(left < right && m[s[right]] > 0)
                    m[s[left++]]--;
            }
        }
        return ret;
    }
};