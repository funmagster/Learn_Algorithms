#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector<int>>& graph,
                vector<pair<int, int>>& ans,
                vector<bool>& used){
    used[v] = true;
    for (int u : graph[v]){
        if (!used[u]){
            ans.push_back(make_pair(v + 1, u + 1));
            dfs(u, graph, ans, used);
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<pair<int, int>> ans;
    vector<bool> used(n, false);
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    
    dfs(0, graph, ans, used);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}