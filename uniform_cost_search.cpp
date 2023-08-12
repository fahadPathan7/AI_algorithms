#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(100);
map<pair<int, int>, int> cost;

int ucs(int start, int goal) {
    priority_queue<pair<int, int>> queue;
    map<int, int> visited;

    queue.push(make_pair(0, start));

    while (queue.size() > 0) {
        pair<int, int> p = queue.top();
        queue.pop();

        p.first *= -1;

        if (p.second == goal) {
            return p.first;
        }

        if (visited[p.second] == 0) {
            for (int i = 0; i < graph[p.second].size(); i++) {
                queue.push(make_pair((p.first + cost[make_pair(p.second, graph[p.second][i])]) * -1, graph[p.second][i]));
            }
        }

        visited[p.second] = 1;
    }

    return -1;
}

int main() {
    int nodes;
    cin >> nodes;

    for (int i = 0; i < nodes - 1; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(to);
        graph[to].push_back(from);
        cost[make_pair(from, to)] = weight;
        cost[make_pair(to, from)] = weight;
    }

    int start, goal;
    cin >> start >> goal;

    cout << "Cost from node " << start << " to node " << goal << ": " << ucs(start, goal) << endl;
}

/*
Input:
9
0 1 5
0 2 2
1 3 1
1 4 4
2 5 1
2 6 7
5 7 4
5 8 5
0 6

Output:
Cost from node 0 to node 6: 7
*/