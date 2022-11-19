#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allow(26, false);
        for (char &c : allowed) {
            allow[c - 'a'] = true;
        }
        int ans = 0;
        for (string &word : words) {
            bool inAllow = true;
            for (char &c : word) {
                if (allow[c - 'a'] != true) {
                    inAllow = false;
                    break;
                }
            }
            if (inAllow == true) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {

    Solution solution;

    string allowed;
    cin >> allowed;

    vector<string> words;
    int nums;
    cin >> nums;
    for (int i = 0; i < nums; ++i) {
        string word;
        cin >> word;
        words.emplace_back(word);
    }

    int ans = solution.countConsistentStrings(allowed, words);

    cout << ans << endl;

    return 0;
}