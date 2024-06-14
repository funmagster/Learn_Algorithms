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
    if (dp[w])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
