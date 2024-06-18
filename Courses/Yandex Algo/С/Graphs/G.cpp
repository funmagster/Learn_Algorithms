#include <iostream>
#include <vector>

using namespace std;

int invert(int c) {
    return c == 1 ? 2 : 1;
}

bool dfs(int v, vector<vector<int>>& graph, vector<int>& used, int c) {
    used[v] = c;
    for (int u : graph[v]) {
        if (used[u]) {
            if (used[u] == used[v])
                return false;
        } else if (!dfs(u, graph, used, invert(c)))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> used(n, 0);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool isBipartite = true;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (!dfs(i, graph, used, 1)) {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
