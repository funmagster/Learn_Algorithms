// debug needed; 10/20 test

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 0; l < n - 1; ++l) {
        dp[l][l + 1] = (s[l] == s[l + 1]) ? 0 : 1;
    }
    for (int length = 3; length <= n; length++) {
        for (int l = 0; l <= n - length; l++) {
            int r = l + length - 1;
            if (s[l] == s[r]) {
                dp[l][r] = dp[l + 1][r - 1];
            } else {
                dp[l][r] = dp[l + 1][r - 1] + 1;
            }
        }
    }
    
    long long cnt = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            if (dp[l][r] <= k) {
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}
