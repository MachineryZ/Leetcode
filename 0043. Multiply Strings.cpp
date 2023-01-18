class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> ret(n1 + n2 + 1, 0);
        for(int i = n1 - 1; i >= 0; i--) {
            for(int j = n2 - 1; j >= 0; j--) {
                ret[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for(int i = n1 + n2 + 1; i > 0; i--) {
            if(ret[i] >= 10) {
                ret[i-1] += ret[i] / 10;
                ret[i] %= 10;
            }
        }
        string res = "";
        for(int i = 0; i < n1 + n2 + 1; i++) {
            res += '0' + 
        }
    }
};