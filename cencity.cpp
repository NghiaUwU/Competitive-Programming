#include <bits/stdc++.h>
using namespace std;

typedef string str;

typedef long long ll;

vector <int> g[100004], rev[100004];
vector <bool> used;
vector <int> topo;
vector <int> com;
vector <int> member[100004];
int low[100004];
int fromwhere[100004];
int nonorphan[100004];

void dfsfortopo(int u){
    used[u] = true;

    for(auto v: g[u]){
        if(!used[v])    dfsfortopo(v);
    }
    topo.push_back(u);
}

int res = 0;
void dfsforstrong(int u, int &res){
    used[u] = true;
    com.push_back(u);
    fromwhere[u] = res;
    member[res].push_back(u);
   // cout<<u<<' '<<fromwhere[u]<<'\n';
    
    for(auto v: rev[u]){
        if(!used[v])    dfsforstrong(v, res);    
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        rev[y].push_back(x);
    }

    used.assign(n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!used[i])    dfsfortopo(i);
    }

    reverse(topo.begin(), topo.end());
    used.assign(n + 1, false);

    int res = 0;
    for(auto i : topo){
        if(!used[i]){
            res++;
            dfsforstrong(i, res);
            com.clear();
        }
    }
    //for(int i = 1; i <= n; i++) low[i] = fromwhere[i];
    //memset(nonorphan, 0, sizeof(nonorphan));
    int wheretoput = 0;
    if(res == 1){
        cout<<member[1].size()<<'\n';
        sort(member[1].begin(), member[1].end());
        for(int i = 0; i < member[1].size(); i++){
            cout<<member[1][i]<<' ';
        }
        exit(0);
    }
    int outside = 0;
    //cout<<res<<'\n';
    for(int i = 1; i <= res; i++){
        outside = 0;
        for(auto u : member[i]){
            for(auto v : g[u]){
                if(fromwhere[u] != fromwhere[v]){
                    outside = 1;
                    //cout<<i<<" "<<"GOT BREAK"<<'\n';
                    break;
                }
            }
            if(outside == 1){
                break;
                //cout<<"GOT BREAK"<<'\n';
            }
        }
        if(outside == 0){
            if(wheretoput != 0){
                cout<<"0";
                exit(0);
            }
            else    wheretoput = i;
        }
    }

    
   
        cout<<member[wheretoput].size()<<'\n';
        sort(member[wheretoput].begin(), member[wheretoput].end());


        for(auto x : member[wheretoput]){
            cout<<x<<" ";
        }
    
}