
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    const int n = 5;
    char vertex[] = {'a', 'b', 'c', 'd', 'e'};

    vector<vector<int>> graph(n, vector<int>(n, INF));

    auto addEdge = [&](int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    };

    addEdge(0, 1, 5); // a-b
    addEdge(0, 2, 7); // a-c
    addEdge(2, 3, 4); // c-d
    addEdge(1, 3, 6); // b-d
    addEdge(0, 4, 2); // a-e
    addEdge(2, 4, 4); // c-e
    addEdge(1, 4, 3); // b-e
    addEdge(3, 4, 5); // d-e

    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    key[0] = 0;
    int totalCost = 0;

    cout << "Prim's MST Algorithm\n\n";

    for (int step = 0; step < n; step++) {
        // Select minimum from all remaining vertices
        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!inMST[v] &&
                (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        if (u == -1 || key[u] == INF) {
            cout << "Graph is disconnected.\n";
            return 1;
        }

        inMST[u] = true;
        totalCost += key[u];

        if (parent[u] == -1) {
            cout << "Start: " << vertex[u] << "\n";
        } else {
            cout << vertex[parent[u]] << " - "
                 << vertex[u] << " : "
                 << key[u] << "\n";
        }

        // Update remaining vertices
        for (int v = 0; v < n; v++) {
            if (!inMST[v] &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nTotal MST cost: "
         << totalCost << "\n";

    return 0;
}
