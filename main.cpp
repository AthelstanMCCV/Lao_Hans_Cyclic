#include <iostream>
#define MAX 100

#include "cyclic_dfs.h"
#include "cyclic_bfs.h"

using namespace std;

int main() {
    // Predefined Matrix, Reconstructed From Previous Lecture Assignment
    const int V = 7;
    int adj[MAX][MAX] = {
        //A  B  C  D  E  F  G
        { 0, 0, 1, 0, 0, 0, 0 }, // A (0)
        { 0, 0, 0, 0, 0, 0, 0 }, // B (1)
        { 0, 1, 0, 0, 1, 1, 1 }, // C (2)
        { 1, 0, 0, 0, 0, 0, 0 }, // D (3)
        { 1, 0, 0, 0, 0, 0, 0 }, // E (4)
        { 0, 1, 0, 0, 0, 0, 0 }, // F (5)
        { 0, 0, 0, 0, 0, 0, 0 }  // G (6)
    };

    char labels[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };

    hasCycleDFS(adj, V, labels);
    hasCycleBFS(adj, V);

    return 0;
}
