#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
#define vii vector<int>
#define fi first
#define se second
using namespace std;
const int inf = 10000000000000000LL;
const int N = 2e5;

int dp[N + 5], ind[N + 5], ans[N + 5], trace[N + 5];
bool vis[N + 5];
vector <int> g[N + 5], topo;

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        ind[v] ++;
    }

    queue <int> source;
    for(int i = 1; i <= n; ++i)
        if(!ind[i] == 1) source.push(i);

    while(!source.empty()) {
        int u = source.front();
        source.pop();
        topo.pb(u);
        for(auto v : g[u]) {
            ind[v] --;
            if(!ind[v]) source.push(v);
        }
    }
    dp[n] = 0;
    for(int i = topo.size() - 1; i >= 0; --i) {
        int u = topo[i];
        for(auto v : g[u]) {
            if(dp[u] < dp[v] + 1 && (dp[v] != 0 || v == n)) {
                dp[u] = dp[v] + 1;
                trace[u] = v;
            }
        }
    }
    int u = 1;
    if(!dp[u]) return cout << "IMPOSSIBLE", 0;
    cout << dp[u] + 1 << '\n';
    while(trace[u]) {
        cout << u << ' ';
        u = trace[u];
    }
    cout << n;
}