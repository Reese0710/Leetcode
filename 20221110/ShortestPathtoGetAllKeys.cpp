#include<vector>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    struct State {
        int x;
        int y;
        int key;
    };

public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        State start;
        int keyCnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    start.x = i;
                    start.y = j;
                    start.key = 0;
                }
                if (islower(grid[i][j])) {
                    keyCnt++;
                }
            }
        }

        queue<State> q;
        q.push(start);
        int allKey = (1 << keyCnt) - 1;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(allKey + 1, false)));
        int step = 0;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                State cur = q.front();
                q.pop();

                if (cur.key == allKey) {
                    return step;
                }

                for (int j = 0; j < 4; ++j) {
                    int x = cur.x + dx[j];
                    int y = cur.y + dy[j];
                    if (x < 0 || y < 0 || x >= m || y >= n) {
                        continue;
                    }

                    char c = grid[x][y];
                    int key = cur.key;

                    if (c == '#') {
                        continue;
                    }
                    if (isupper(c) && (key >> (c - 'A') & 1) == 0) {
                        continue;
                    }
                    if (islower(c)) {
                        key |= 1 << (c - 'a');
                    }
                    if (visited[x][y][key] == true) {
                        continue;
                    }

                    visited[x][y][key] = true;
                    q.push(State{x, y, key});
                }
            }
            step++;
        }
        return -1;
    }
};

int main() {

    Solution solution;

    vector<string> grid;
    int nums;
    cin >> nums;
    for (int i = 0; i < nums; ++i) {
        string str;
        cin >> str;
        grid.emplace_back(str);
    }
    int ans = solution.shortestPathAllKeys(grid);

    cout << ans << endl;

    return 0;
}