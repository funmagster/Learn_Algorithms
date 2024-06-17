#include <iostream>
#include <vector>

using namespace std;

void split(int n, int m, vector<int>& curr) {
    if (n == 1) {
        for (int i = 0; i < curr.size(); ++i) {
            if (i > 0) cout << '*';
            cout << curr[i];
        }
        cout << endl;
        return;
    }

    for (int i = m; i <= n; ++i) {
        if (n % i == 0) {
            curr.push_back(i);
            split(n / i, i, curr);
            curr.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> curr;
    split(n, m, curr);
    return 0;
}
