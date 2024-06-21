#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int inf = 1e9;

void bfs(int v, vector<vector<pair<int, int>>>& graph,
        vector<int>& dist,
        vector<bool>& used){
    dist[v] = 0;
    vector<queue<int>> q(3);
    q[0].push(v);
    int cnt_q = 1;
    int pos = 0;
    int c, u;
    while (cnt_q > 0){
        while(q[pos].empty()){
            pos = (pos + 1) % 3;
        }

        v = q[pos].front();
        q[pos].pop();
        cnt_q--;
        if (used[v])
            continue;
        used[v] = true;

        for (int i = 0; i < graph[v].size(); i++){
            tie(u, c) = graph[v][i];
            if (dist[u] > dist[v] + c){
                dist[u] = dist[v] + c;
                q[dist[u] % 3].push(u);
                cnt_q++;
            }
        }
    }
          
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int u, v, c;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++){
        cin >> u >> v >> c;
        u--, v--;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    vector<int> dist(n, inf);
    vector<bool> used(n, false);
    bfs(0, graph, dist, used);
    if (dist[n - 1] == inf)
        cout << -1;
    else
        cout << dist[n - 1];
    return 0;
}