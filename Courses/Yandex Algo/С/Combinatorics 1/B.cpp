#include <iostream>
#include <vector>

using namespace std;

void compute_binomial_coefficients(vector<vector<long long>> &C, int max_n) {
    for (int n = 0; n <= max_n; n++) {
        C[n][0] = 1;
        for (int k = 1; k <= n; k++) {
            C[n][k] = C[n-1][k-1] + C[n-1][k];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    int max_n = max(n, m);

    vector<vector<long long>> C(max_n + 1, vector<long long>(max_n + 1, 0));
    compute_binomial_coefficients(C, max_n);

    long long ans = 0;
    for (int boys = 4; boys <= n && boys <= t-1; boys++) {
        int girls = t - boys;
        if (girls >= 1 && girls <= m) {
            ans += C[n][boys] * C[m][girls];
        }
    }

    cout << ans << endl;
    return 0;
}
