#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct threes{
    int a, b, c;
};

int main(){
    int n, a, b, c;
    cin >> n;

    vector<threes> q(n);
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        q[i].a = a;
        q[i].b = b;
        q[i].c = c;
    }
    if (n == 1)
        cout << q[0].a;
    else if (n == 2)
        cout << min(q[0].b, q[0].a + q[1].a);

    else{
        dp[0] = 0;
        dp[1] = q[0].a;
        dp[2] = min(q[0].b, q[0].a + q[1].a);
        for (int i = 3; i <= n; i++){
            dp[i] = min({
                dp[i - 1] + q[i - 1].a,
                dp[i - 2] + q[i - 2].b,
                dp[i - 3] + q[i - 3].c
            });
        }
        cout << dp[n];
    }
    return 0;
}