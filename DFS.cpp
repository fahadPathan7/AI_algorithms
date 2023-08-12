#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mx 100000

ll node, edge, t = 1;
vector<ll> sTime(mx), eTime(mx);
vector<ll> traverse;
vector<ll> adj[mx];
vector<bool> visited(mx, 0);

void dfs(ll cNode) {
    traverse.pb(cNode);
    visited[cNode] = 1;
    sTime[cNode] = t++;

    for (ll i = 0; i < adj[cNode].size(); i++) {
        if (!visited[adj[cNode][i]]) {
            dfs(adj[cNode][i]);
        }
    }

    eTime[cNode] = t++;
}
int main() {
    cin >> node >> edge;

    for (ll i = 0; i < edge; i++) {
        ll a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a); // for unorder edge
    }

    dfs(0); // single source dfs with 0 as starting node
}
