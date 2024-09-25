#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll adj[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin>>n>>m>>q;
    memset(adj, 0, n + 1);
    for(int i = 1; i <= m; i++){
        int u, v;
        cin>>u>>v;
        
        adj[v]++;
        //cout<<u<<" "<<adj[u]<<endl;
    }
    
    for(int i = 1; i <= q; i++){
        int l;
        cin>>l;
        cout<<adj[l]<<endl;
    }
}