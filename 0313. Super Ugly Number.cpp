// TLE:
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        std::set<long long> s;
        long long cur = 1;
        int cnt = 1;
        s.insert(cur);
        long long c_max = pow(primes[0], n);
        auto it = s.begin();
        while(cnt < n) {
            for (int i = 0; i < primes.size(); i++)
                if (c_max > cur * primes[0])
                    break;
                else
                    s.insert((cur) * primes[i]);
            it++;
            cur = *it;
            cnt++;
        }
        return *it;
    }
};

// AC: DP  setting pointers.
// Very clever methods, set lens pointers to 1, and move pointers forward.
// When meet the same min_num, move all pointers forward.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n+2, 0);
        int lens = primes.size();
        vector<int> pointers(lens+1, 1);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            long long min_num = INT_MAX;
            int cur = -1;
            for (int j = 0; j < lens; ++j) {
                long long tmp = dp[pointers[j]] * primes[j];
                if (min_num > tmp) {
                    min_num = tmp;
                }
            }
            for (int j = 0; j < lens; ++j) {
                if (dp[pointers[j]] * primes[j] == min_num) {
                    pointers[j]++;
                }
            }
            dp[i] = min_num;
        }
        return dp[n];
    }
};
