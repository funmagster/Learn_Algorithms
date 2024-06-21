#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, int m, vector<vector<int>>& table) {
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    queue<pair<int, int>> q;
    vector<vector<bool>> used(n, vector<bool>(m, false));
    
    q.push({0, 0});
    used[0][0] = true;
    int cnt = 0;
    
    while (!q.empty()) {
        int size = q.size();
        cnt++;
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x;
                int ny = y;
                while (true) {
                    int nnx = nx + dx[d];
                    int nny = ny + dy[d];
                    if (nnx < 0 || nnx >= m || nny < 0 || nny >= n || table[nny][nnx] == 1)
                        break;
                    nx = nnx;
                    ny = nny;
                    if (table[ny][nx] == 2) return cnt;
                }
                if (!used[ny][nx]) {
                    q.push({nx, ny});
                    used[ny][nx] = true;
                }
            }
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
    
    cout << bfs(n, m, table) << endl;
    return 0;
}
