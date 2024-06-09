#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> nails(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++){
        cin >> nails[i];
    }
    sort(nails.begin(), nails.end());

    if (n == 2){
        cout << nails[1] - nails[0];
    }
    else if(n == 3){
        cout << nails[2] - nails[0];
    }
    else{
        dp[0] = nails[1] - nails[0];
        dp[1] = nails[2] - nails[0];
        for (int i = 2; i < n - 1; i++){
            dp[i] = nails[i + 1] - nails[i] + min(dp[i - 1], dp[i - 2]);
        }
        cout << dp[n - 2];
    }

    return 0;
}