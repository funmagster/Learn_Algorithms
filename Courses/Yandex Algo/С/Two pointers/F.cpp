#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> mas(n);
    vector<long long> pr(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    for (int i = 1; i <= n; i++) {
        pr[i] = pr[i - 1] + mas[i - 1];
    }

    int min_i = 0;
    int i_best = 0, j_best = 1;
    
    for (int j = 1; j <= n; j++) {
        if (pr[j - 1] < pr[min_i]) {
            min_i = j - 1;
        }
        if (pr[j] - pr[min_i] > pr[j_best] - pr[i_best]) {
            j_best = j;
            i_best = min_i;
        }
    }
    cout << i_best + 1 << ' ' << j_best << ' ' << pr[j_best] - pr[i_best];
}
