#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cin >> s;
    
    vector<int> dp(s + 1, INT_MAX);
    vector<int> previous(s + 1, -1);
    dp[0] = 0;
    
    for (int i = 1; i <= s; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= x[j] && dp[i - x[j]] != INT_MAX && dp[i] > dp[i - x[j]] + 1) {
                dp[i] = dp[i - x[j]] + 1;
                previous[i] = x[j];
            }
        }
    }

    if (dp[s] == INT_MAX) {
        cout << -1;
    } else {
        vector<int> result;
        int current = s;
        while (current > 0) {
            result.push_back(previous[current]);
            current -= previous[current];
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << ' ';
        }
    }
    return 0;
}
