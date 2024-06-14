#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, w;
    cin >> n >> w;

    vector<int> m(n);
    for (int i = 0; i < n; i++){
        cin >> m[i];
    }

    vector<bool> dp(w + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++){
        for (int j = w; j >= m[i]; j--){
            dp[j] = dp[j] || dp[j - m[i]];
        }
    }
    
    bool flag = true;
    for (int i = w; i >= 0; i--){
        if (dp[i]){
            cout << i;
            flag = false;
            break;
        }
    }
    if (flag)
        cout << 0;
    return 0;
}
