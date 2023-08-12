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

int main() {
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int startNode, targetNode, limit;
    cin >> startNode >> targetNode >> limit;

    if (DLS(startNode, targetNode, limit)) {
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
0 6 1

Output:
Target node is not found
*/