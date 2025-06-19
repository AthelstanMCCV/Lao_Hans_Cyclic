#ifndef CYCLIC_DFS_H
#define CYCLIC_DFS_H

#include <iostream>
#define MAX 100

using namespace std;

bool dfs(int v, bool visited[], bool recStack[], int parent[],
         int cycle[], int &cycleLen, int adj[MAX][MAX], int V) {
    visited[v] = true;
    recStack[v] = true;

    for (int u = 0; u < V; u++) {
        if (adj[v][u]) {
            if (!visited[u]) {
                parent[u] = v;
                if (dfs(u, visited, recStack, parent, cycle, cycleLen, adj, V))
                    return true;
            }
            else if (recStack[u]) {
                // cycle found
                cycle[cycleLen++] = u;
                int temp = v;
                while (temp != u && temp != -1) {
                    cycle[cycleLen++] = temp;
                    temp = parent[temp];
                }
                cycle[cycleLen++] = u;
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

// DFS driver function
bool hasCycleDFS(int adj[MAX][MAX], int V, const char labels[]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};
    int parent[MAX];
    int cycle[MAX];
    int cycleLen = 0;

    for (int i = 0; i < V; i++) parent[i] = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, parent, cycle, cycleLen, adj, V)) {
                cout << "[DFS] Cycle found: ";
                for (int j = cycleLen - 1; j >= 0; j--) {
                    cout << labels[cycle[j]];
                    if (j != 0) cout << " -> ";
                }
                cout << endl;
                return true;
            }
        }
    }

    cout << "[DFS] No cycle.\n";
    return false;
}

#endif
