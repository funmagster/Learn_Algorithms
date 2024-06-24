#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool topSort(int v, vector<vector<int>>& graph, vector<int>& visited, stack<int>& Stack) {
    visited[v] = 1;

    for (int u : graph[v]) {
        if (visited[u] == 1) {
            return false;
        }
        if (visited[u] == 0) {
            if (!topSort(u, graph, visited, Stack)) {
                return false;
            }
        }
    }

    visited[v] = 2;
    Stack.push(v);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
    }

    vector<int> visited(n, 0);
    stack<int> Stack;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (!topSort(i, graph, visited, Stack)) {
                cout << -1;
                return 0;
            }
        }
    }

    while (!Stack.empty()) {
        cout << Stack.top() + 1 << ' ';
        Stack.pop();
    }

    return 0;
}
