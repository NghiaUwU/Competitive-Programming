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
const long long MAX = 1e9;

// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //

int n, m, k;
long long shortest_dis[19][19];
vector <pair <int, long long> > dis[200001];
int bank[19];
void dijkstra(int u ){
    vector <int> trace;
    trace.resize(n, - 1);
    vector <bool> mark(n, 0);
    priority_queue <pair <int, long long>, vector <pair <int, long long> >, greater <pair <int, long long> > > pq;
    for(int i = 1; i <= k; i++){
        shortest_dis[u][bank[i]] = MAX;
    }
    shortest_dis[u][u] = 0;
    pq.push({u, 0});
    while(!pq.empty()){
        pair <int, long long> doop = pq.top();
        pq.pop();

        int s = doop.first;
        if(mark[s] == 1)    continue;
        mark[s] = 1;

        for(auto v : dis[s]){
            int fir = v.first;
            long long sec = v.second;

            if(shortest_dis[u][fir] > shortest_dis[u][s]+ sec){
                shortest_dis[u][fir] =  shortest_dis[u][s] + sec;
                pq.push({fir, shortest_dis[u][fir]});
                trace[fir] = s;
            }
        }
    }

    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    for(int i = 1; i <= k; i++) cin>>bank[i];

    int u, v;
    long long x;
    memset(shortest_dis, MAX, sizeof(shortest_dis));
    for(int i = 1; i <= m; i++){
        cin>>u>>v>>x;
        dis[u].push_back({v, x});
        dis[v].push_back({u, x});
    }    
    for(int i = 1; i <= k; i++){
        dijkstra(bank[i]);
    }
    cout<<shortest_dis[bank[1]][bank[2]];


    

}