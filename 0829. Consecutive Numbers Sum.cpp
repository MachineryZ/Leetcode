class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ret = 1;
        long long half = std::sqrt(n);
        for (long long t = 2; t <= 2 * sqrt(n); ++t) {
            if (n % t == ((t - 1) * t / 2) % t and (t + 1) * t / 2 <= n)
                ret++;
        }
        return ret;
    }
};