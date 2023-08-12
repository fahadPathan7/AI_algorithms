#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100);
vector<int> visited(100, 0);


bool DLS(int curNode, int target, int limit) {
    if (curNode == target) return true;
    if (limit <= 0) return false;

    visited[curNode] = 1;

    for (int i = 0; i < adj[curNode].size(); i++) {
        int nextNode = adj[curNode][i];

        if (!visited[nextNode]) {
            if (DLS(nextNode, target, limit - 1)) return true;
        }
    }

    return false;
}

bool IDS(int startNode, int targetNode, int maxDepth) {
    for (int i = 0; i <= maxDepth; i++) {
        if (DLS(startNode, targetNode, i)) return true;
    }

    return false;
}

int main() {
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int startNode, targetNode, maxDepth;
    cin >> startNode >> targetNode >> maxDepth;

    if (IDS(startNode, targetNode, maxDepth)) {
        cout << "Target node is found" << endl;
    }
    else cout << "Target node is not found" << endl;
}

/*
Input:
10 9
0 1
1 3
1 4
3 7
3 8
0 2
2 5
2 6
5 9
0 6 2

Output:
Target node is found
*/