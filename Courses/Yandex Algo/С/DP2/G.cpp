#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, sums;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; i++){
        cin >> m[i];
        sums += m[i];
    }

    if (sums % 2 == 1){
        cout << "NO";
    }
    else{
        int w = sums / 2;
        vector<bool> dp(w + 1, false);
        dp[0] = true;
        for (int i = 1; i < n; i++){
            for (int j = w; j >= m[i]; j--){
                dp[j] = dp[j] || dp[j - m[i]];
            }
        }
        if (dp[w])
            cout << "YES";
        else
            cout << "NO";
    }
}