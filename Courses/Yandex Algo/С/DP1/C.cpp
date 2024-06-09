#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> table(n);
    vector<int> dp(n + 2, 0);
    for (int i = 0; i < n; i++){
        cin >> table[i];
    }
    for (int i = 2; i < n + 2; i++){
        dp[i] = min(dp[i - 1], dp[i - 2]) + table[i - 2];
    }
    cout << dp[n + 1];
    return 0;
}