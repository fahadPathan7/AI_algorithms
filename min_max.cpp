#include<bits/stdc++.h>
using namespace std;
#define ll long

vector<ll> vec[100];
map<ll, ll> val;
map<ll, bool> vis;

ll minimax(ll source, ll indicator) {
    vis[source] = true;
    ll min_val = INT_MAX, max_val = -100000;
    for (auto x : vec[source]) {
        if (!vis[x]) {
            if (val[x] == INT_MAX) {
                ll temp = minimax(x, !indicator);
                min_val = min(min_val, temp);
                max_val = max(max_val, temp);;
            }
            else {
                min_val = min(min_val, val[x]);
                max_val = max(max_val, val[x]);
            }
        }
    }
    if (indicator) val[source] = max_val;
    else val[source] = min_val;
    return val[source];
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        ll x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
        val[x] = INT_MAX,
        val[y] = INT_MAX;
    }

    int leafNodes;
    cin >> leafNodes;
    for (int i = nodes - (leafNodes - 1); i <= nodes; i++) {
        ll x;
        cin >> x;
        val[i] = x;
    }

    bool indicator = true;
    ll ans = minimax(1, indicator);
    cout << ans << endl;
}

/*
Input:
25 24
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
7 13
7 14
8 15
8 16
9 17
9 18
10 19
11 20
11 21
12 22
12 23
13 24
14 25
11
1 2 3 4 5 6 7 8 9 10 11

Output:
8
*/