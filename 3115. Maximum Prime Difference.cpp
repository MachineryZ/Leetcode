class Solution {
public:
    set<int> prime;
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        for(left = 0; left < n; ++left) {
            if (isprime(nums[left])) {
                break;
            }
        }
        for (right = n-1; right >= 0; right--) {
            if (isprime(nums[right]))
                break;
        }
        return left < right ? right - left : 0;
    }
    bool isprime(int x) {
        if (x == 1)
            return false;
        if (prime.find(x) != prime.end())
            return true;
        for (int i = 2; i <= sqrt(x); ++i) {
            if (x % i == 0)
                return false;
        }
        prime.insert(x);
        return true;
    }
};