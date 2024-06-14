#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, A, B, C, cnt = 1;
    cin >> n >> A >> B >> C;
    
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 1; i < n; i++){
        dp[i] = (i >= A && dp[i - A]) || (i >= B && dp[i - B]) || (i >= C && dp[i - C]);
        if (dp[i])
            cnt++;
    }
    cout << cnt;
}