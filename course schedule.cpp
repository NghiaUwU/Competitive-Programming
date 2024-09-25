#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

ll n, m;
ll u, v;

ll vis[100005], ans[100005];
vector <int> g[100005];
stack <int> topo;

void dfs(int u){
    vis[u] = 1;
    for(auto v : g[u]){
        if(vis[v] == 1){
            cout<<"IMPOSSIBLE";
            exit(0);
        }
        if(vis[v] == 0) dfs(v);
    }

    topo.push(u);
    vis[u] = 2;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>u>>v;
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }

    int cnt = 0;
    while (!topo.empty()) {
        ans[topo.top()] = ++cnt; 
        topo.pop();
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    

    

    
}