#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, n));
        for (auto &mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        for (int k = 0; k < n; ++k) {
            int left = 0, right = 0, up = 0, down = 0;
            for (int i = 0, j = n - 1; i < n; ++i, --j) {
                left = (grid[k][i] == 0 ? 0 : left + 1);
                grid[k][i] = min(grid[k][i], left);

                right = (grid[k][j] == 0 ? 0 : right + 1);
                grid[k][j] = min(grid[k][j], right);

                up = (grid[i][k] == 0 ? 0 : up + 1);
                grid[i][k] = min(grid[i][k], up);
                
                down = (grid[j][k] == 0 ? 0 : down + 1);
                grid[j][k] = min(grid[j][k], down);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, grid[i][j]);
            }
        }
        return ans;
    }
};

int main() {

    Solution solution;

    int n;
    cin >> n;

    vector<vector<int>> mines;
    int nums;
    cin >> nums;
    for (int i = 0; i < nums; ++i) {
        int x, y;
        cin >> x;
        cin >> y;
        vector<int> mine = {x, y};
        mines.emplace_back(mine);
    }

    int ans = solution.orderOfLargestPlusSign(n, mines);

    cout << ans << endl;

    return 0;
}