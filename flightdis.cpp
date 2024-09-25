#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
const long long INF = -1e18; 
int n, m;
ll a, b, c;
bool vis1[2505], vis2[2505];
vector <int> dis1[2505], dis2[2505];
int dis[2505];
vector <tuple <int, int, int> > path;
void dfs(int s){
    if (vis1[s]) return;
    vis1[s]=1;
    for (auto i: dis1[s]) dfs(i);
}
void dfs2(int s){
    if (vis2[s]) return;
    vis2[s]=1;
    for (auto i: dis2[s]) dfs2(i);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>a>>b>>c;
        path.push_back({a, b, -c});
        dis1[a].push_back(b);
        dis2[b].push_back(a);
    }

    for(int i = 1; i <= n + 1; i++) dis[i] = INF;
    dis[1] = 0;

    dfs(1);
    dfs2(n);

    for(int i = 0; i <= n; i++){
        for(auto [a, b, c]: path){
            if(dis[b] > dis[a] + c){
                dis[b] = dis[a] + c;
                if (i==n-1 && vis1[b] && vis2[b]) {cout<<"-1"; exit(0);}
            }
        }
    }
    cout<<-dis[n];
}
