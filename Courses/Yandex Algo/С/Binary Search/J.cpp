#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct threes {
    long long t, z, y;
};

long long count_ball(long long time, long long t, long long z, long long y) {
    long long cycleTime = static_cast<long long>(t) * z + y;
    long long fullCycles = time / cycleTime;
    long long remainingTime = time % cycleTime;
    long long balloons = fullCycles * z + min(static_cast<long long>(z), remainingTime / t);
    return balloons;
}

bool ok(long long m, int n, long long time, const vector<threes>& a) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += count_ball(time, a[i].t, a[i].z, a[i].y);
    }
    return cnt >= m;
}

int main() {
    long long m;
    int n;
    cin >> m >> n;
    vector<threes> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].t >> a[i].z >> a[i].y;
    }

    long long l = 0, r = 1e14, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (ok(m, n, mid, a))
            r = mid;    
        else
            l = mid + 1;
    }

    cout << l << endl;
    vector<long long> balloons(n, 0);
    for (int i = 0; i < n && m > 0; ++i) {
        long long balloonsCount = count_ball(l, a[i].t, a[i].z, a[i].y);
        balloons[i] = min(m, balloonsCount);
        m -= balloons[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << balloons[i] << " ";
    }
    return 0;
}