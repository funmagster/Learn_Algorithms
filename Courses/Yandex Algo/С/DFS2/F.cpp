#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct apple {
    int x, y, z, r;
};

int cnt_fall_apple = 0;

double dist(apple a1, apple a2) {
    return sqrt((a1.x - a2.x) * (a1.x - a2.x) + (a1.y - a2.y) * (a1.y - a2.y));
}

bool will_it_fall(apple a1, apple a2) {
    return dist(a1, a2) <= a1.r + a2.r && a2.z < a1.z;
}

void dfs(int v, vector<apple>& apples, vector<bool>& used) {
    used[v] = true;
    cnt_fall_apple++;
    for (int u = 0; u < apples.size(); u++) {
        if (!used[u] && will_it_fall(apples[v], apples[u])) {
            dfs(u, apples, used);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<apple> apples(n);
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++) {
        cin >> apples[i].x >> apples[i].y >> apples[i].z >> apples[i].r;
    }

    dfs(0, apples, used);

    cout << cnt_fall_apple << endl;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;

    return 0;
}
