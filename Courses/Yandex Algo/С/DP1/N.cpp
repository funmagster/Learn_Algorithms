#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 1);

    dp[1] = 0;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1];
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2]);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3]);
        dp[i]++;
    }
    
    vector<int> ans;
    int i = n;
    while (i > 1){
        if (i % 2 == 0 and dp[i / 2] + 1 == dp[i]){
            i /= 2;
            ans.push_back(2);
        }
        else if(i % 3 == 0 and dp[i / 3] + 1 == dp[i]){
            i /= 3;
            ans.push_back(3);
        }
        else{
            i--;
            ans.push_back(1);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i];
    }
    return 0;
}