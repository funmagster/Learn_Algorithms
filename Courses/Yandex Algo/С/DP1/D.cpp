#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> table[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    vector<vector<char>> parents(n, vector<char>(m, ' '));

    dp[0][0] = table[0][0];

    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + table[0][j];
        parents[0][j] = 'R';
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + table[i][0];
        parents[i][0] = 'D';
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j] + table[i][j];
                parents[i][j] = 'D';
            } else {
                dp[i][j] = dp[i][j-1] + table[i][j];
                parents[i][j] = 'R';
            }
        }
    }

    cout << dp[n-1][m-1] << endl;

    string ans;
    int i = n - 1, j = m - 1;
    while (i > 0 || j > 0) {
        if (parents[i][j] == 'D') {
            ans += 'D';
            i--;
        } else {
            ans += 'R';
            j--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << ' ';
    }
    return 0;
}