#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define ty1 first
#define ty2 second
//  ~~ * ~~ NGHIA HAS GH ~~ * ~~ //
//  ~~ * ~~ NGHIA belongs to GHL ~~ * ~~

const long long ghl = 15052007;
const long long anniversary = 11102022;
const bool i_love_you_so_much = true; 
const long long MOD = 1e9 + 7;
const long long MAX = 1e18;

// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //


vector < int > path[300005];
int n, m;
int city[300005];

pair <int, int> node[300005];
int visited[300005];
pair <int, int>  dfs(int u, int par){
    pair <int, int> h = {0, 0}; 

    visited[u] = 1;
    for(auto v : path[u]){
        if(v != par && visited[v] == 0){
            h = dfs(v, u);
            //visit[v] = 1;
            node[u].ty1 += h.ty1;
            node[u].ty2 += h.ty2;
        }
    } 

    if(city[u] == 1)    node[u].ty1++;
    else if(city[u] == 2)   node[u].ty2++;
    
    return node[u];


}
int res = 0;
int c1, c2;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     //GHL;
     cin>>n;
    for(int i = 1; i <= n; i++) cin>>city[i];
        int u, v;
    for(int i = 1; i < n; i++){
        cin>>v>>u;
        path[v].push_back(u);
        path[u].push_back(v);                
    }
    memset(node, 0, sizeof(node));
    dfs(1, 0);
    //cout<<"TAC"<<'\n';
    for(int i = 1; i <= n; i++){
        
        //cout<<i<<' '<<node[i].ty1<<' '<<node[i].ty2<<'\n';
        if((node[i].ty1 == 0 || node[i].ty2 == 0) && (node[1].ty1 - node[i].ty1 == 0 || node[1].ty2 - node[i].ty2 == 0))
            res++;    
        
    }

    cout<<res;

            

}

//F1[I]=SL1
//F2[I]=SL2
//(F1[I]==0||F2[I]==0)

//PCL
//CL1=TONGTCL1-F1[I]
//CL2=TONGTCL2-F2[I]
//CL1==0||CL2==0)
