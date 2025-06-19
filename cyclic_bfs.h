#ifndef CYCLIC_BFS_H
#define CYCLIC_BFS_H

#include <iostream>
#define MAX 100

using namespace std;

bool hasCycleBFS(int adj[MAX][MAX], int V) {
    int indegree[MAX] = {0};

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (adj[i][j])
                indegree[j]++;

    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        count++;

        for (int j = 0; j < V; j++) {
            if (adj[node][j]) {
                indegree[j]--;
                if (indegree[j] == 0)
                    queue[rear++] = j;
            }
        }
    }

    if (count != V) {
        cout << "[BFS] Cycle detected (Kahn's algorithm).\n";
        return true;
    } else {
        cout << "[BFS] No cycle (Kahn's algorithm).\n";
        return false;
    }
}

#endif
