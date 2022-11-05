#include <iostream>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int step = 0;
        while (sum < target || (sum - target) % 2 != 0) {
            step++;
            sum += step;
        }
        return step;
    }
};


int main() {

    Solution solution;

    int target;
    cin >> target;

    int ans = solution.reachNumber(target);

    cout << ans << endl;

    return 0;
}