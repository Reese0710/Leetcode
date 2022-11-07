#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> ans;
        for (int k = 1; k <= n - 3; ++k) {
            string l = s.substr(1, k);
            string r = s.substr(k + 1, n - 2 - k);
            vector<string> left = f(l);
            vector<string> right = f(r);
            for (auto &x : left) {
                for (auto &y : right) {
                    ans.emplace_back("(" + x + ", " + y + ")");
                }
            }
        }
        return ans;
    }

private:
    vector<string> f(string &s) {
        int n = s.size();
        if (n == 1) {
            return {s};
        }
        if (s[0] == '0' && s[n - 1] == '0') {
            return {};
        }
        if (s[n - 1] == '0') {
            return {s};
        }
        if (s[0] == '0') {
            return {"0." + s.substr(1)};
        }
        vector<string> ans;
        ans.emplace_back(s);
        for (int i = 1; i <= n - 1; ++i) {
            string a = s.substr(0, i);
            string b = s.substr(i);
            ans.emplace_back(a + "." + b);
        }
        return ans;
    }
};

int main() {

    Solution solution;

    string s;

    cin >> s;

    vector<string> ans = solution.ambiguousCoordinates(s);

    for (auto a : ans) {
        cout << a << endl;
    }

    return 0;
}