#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long INF = 1e18;
ll n, m;
ll a, b, c, w;
ll dis[100005];
ll par[100005]; 
vector <tuple <int, int, int> > path;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>a>>b>>c;
        path.push_back({a, b, c});
    }
    for(int i = 1; i <= n + 1; i++) dis[i] = INF;
    dis[1]=0; 
    int f;
    for (int i = 1; i <= n + 1; i++)
    {
        f=0;
        for (auto [a,b,w]: path){
            if (dis[a]+w<dis[b]){
                dis[b] = dis[a]+w;
                par[b] = a;
                f=b;
            }
        }
    }
    if (!f){cout<<"NO"; return;}
    else{
        cout<<"YES<"<<endl;
        vector <int> cyc;
        for(int i = 1; i <= n + 1; i++) f = par[f];
        for (int x = f;; x = par[x]){
            cyc.push_back(x);
            if (x==f && cyc.size()>1) break;
        }
        
        reverse(cyc.begin(), cyc.end());
        for (auto i: cyc) cout<<i<<" ";
    }


}