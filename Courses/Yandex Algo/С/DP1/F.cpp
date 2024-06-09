#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, str;
    cin >> x >> y;
    str = 9 - y;
    vector<vector<int>> table(str, vector<int>(10, 0));
    table[0][x] = 1;
    for (int i = 1; i < str; i++){
        for (int j = 1; j <= 8; j++){
            table[i][j] = table[i - 1][j - 1] + table[i - 1][j + 1];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 8; i++){
        cnt += table[str - 1][i];
    }
    cout << cnt;
    return 0;
}