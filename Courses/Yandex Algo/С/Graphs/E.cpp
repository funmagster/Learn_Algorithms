#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& used, vector<int>& component) {
    used[v] = true;
    component.push_back(v + 1);
    for (int u : graph[v]) {
        if (!used[u]) {
            dfs(u, graph, used, component);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> used(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            vector<int> component;
            dfs(i, graph, used, component);
            components.push_back(component);
        }
    }

    cout << components.size() << endl;
    for (const auto& component : components) {
        cout << component.size() << endl;
        for (int vertex : component) {
            cout << vertex << ' ';
        }
        cout << endl;
    }

    return 0;
}
