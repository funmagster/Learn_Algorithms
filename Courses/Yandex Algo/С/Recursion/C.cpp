#include <iostream>
#include <vector>

using namespace std;

unsigned long long cnt_fib(int n, vector<unsigned long long>& dp){
    if (dp[n] != -1){
        return dp[n];
    }
    dp[n] = cnt_fib(n - 1, dp) + cnt_fib(n - 2, dp) + 1;
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<unsigned long long> dp(n + 1, -1);
    dp[1] = 1;
    dp[2] = 1;
    cout << cnt_fib(n, dp);
    return 0;
}