#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int max_in_vector(vector<int>& mas){
    int maxs = -inf;
    for (int i = 0; i < mas.size(); i++){
        if (mas[i] > maxs && mas[i] != inf){
            maxs = mas[i];
        }
    }
    return maxs;
}
int floid(vector<vector<int>>& graph){
    int n = graph.size();

    for (int i = 0; i < n; i++){
        for (int u = 0; u < n; u++){
            for (int v = 0; v < n; v++){
                if (graph[u][i] != inf &&
                    graph[i][v] != inf &&
                    graph[u][v] > graph[u][i] + graph[i][v])
                    graph[u][v] = graph[u][i] + graph[i][v];
            }
        }
    }
    int maxs = -inf;
    for (int i = 0; i < n; i++){
        int new_elem = max_in_vector(graph[i]);
        maxs = max(maxs, new_elem);
    }
    return maxs;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
            if (graph[i][j] == -1){
                graph[i][j] = inf;
            }
        }
    }
    cout << floid(graph);
    return 0;
}