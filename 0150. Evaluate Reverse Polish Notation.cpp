class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st_num;
        // stack<string> st_opt;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                int last = st_num.top();
                st_num.pop();
                int first = st_num.top();
                st_num.pop();
                st_num.push(last + first);
            }
            else if (tokens[i] == "-") {
                int last = st_num.top();
                st_num.pop();
                int first = st_num.top();
                st_num.pop();
                st_num.push(last - first);
            }
            else if (tokens[i] == "*") {
                int last = st_num.top();
                st_num.pop();
                int first = st_num.top();
                st_num.pop();
                st_num.push(last * first);
            }
            else if (tokens[i] == "/") {
                int last = st_num.top();
                st_num.pop();
                int first = st_num.top();
                st_num.pop();
                st_num.push(first / last);
            }
            else {
                int num = std::stoi(tokens[i]);
                st_num.push(num);
            }
        }
        return st_num.top();
    }
};