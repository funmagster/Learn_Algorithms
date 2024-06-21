#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

void bfs(int n, int m, int x_start, int y_start, vector<string>& table, vector<vector<int>>& dist, vector<vector<bool>>& used, vector<vector<pair<int, int>>>& parents) {
    vector<queue<pair<int, int>>> q(3);
    q[0].push({x_start, y_start});
    dist[x_start][y_start] = 0;
    int cnt_q = 1;
    int pos = 0;
    while (cnt_q > 0) {
        while (q[pos].empty()) {
            pos = (pos + 1) % 3;
        }
        auto [x, y] = q[pos].front();
        q[pos].pop();
        cnt_q--;
        if (used[x][y])
            continue;
        used[x][y] = true;

        // Directions vectors for N, E, S, W
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny] && table[nx][ny] != '#') {
                int cost = table[nx][ny] == '.' ? 1 : 2;
                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    q[dist[nx][ny] % 3].push({nx, ny});
                    cnt_q++;
                    parents[nx][ny] = {x, y};
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x_start, y_start, x_finish, y_finish;
    cin >> n >> m >> x_start >> y_start >> x_finish >> y_finish;
    x_start--; y_start--; x_finish--; y_finish--;

    vector<string> table(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    vector<vector<bool>> used(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m, {-1, -1}));

    bfs(n, m, x_start, y_start, table, dist, used, parents);

    if (dist[x_finish][y_finish] == INT_MAX) {
        cout << -1;
        return 0;
    }

    cout << dist[x_finish][y_finish] << endl;

    int x = x_finish, y = y_finish;
    string ans;
    while (parents[x][y].first != -1) {
        int x_next = parents[x][y].first, y_next = parents[x][y].second;
        if (x_next == x) {
            if (y_next < y)
                ans += 'E';
            else
                ans += 'W';
        } else {
            if (x_next < x)
                ans += 'S';
            else
                ans += 'N';
        }
        x = x_next;
        y = y_next;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
