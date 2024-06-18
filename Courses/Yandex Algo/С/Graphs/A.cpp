#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        matrix[u - 1][v - 1] = 1;
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}