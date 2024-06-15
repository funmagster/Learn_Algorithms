// bad code timing, does not pass all tests

#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> factors(n);
    for (int i = 0; i < n; ++i) {
        cin >> factors[i];
    }

    long long product = 1;
    for (int i = 0; i < n; ++i) {
        product *= factors[i];
    }

    // dp[i][j] - количество способов разложить число j на i множителей
    vector<vector<long long>> dp(n + 1, vector<long long>(product + 1, 0));
    
    dp[0][1] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= product; ++j) {
            for (int k = 1; k <= j; ++k) {
                if (j % k == 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j / k]) % MOD;
                }
            }
        }
    }

    cout << dp[n][product] % MOD;

    return 0;
}
