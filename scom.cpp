#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector <int> g[100004], rev[100004];
vector <int> topo;
vector <bool> used;
vector <int> com;
int fromwhere[100004];
int nonorphan[100004];
void dfsfortopo(int u){
    used[u] = true;
    
    for(auto v : g[u]){
        if(!used[v])   dfsfortopo(v);
    }

    topo.push_back(u);
    //cout<<u<<" "<<topo.top()<<'\n';
}

int ans = 0, res;
void dfsforstrong(int u, int res){
    //cout<<u<<' ';
    used[u] = true;
    com.push_back(u);
    fromwhere[u] = res;
    //cout<<u<<' '<<fromwhere[u]<<'\n';
    for(auto v: rev[u]){
        //if(m[v] == 1)  ans++;
        if(!used[v])  dfsforstrong(v, res);
    }
}
vector <int> toposure;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
            for(int i = 1; i <= m; i++){
                int x, y;
                cin>>x>>y;

                g[x].push_back(y);
                rev[y].push_back(x);

            }
            //cout<<"TATICS"<<'\n';
            
            used.assign(n + 1, false);
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(!used[i])    dfsfortopo(i);
            }
                used.assign(n + 1, false);  

                reverse(topo.begin(), topo.end());
                res = 0;
                for(auto v : topo){
                    if(!used[v]){
                        res++;
                        dfsforstrong(v, res);
                        com.clear();
                        ans++;
                    }
                    //cout<<'\n';
                }
            memset(nonorphan, 0, sizeof(nonorphan));
            int adjacent = 0;
            used.assign(n + 1, false);
            for(int i = 1; i <= n; i++){
                for(auto v: g[i]){
                    //cout<<i<<' '<<v<<'\n';
                    if(fromwhere[i] != fromwhere[v]){
                        if(nonorphan[fromwhere[v]] == 0){
                            nonorphan[fromwhere[v]] = 1;
                            //cout<<"SPECIAL: "<<i<<" "<<v<<'\n';
                            adjacent++;
                        }
                    }
                }
            }
            
            cout<<ans - adjacent;
            
}