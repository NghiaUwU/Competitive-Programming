#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
typedef unsigned long long ull;

int n, m;
int vis[100005];
vector <int> khue[100005];
vector <int> topo;
void dfs(int u){
    vis[u] = 1;
    for(auto x : khue[u]){
        if(vis[x] == 0 && x > u) dfs(x);
    }
    topo.push_back(u);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    if(m == 0){
        for(int i = 1; i <= n; i++){
            cout<<i<<" ";
        }
        exit(0);
    }

    for(int i = 1; i <= m; i++){
        int u, v;
        cin>>u>>v;
        khue[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0) dfs(i);
    }

    for(int i = 0; i < topo.size(); i++)    cout<<topo[i]<<" ";
}