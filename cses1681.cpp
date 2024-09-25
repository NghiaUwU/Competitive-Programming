#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long N = 2e5 + 5;
const long long khue = 2e5 + 5;
const long long MOD = 1e9 + 7;
int n, m;
int u, v;
long long dp[khue];
vector <int> luvkhue[khue];
int f[N + 5], trace[N + 5];
bool vis[N + 5];
vector <int> g[N + 5], topo;
void dfs(int u) {
    vis[u] = true;
    for(auto v : g[u])
        if(!vis[v]) dfs(v);
    topo.push_back(u);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; ++i)
        if(!vis[i]) dfs(i);
    for(auto i : topo)    cout<<i<<" ";
    f[n] = 1;
    for(auto i : topo) {
        int u = i;
        for(auto v : g[u]) {
            f[u] = (f[u] + f[v]) % MOD;
        }
    }
    //cout << f[1];
}