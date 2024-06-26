#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e9;

struct Edge {
    int v, start, end;
};

vector<int> dijkstra(int start, vector<vector<Edge>>& graph) {
    vector<int> dist(graph.size(), inf);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int current_time = pq.top().first;
        pq.pop();

        if (current_time > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            if (edge.start >= current_time && dist[edge.v] > edge.end) {
                dist[edge.v] = edge.end;
                pq.push({edge.end, edge.v});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d, v, r;
    cin >> n >> d >> v >> r;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < r; i++) {
        int u, start, end, dest;
        cin >> u >> start >> dest >> end;
        Edge edge;
        edge.v = dest - 1;
        edge.start = start;
        edge.end = end;
        graph[u - 1].push_back(edge);
    }
    vector<int> dist = dijkstra(d - 1, graph);
    if (dist[v - 1] == inf) {
        cout << -1;
    } else {
        cout << dist[v - 1];
    }
    return 0;
}
