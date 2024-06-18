#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    vector<int> vertex_degree(n, 0);

    for (int i = 0; i < m; i++){
        cin >> u >> v;
        vertex_degree[u - 1]++;
        vertex_degree[v - 1]++;
    }
    for (int i = 0; i < n; i++){
        cout << vertex_degree[i] << ' ';
    }
}