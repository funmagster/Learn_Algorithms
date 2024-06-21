#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int k, int start_mod,
         vector<vector<pair<int, int>>>& graph,
         vector<pair<int, int>>& parents,
         vector<bool>& used) {
    used[start_mod] = true;
    queue<int> q;
    q.push(start_mod);
    while (!q.empty()) {
        int current_mod = q.front();
        q.pop();
        if (current_mod == 0) break;
        for (auto [next_mod, digit] : graph[current_mod]) {
            if (!used[next_mod]) {
                used[next_mod] = true;
                q.push(next_mod);
                parents[next_mod] = {current_mod, digit};
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string x;
    int k, num_digits;
    cin >> x >> k;
    cin >> num_digits;
    vector<int> digits(num_digits);
    for (int i = 0; i < num_digits; i++) {
        cin >> digits[i];
    }

    sort(digits.begin(), digits.end());

    int start_mod = 0;
    for (char c : x) {
        start_mod = (start_mod * 10 + (c - '0')) % k;
    }

    vector<vector<pair<int, int>>> graph(k);
    for (int mod = 0; mod < k; mod++) {
        for (int d : digits) {
            graph[mod].emplace_back((mod * 10 + d) % k, d);
        }
    }

    vector<pair<int, int>> parents(k, {-1, -1});
    vector<bool> used(k, false);

    bfs(k, start_mod, graph, parents, used);

    if (!used[0]) {
        cout << -1;
        return 0;
    }

    string ans;
    int mod = 0;
    while (mod != start_mod) {
        ans += to_string(parents[mod].second);
        mod = parents[mod].first;
    }

    reverse(ans.begin(), ans.end());
    cout << x << ans;
    return 0;
}
