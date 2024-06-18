#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& used) {
    used[v] = true;
    for (int u : graph[v]) {
        if (!used[u]) {
            dfs(u, graph, used);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }

    vector<vector<int>> graph(n * m);
    vector<bool> used(n * m, false);

    auto index = [m](int i, int j) { return i * m + j; };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == '#') {
                int curr_ver = index(i, j);
                if (j != m - 1 && table[i][j + 1] == '#') {
                    graph[curr_ver].push_back(index(i, j + 1));
                    graph[index(i, j + 1)].push_back(curr_ver);
                }
                if (i != n - 1 && table[i + 1][j] == '#') {
                    graph[curr_ver].push_back(index(i + 1, j));
                    graph[index(i + 1, j)].push_back(curr_ver);
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == '#' && !used[index(i, j)]) {
                dfs(index(i, j), graph, used);
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}
