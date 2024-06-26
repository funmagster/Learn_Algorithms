#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;
vector<int> dist;

vector<int> getCycle(vector<int>& from, int lastVertex){
    vector<int> cycle = {lastVertex};
    for (int v = from[lastVertex]; v != lastVertex; v = from[v]){
        cycle.push_back(v);
    }
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

vector<int> fordBellman(int n, vector<vector<int>>& edges){
    vector<int> from(n, -1);
    for (int i = 0;  i < n; i++){
        for (int j = 0; j < edges.size(); j++){
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (dist[u] != inf && dist[v] > dist[u] + w){
                dist[v] = max(dist[u] + w, -inf);
                from[v] = u;
            }
        }
    }
    for (int j = 0; j < edges.size(); j++){
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (dist[u] != inf && dist[v] > dist[u] + w){
                from[v] = u;
                for (int i = 0; i < n - 1; i++){
                    v = from[v];
                }
                return getCycle(from, v);
            }
        }
    return {};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin >> n;
    vector<vector<int>> edges;
    dist.assign(n, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> w;
            if (w != 1e5){
                edges.push_back({i, j, w});
            }
        } 
    }
    vector<int> cycle = fordBellman(n, edges);
    if (!cycle.empty()){
        cout << "YES" << endl;
        cout << cycle.size() + 1 << endl;
        for (int v : cycle){
            cout << v + 1 << ' ';
        }
        cout << cycle[0] + 1;
    }
    else{
        cout << "NO";
    }
    return 0;
}