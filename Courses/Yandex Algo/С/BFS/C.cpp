#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;

using namespace std;

void bfs(int n, int x1, int y1,
         vector<vector<pair<int, int>>>& parents,
         vector<vector<int>>& dist) {
    queue<pair<int, int>> q;
    dist[x1][y1] = 0;
    q.push({x1, y1});
    vector<int> dx = {1, 1, 2, 2, -1, -1, -2, -2};
    vector<int> dy = {-2, 2, -1, 1, -2, 2, -1, 1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < dx.size(); d++) {
            int tx = x + dx[d];
            int ty = y + dy[d];

            if (tx >= 0 && tx < n && ty >= 0 && ty < n &&
                dist[tx][ty] > dist[x][y] + 1) {
                dist[tx][ty] = dist[x][y] + 1;
                q.push({tx, ty});
                parents[tx][ty] = {x, y};
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x1, y1, x2, y2;
    cin >> n;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(n, {-1, -1}));
    vector<pair<int, int>> ans;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    bfs(n, x1 - 1, y1 - 1, parents, dist);

    cout << dist[x2 - 1][y2 - 1] << endl;

    int x = x2 - 1, y = y2 - 1;
    while (x != -1 && y != -1) {
        ans.push_back({x, y});
        auto [tx, ty] = parents[x][y];
        x = tx;
        y = ty;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }
    return 0;
}
