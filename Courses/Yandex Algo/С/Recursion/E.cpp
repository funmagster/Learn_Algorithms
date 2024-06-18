#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<unsigned long long, unsigned long long> dp;

unsigned long long f(unsigned long long n) {
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }

    if (n % 2 == 0) {
        dp[n] = f(n / 2);
    } else {
        dp[n] = f(n / 2) + f(n / 2 + 1);
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    cout << f(n) << endl;

    return 0;
}
