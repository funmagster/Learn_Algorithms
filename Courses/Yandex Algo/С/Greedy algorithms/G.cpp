/*
not yet resolved
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    long long m;
    cin >> m;
    vector<long long> a(31);
    for (int i = 0; i < 31; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < 31; ++i) {
        a[i] = min(a[i], 2 * a[i - 1]);
    }

    long long result = LLONG_MAX;
    long long current_cost = 0;
    long long needed_seconds = m;

    for (int i = 30; i >= 0; --i) {
        long long unit_seconds = 1LL << i;
        if (needed_seconds == 0) break;
        
        long long count = (needed_seconds + unit_seconds - 1) / unit_seconds;
        result = min(result, current_cost + count * a[i]);

        long long buy = needed_seconds / unit_seconds;
        current_cost += buy * a[i];
        needed_seconds -= buy * unit_seconds;
    }

    cout << result << endl;

    return 0;
}
