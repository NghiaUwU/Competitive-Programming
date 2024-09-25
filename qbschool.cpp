#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pp pair<long long, long long>
#define pi M_PI
#define v2d vector<vector<long long>>
#define vpp vector<pp>
const int M = 5002;
class SOL{
    public: 
        ll n, m, u, v, w, type;
        vector <pair <long long, long long > > g[100005];
        ll dis_x[M + 1], dis_n[M + 1];
        bool vis[M + 1];
        vector<int> temp;

        void solving(){
            cin>>n>>m;

            temp.resize(150507);
            for(int i = 1; i <= m; i++){
                cin>>type>>u>>v>>w;
                g[u].push_back({v, w});
                if(type == 2)   g[v].push_back({u, w});
            }

            for(int i = 2; i <= n; i++)
                dis_x[i] = INT_MAX; 
            
            for(int i = 1; i <= n; i++)
                temp[i] = i;

            priority_queue<pp, vpp, greater<pp>> q;
            q.push({0, 1});
            temp[1] = 1;

            while (!q.empty()){
                ll u = q.top().second;
                q.pop();

                if (vis[u]) continue;
                vis[u] = true;

                for (int i = 0; i < g[u].size(); i++)
                {
                    ll v = g[u][i].first, w = g[u][i].second;
                    if (dis_x[v] >= dis_x[u] + w)
                    {
                        if(dis_x[v] > dis_x[u] + w)
                        {
                            temp[v] = temp[u];
                            dis_x[v] = dis_x[u] + w;
                            q.push({dis_x[v], v});
                        }
                    else
                        temp[v] += temp[u];
            }
        }
    }

    cout << dis_x[n] << " " << temp[n]; 
        }

};
SOL ask; 
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    ask.solving();
   

    


}