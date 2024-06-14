#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    vector<int> dp(m + 1);
    vector<int> dp_prev(m + 1);
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0 or j == 0)
                dp[j] = 0;
            else if(a[i - 1] == b[j - 1]){
                dp[j] = dp_prev[j - 1] + 1;
            }
            else{
                dp[j] = max(dp_prev[j], dp[j - 1]);
            }
        }
        dp_prev = dp;
    }
    cout << dp[m];
    return 0;
}