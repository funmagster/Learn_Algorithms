#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    vector<vector<int>> graph, inv_graph;
    vector<int> visited, order;
    vector<bool> used;
    int cnt_edge = 0;

    void dfs1(int v) {
        visited[v] = 1;
        for (int u : inv_graph[v]) {
            if (!visited[u]) {
                dfs1(u);
            }
        }
        order.push_back(v);
    }

    void dfs2(int v, int component) {
        visited[v] = component;
        for (int u : graph[v]) {
            if (!visited[u]) {
                dfs2(u, component);
            }
        }
    }

    void dfs3(int v) {
        used[v] = true;
        for (int u : graph[v]) {
            if (visited[v] != visited[u])
                cnt_edge++;
            if (!used[u])
                dfs3(u);
        }
    }

public:
    Graph(int vertexCount) {
        graph.resize(vertexCount);
        inv_graph.resize(vertexCount);
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
        inv_graph[v].push_back(u);
    }

    int CountScc() {
        visited.assign(graph.size(), 0);
        for (int v = 0; v < graph.size(); v++) {
            if (!visited[v]) {
                dfs1(v);
            }
        }
        reverse(order.begin(), order.end());

        visited.assign(graph.size(), 0);
        int sccCount = 0;
        for (int v : order) {
            if (!visited[v])
                dfs2(v, ++sccCount);
        }

        used.assign(graph.size(), false);
        for (int v = 0; v < graph.size(); v++) {
            if (!used[v]) {
                dfs3(v);
            }
        }
        return cnt_edge;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int vertexCount, edgeCount, u, v;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        cin >> u >> v;
        graph.addEdge(u - 1, v - 1);
    }

    cout << graph.CountScc();
    return 0;
}
