#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n + 2, vector<int>(m + 2, 0));
    table[2][2] = 1;
    for (int j = 3; j < m + 2; j++){
        table[2][j] = 0;
    }
    for (int i = 3; i < n + 2; i++){
        for (int j = 2; j < m + 2; j++){
            table[i][j] = table[i - 2][j - 1] + table[i - 1][j - 2];
        }
    }
    cout << table[n + 1][m + 1];
    return 0;
}