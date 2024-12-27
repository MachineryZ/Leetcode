class Solution {
public:
    int trailingZeroes(int n) {
        int five = 0;
        int x = n;
        while (x > 1) {
            if (x >= 5) {
                five += x / 5;
                x = x / 5;
            }
            else
                break;
        }
        return five;
    }
};