#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e9;
vector<int> dist;
vector<int> parents;

void dijkstra(int v, vector<vector<pair<int, int>>>& graph){
    dist[v] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, v});
    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (curr_dist > dist[v])
            continue;
        for (int i = 0; i < graph[v].size(); i++){
            int u = graph[v][i].first;
            int w = graph[v][i].second;
            if (curr_dist + w < dist[u]){
                dist[u] = curr_dist + w;
                parents[u] = v;
                pq.push({dist[u], u});
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--; t--;
    vector<vector<pair<int, int>>> graph(n);
    parents.assign(n, -1);
    dist.assign(n, inf);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(s, graph);
    if (dist[t] == inf){
        cout << -1;
    }
    else{
        cout << dist[t] << endl;
        vector<int> ans;
        while(parents[t] != -1){
            ans.push_back(t + 1);
            t = parents[t];
        }
        ans.push_back(s + 1);
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << ' ';
        }
        
    }
    return 0;
}