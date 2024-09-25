#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

//  ~~ * ~~ NGHIA HAS GH ~~ * ~~ //
//  ~~ * ~~ NGHIA belongs to GHL ~~ * ~~

const long long ghl = 15052007;
const long long anniversary = 11102022;
const bool i_love_you_so_much = true; 
const long long MOD = 1e9 + 7;
const long long MAX = 1e18;

// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //


int n, m;
int visited[100005];
vector <int> path[100005];

int diz[100005];
int oppo(int x){
    if(x == 1)  return 2;
    else    return 1;
}
void dfs(long long u, int dv){
    if(visited[u] == 1){
        //if(diz[u] != dv){
            //cout<<"IMPOSSIBLE", 0;
        //}
           return;
    }

    visited[u] = 1;
    diz[u] = dv;
    dv = oppo(dv);
    for(auto v : path[u]){
        if(visited[v] == 1) continue;
        else{
            dfs(v, dv);
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin>>u>>v;
        path[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            dfs(i, 1);
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<diz[i]<<' ';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    SOL GHL;
  //  GHL.solve();
  solve();

}