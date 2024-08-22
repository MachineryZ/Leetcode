class Solution {
    std::map<int, double> m;
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0.0; 
        if (m.find(n) != m.end()) {
            return m[n];
        }
        else if (x == 0 || n == 0) {
            return m[n] = 1.0;
        }
        else if (n > 0) {
            if (n % 2 == 0) {
                return m[n] = myPow(x, n/2) * myPow(x, n/2);
            }
            else if (n % 2 == 1) {
                return m[n] = x * myPow(x, n - 1);
            }
        }
        else if (n < 0) {
            if (n % 2 == 0) {
                return m[n] = myPow(x, n/2) * myPow(x, n/2);
            }
            else if (n % 2 == -1) {
                return m[n] = myPow(x, n + 1) / x;
            }
        }
        return 1.0;
    }
};