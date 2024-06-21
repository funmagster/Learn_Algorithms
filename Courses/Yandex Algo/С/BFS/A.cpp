#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, int x, vector<vector<int>>& graph, vector<int>& dist){
    dist[x] = 0;
    queue<int> q;
    q.push(x);

    int elem;
    while(!q.empty()){
        elem = q.front();
        q.pop();

        for (int u = 0; u < n; u++){
            if (graph[elem][u] == 1 && dist[u] == -1){
                dist[u] = dist[elem] + 1;
                q.push(u);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> dist(n, -1);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    bfs(n, x - 1, graph, dist);
    for (int i = 0; i < n; i++){
        cout << dist[i] << ' ';
    }
    return 0;
}