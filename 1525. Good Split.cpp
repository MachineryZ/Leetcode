class Solution {
public:
    int numSplits(string s) {
        vector<int> s_left(26, 0);
        vector<int> s_right(26, 0);
        int ret = 0;
        for(int i = 0; i < s.size(); i++) {
            s_right[s[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            s_left[s[i] - 'a']++;
            s_right[s[i] - 'a']--;
            int sum_left = 0;
            int sum_right = 0;
            for(int j = 0; j < 26; j++) {
                if(s_left[j] > 0)
                    sum_left++;
                if(s_right[j] > 0)
                    sum_right++;
            }
            if(sum_left == sum_right)
                ret++;
        }
        return ret;
    }
};