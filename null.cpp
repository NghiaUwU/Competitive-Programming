#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
#define vii vector<int>
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
const int inf = 10000000000000000LL;
const int N = 2e5;

int f[N + 5], trace[N + 5];
bool vis[N + 5];
vector <int> g[N + 5], topo;

void dfs(int u) {
    vis[u] = true;
    for(auto v : g[u])
        if(!vis[v]) dfs(v);
    topo.pb(u);
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }

    for(int i = 1; i <= n; ++i)
        if(!vis[i]) dfs(i);
    f[n] = 1;
    for(auto i : topo) {
        int u = i;
        for(auto v : g[u]) {
            f[u] = (f[u] + f[v]) % mod;
        }
    }
    cout << f[1];

}