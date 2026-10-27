
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;

void dijkstra(const vector<vector<pii>>& graph, int source) {
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [distance, u] = pq.top();
        pq.pop();

        if (distance != dist[u])
            continue;

        for (auto [v, weight] : graph[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra's Algorithm\n";
    cout << "Source: a\n\n";

    for (int i = 0; i < n; i++) {
        cout << char('a' + i) << " | ";

        if (dist[i] == INT_MAX) {
            cout << "INF | Unreachable\n";
            continue;
        }

        cout << dist[i] << " | ";

        vector<int> path;
        for (int v = i; v != -1; v = parent[v])
            path.push_back(v);

        reverse(path.begin(), path.end());

        for (int j = 0; j < (int)path.size(); j++) {
            if (j > 0) cout << " -> ";
            cout << char('a' + path[j]);
        }

        cout << "\n";
    }
}

int main() {
    int n = 12;
    vector<vector<pii>> graph(n);

    auto addEdge = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };

    addEdge(0, 1, 3);  // a-b
    addEdge(0, 2, 5);  // a-c
    addEdge(0, 3, 4);  // a-d
    addEdge(1, 4, 3);  // b-e
    addEdge(1, 5, 6);  // b-f
    addEdge(2, 3, 2);  // c-d
    addEdge(2, 6, 4);  // c-g
    addEdge(3, 4, 1);  // d-e
    addEdge(3, 7, 5);  // d-h
    addEdge(4, 5, 2);  // e-f
    addEdge(4, 8, 4);  // e-i
    addEdge(5, 9, 5);  // f-j
    addEdge(6, 7, 3);  // g-h
    addEdge(6, 10, 6); // g-k
    addEdge(7, 8, 6);  // h-i
    addEdge(7, 10, 7); // h-k
    addEdge(8, 9, 3);  // i-j
    addEdge(8, 11, 5); // i-l
    addEdge(9, 11, 9); // j-l
    addEdge(10, 11, 8);// k-l

    dijkstra(graph, 0);

    return 0;
}
