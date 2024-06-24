#include <iostream>
#include <vector>

using namespace std;

vector<int> tin;
vector<int> tout;
int timer = 0;

void dfs(int v, const vector<vector<int>>& tree) {
    tin[v] = ++timer;
    for (int u : tree[v]) {
        dfs(u, tree);
    }
    tout[v] = ++timer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, v, root, u;
    cin >> n;
    tin.resize(n + 1);
    tout.resize(n + 1);
    vector<vector<int>> tree(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v;
        if (v == 0)
            root = i;
        else
            tree[v].push_back(i);
    }
    dfs(root, tree);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (tin[u] < tin[v] && tout[u] > tout[v])
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
