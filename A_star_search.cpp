#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll node, edge;
unordered_map<string, vector<pair<ll, string>>> adj;
unordered_map<string, ll> dis, heuristic;
unordered_map<string, string> parent;
vector<string> path;
unordered_map<string, bool> vis;

void dijkstra(string sNode, string destination) {
    dis[sNode] = heuristic[sNode];
    parent[sNode] = sNode;

    multiset<pair<ll, string>> ms;
    ms.insert({ heuristic[sNode], sNode });

    while (!ms.empty()) {
        pair<ll, string> p = *ms.begin();
        ms.erase(ms.begin());
        string cNode = p.second;

        if (cNode == destination) break;

        if (vis[cNode]) continue; // avoiding negative cycle and revisit
        vis[cNode] = true;

        for (ll i = 0; i < adj[cNode].size(); i++) {
            string tNode = adj[cNode][i].second;
            ll weight = p.first - heuristic[cNode] + adj[cNode][i].first + heuristic[adj[cNode][i].second];
            if (weight < dis[tNode]) {
                dis[tNode] = weight;
                parent[tNode] = cNode;

                ms.insert({ dis[tNode], tNode });
            }
        }
    }
}

void trackPath(string cNode, string source) {
    path.push_back(cNode);
    if (cNode == source) return;
    trackPath(parent[cNode], source);
}
int main() {
    cin >> node >> edge;

    for (ll i = 0; i < edge; i++) {
        string eFrom, eTo;
        ll weight;
        cin >> eFrom >> eTo >> weight;

        adj[eFrom].push_back({ weight, eTo });
        adj[eTo].push_back({ weight, eFrom });
    }
    for (ll i = 0; i < node; i++) {
        string str;
        int val;
        cin >> str >> val;
        heuristic[str] = val;
        vis[str] = false;
        dis[str] = INT_MAX;
    }

    string source, destination;
    cin >> source >> destination;

    trackPath(destination, source);

    cout << "The path from " << source << " to " << destination << " is: " << endl;
    for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
    cout << endl << "The cost is: " << dis[destination] << endl;
}
