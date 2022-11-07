#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                ans += 'G';
            } else if (command[i] == '(' && command[i + 1] == ')') {
                ans += 'o';
            i += 1;
            } else {
                ans += "al";
                i += 3;
            }
        }
        return ans;
    }
};

int main() {

    Solution solution;

    string command;

    cin >> command;

    string ans = solution.interpret(command);

    cout << ans << endl;

    return 0;
}