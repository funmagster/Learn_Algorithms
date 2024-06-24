#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Graph {
    vector<vector<int>> graph, inv_graph;
    vector<int> visited, order, component;

    void dfs1(int v) {
        visited[v] = 1;
        for (int u : inv_graph[v]) {
            if (!visited[u]) {
                dfs1(u);
            }
        }
        order.push_back(v);
    }

    void dfs2(int v, int comp) {
        component[v] = comp;
        for (int u : graph[v]) {
            if (component[u] == -1) {
                dfs2(u, comp);
            }
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

    pair<vector<int>, int> findScc() {
        visited.assign(graph.size(), 0);
        order.clear();

        for (int v = 0; v < graph.size(); v++) {
            if (!visited[v]) {
                dfs1(v);
            }
        }
        reverse(order.begin(), order.end());

        component.assign(graph.size(), -1);
        int sccCount = 0;
        for (int v : order) {
            if (component[v] == -1) {
                dfs2(v, ++sccCount);
            }
        }

        return {component, sccCount};
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

    vector<int> scc;
    int c;
    tie(scc, c) = graph.findScc();
    cout << c << endl;
    for (int i = 0; i < scc.size(); i++) {
        cout << c - scc[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}
