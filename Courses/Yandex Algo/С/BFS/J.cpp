#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e9;

void bfs(queue<int>& q,
         vector<vector<int>>& graph,
         vector<int>& dist,
         vector<int>& prev){
    int v;
    while (!q.empty()){
        v = q.front();
        q.pop();
        for (int u : graph[v]){
            if (dist[u] == inf){
                dist[u] = dist[v] + 1;
                q.push(u);
                prev[u] = prev[v];
            }
            else if(dist[u] == dist[v] + 1){
                prev[u] = min(prev[v], prev[u]);
                q.push(u);
            }
        }
    }
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, elem, m, u, v;
    cin >> n >> k;
    queue<int> q;
    vector<int> dist(n, inf);
    vector<int> prev(n, inf);
    for (int i = 0; i < k; i++){
        cin >> elem;
        elem--;
        q.push(elem);
        dist[elem] = 0;
        prev[elem] = elem;
    }
    cin >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        cin >> v >> u;
        v--;
        u--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(q, graph, dist, prev);
    for (int i = 0; i < n; i++){
        cout << dist[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << prev[i] + 1 << ' ';
    }
    return 0;
}