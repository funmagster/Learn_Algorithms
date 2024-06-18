#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<bool>& used, vector<vector<int>>& graph){
    used[v] = true;
    for (int u:graph[v]){
        if (!used[u])
            dfs(u, used, graph);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    if (n - 1 != m){
        cout << "NO";
    }
    else{
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> used(n, false);
        for (int i = 0; i < m; i++){
            cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        dfs(0, used, graph);
        for (int i = 0; i < n; i++){
            if (!used[i]){
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
    return 0;
}