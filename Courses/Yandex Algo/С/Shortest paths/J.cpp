#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Node {
    int city, cost, nights;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, s, f;
    cin >> n >> m >> k >> s >> f;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
    }

    vector<vector<int>> dist(n, vector<int>(k + 1, INF));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[s-1][0] = 0;
    pq.push({s-1, 0, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        int city = current.city;
        int cost = current.cost;
        int nights = current.nights;

        if (cost > dist[city][nights]) {
            continue;
        }

        for (auto& [next_city, weight] : graph[city]) {
            if (nights + 1 <= k && dist[next_city][nights + 1] > cost + weight) {
                dist[next_city][nights + 1] = cost + weight;
                pq.push({next_city, cost + weight, nights + 1});
            }
        }
    }

    int result = INF;
    for (int i = 0; i <= k; i++) {
        result = min(result, dist[f-1][i]);
    }

    if (result == INF) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}
