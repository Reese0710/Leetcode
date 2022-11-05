#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> stk;
        for (auto c : expression) {
            if (c != ',' && c != ')') {
                stk.push(c);
            } else if (c == ')') {
                int t = 0;
                int f = 0;
                while (stk.top() != '(') {
                    char out = stk.top();
                    stk.pop();
                    if (out == 't') {
                        t++;
                    } else {
                        f++;
                    }
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                if (op == '&') {
                    char in = f > 0 ? 'f' : 't';
                    stk.push(in);
                } else if (op == '|') {
                    char in = t > 0 ? 't' : 'f';
                    stk.push(in);
                } else if (op == '!') {
                    char in = t > f ? 'f' : 't';
                    stk.push(in);
                }
            }
        }
        return (stk.top() == 't');
    }
};

int main() {

    Solution solution;

    string expression;

    cin >> expression;

    bool ans = solution.parseBoolExpr(expression);

    cout << ans << endl;

    return 0;
}