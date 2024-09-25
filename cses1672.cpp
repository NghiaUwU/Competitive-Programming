#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, q;
ll u, v, k;

ll dis[505][505];
const long long INF = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>q;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= n + 1; j++){
            dis[i][j] = INF;
        }   
    }

    for(int i = 1; i <= m; i++){
        cin>>u>>v>>k;
        dis[u][u]=0, dis[v][v]=0;
        dis[u][v]=min(dis[u][v],k), dis[v][u]=min(dis[u][v],k);
    }

    for(int k = 1; k <= n + 1; k++){
        for(int i = 1; i <= n + 1; i++){
            for(int j = 1; j <= n + 1; j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int i = 1; i <= q; i++){
        int a, b;
        cin>>a>>b;
        if(dis[a][b] < INF) cout<<dis[a][b]<<endl;
        else    cout<<"-1"<<endl;
    }


    
}