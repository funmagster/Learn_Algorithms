#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e9;
vector<int> dist;

void calk_dist(int n, vector<vector<int>>& edges){
    dist[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < edges.size(); j++){
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (dist[u] != inf && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int u, v, w;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    dist.assign(n, inf);
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = {u, v, w};
    }
    calk_dist(n, edges);
    for (int i = 0; i < n; i++){
        if (dist[i] == inf)
            cout << 3000 << ' ';
        else
            cout << dist[i] << ' ';
    }
    return 0;
}