#include<string>
#include<unordered_set>
#include<iostream>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0;
        for (int i = 0; i < n / 2; ++i) {
            cnt += st.count(s[i]);
            cnt -= st.count(s[n / 2 + i]);
        }
        return (cnt == 0);
    }
};

int main() {

    Solution solution;

    string s;
    cin >> s;

    bool ans = solution.halvesAreAlike(s);
    cout << ((ans == true) ? "true" : "false") << endl;

    return 0;
}