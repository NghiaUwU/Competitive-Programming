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


class SOL{
    public:
    
};

int n, m;
vector <long long> path[100005];
long long visited[100005];

int ans = 0;
void dfs(int u){
    if(visited[u] == 1)   return;
    visited[u] = 1;

    //cout<<u<<' '<<visited[u]<<'\n';
    for(auto v : path[u]){
        dfs(v);
    }
}
vector <pair <int, int> > lis;
void solve(){
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin>>u>>v;

        path[u].push_back(v);
        path[v].push_back(u);
    }
    memset(visited, 0, sizeof(visited));

    dfs(1);

    //cout<<"=-=-=-==-=-=-="<<'\n';
    for(int i = 1; i <= n; i++){

        //cout<<i<<" "<<visited[i]<<'\n';
        if(visited[i] == 0){
            ans++;
            lis.push_back({i - 1, i});
            dfs(i);
        }
    }

    cout<<ans<<'\n';

    for(int i = 0; i < lis.size(); i++){
        cout<<lis[i].first<<" "<<lis[i].second;
        if(i != lis.size() - 1) cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    //GHL.solve();
    solve();
}