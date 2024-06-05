#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int n, l, r, cnt_app = 0;
    cin >> n;

    vector<pair<int, int>> table(n);
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        table[i] = make_pair(l, r);
    }

    sort(table.begin(), table.end(), compare);

    int i = 0;
    while (i < n) {
        cnt_app++;
        int j = i + 1;
        while (j < n) {
            if (table[j].first >= table[i].second)
                break;
            j++;
        }
        i = j;
    }
    cout << cnt_app;
    return 0;
}
