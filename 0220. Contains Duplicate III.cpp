class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        std::map<long long, int> m; // nums[i] -> i
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i - j > indexDiff)
                m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - valueDiff);
            if (a != m.end() && abs(a->first - nums[i]) <= valueDiff)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

/*
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int size = nums.size();
        int left = 0;
        int right = 0;
        while (left <= size - 1) {
            right = left + 1;
            while (right - left <= indexDiff and right <= size - 1) {
                if (std::abs(nums[right] - nums[left]) <= valueDiff)
                    return true;
                right++;
            }
            left++;
        }
        return false;
    }
};
*/