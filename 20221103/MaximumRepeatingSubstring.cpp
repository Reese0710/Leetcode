#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string temp = word;
        while (sequence.find(temp) != string::npos) {
            temp += word;
            count++;
        }
        return count;
    }
};


int main() {

    Solution solution;

    string sequence;
    string word;
    cin >> sequence;
    cin >> word;

    int ans = solution.maxRepeating(sequence, word);

    cout << ans << endl;

    return 0;
}