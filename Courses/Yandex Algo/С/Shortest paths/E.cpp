#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

void floid(vector<vector<int>>& graph){
    int n = graph.size();
    vector<vector<bool>> is_two(n, vector<bool>(n, false));
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (dist[i][k] < inf && dist[k][j] < inf) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = max(dist[i][k] + dist[k][j], -inf);
                    }
                }
            }
        }
    }

    for (int k = 0; k < n; k++){
        if (dist[k][k] < 0) {
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (dist[i][k] < inf && dist[k][j] < inf) {
                        is_two[i][j] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (is_two[i][j]) {
                cout << 2 << ' ';
            } else if (dist[i][j] == inf) {
                cout << 0 << ' ';
            } else {
                cout << 1 << ' ';
            }
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int weight;
            cin >> weight;
            if (weight != 0) {
                graph[i][j] = weight;
            } else if (i == j) {
                graph[i][j] = 0;
            }
        }
    }
    floid(graph);
    return 0;
}
