#include <iostream>
#include <vector>

using namespace std;

int fib(int n, vector<int>& dp){
    if (dp[n] != -1){
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    cout << fib(n, dp);
    return 0;
}