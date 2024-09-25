#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector <int> g[100004], rev[100004];
vector <int> topo;
vector <bool> used;
vector <int> com;
vector <int> member[100004];
int unite[100005];
int visited[100005];
int k = 1;
void dfsfortopo(int u){
    used[u] = true;
    
    for(auto v : g[u]){
        if(!used[v])   dfsfortopo(v);
    }

    topo.push_back(u);
    //cout<<u<<" "<<topo.top()<<'\n';
}

int ans = 1;
void dfsforstrong(int u){
    //cout<<u<<' ';
    used[u] = true;
    unite[u] = ans;
    com.push_back(u);
    for(auto v: rev[u]){
        //if(m[v] == 1)  ans++;
        if(!used[v])  dfsforstrong(v);
    }
}
vector <int> sortunite;
bool cmp_for_size(int a, int b){
    if(member[a].size() == member[b].size())    return member[a][0] < member[b][0];
    return member[a].size() < member[b].size();
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
            
            for(int i = 1; i <= n; i++){
                if(!used[i])    dfsfortopo(i);
            }
                used.assign(n + 1, false);  

                reverse(topo.begin(), topo.end());
                for(auto v : topo){
                    if(!used[v]){
                        dfsforstrong(v);
                        member[ans] = com;
                        com.clear();
                        ans++;
                    }
                    //cout<<'\n';
                }
            

            cout<<ans - 1<<'\n';
            for(int i = 1; i <= n; i++){
                //cout<<"IN4: "<<i<<" "<<unite[i]<<" "<<visited[i]<<'\n';
                if(visited[i] == 0){
                    int x = unite[i];
                    sortunite.push_back(x);
                    //cout<<member[x].size()<<'\n';
                    sort(member[x].begin(), member[x].end());
                    
                    for(auto v : member[x]){
                        visited[v] = 1;
                    }
                    
                }
            }
            sort(sortunite.begin(), sortunite.end(), cmp_for_size);
            for(int i = 0; i < sortunite.size(); i++){
                cout<<member[sortunite[i]].size()<<'\n';
                for(auto v : member[sortunite[i]]){
                    cout<<v<<" ";
                }
                cout<<'\n';
            }
            
}