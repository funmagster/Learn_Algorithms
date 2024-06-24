#include <iostream>
#include <vector>

using namespace std;

bool dfs(int v, vector<vector<int>>& graph, vector<int>& position, vector<bool>& used){
    used[v] = true;
    for (int u : graph[v]){
        if (position[u] <= position[v])
            return false;
        if (!used[u]){
            if (!dfs(u, graph, position, used)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
    }

    vector<int> top_sort(n);
    for (int i = 0; i < n; i++){
        cin >> top_sort[i];
        top_sort[i]--;
    }

    vector<int> position(n);
    for (int i = 0; i < n; i++){
        position[top_sort[i]] = i;
    }

    vector<bool> used(n, false);
    for (int i = 0; i < n; i++){
        if (!used[i]){
            if (!dfs(i, graph, position, used)){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
