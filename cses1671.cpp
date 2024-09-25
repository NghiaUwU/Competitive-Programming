#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long INF = 1e9 + 17012007;
int vis[100005];
int dis[100005];
vector <pair <int, int> > adj[100005];

void solve(){
    int n, m;
    cin>>n>>m;
    int u, v, k;
    for(int i = 1; i <= m; i++){
        cin>>u>>v>>k;
        adj[u].push_back({v, k});
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i <= n + 1; i++) dis[i] = INF;
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> >> q; 
    q.push({0, 1});
    while(!q.empty()){
        int u = q.top().second; 
        q.pop();
        if (vis[u] == 0) continue;
        vis[u]=1;
        for (auto [v,w] : adj[u]){
            if (dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
