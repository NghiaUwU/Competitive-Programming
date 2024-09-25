#include <bits/stdc++.h>
using namespace std;

#define pp pair<long long, long long>
#define pi M_PI
#define v2d vector<vector<long long>>
#define vpp vector<pp>
typedef long long ll;
const long long mxN = 1e5 + 2;
const long long MEX = 1e18;
class SOL{
    public: 
        ll n, m, k;
        const int mx = 1e8;
        bool getdis[mxN];
        vector <pair <int, int > > gx[100001];
        vector <pair <int, int> >  gn[100001];
        long long disx[mxN], disn[mxN];
        long long ans = MEX;

        void solve(){
            cin>>n>>m>>k;
            

            while(m--){
                long long a, b, c;
                cin>>a>>b>>c;
                gx[a].push_back({b, c});
                gn[b].push_back({a, c});
            }

            for(int i = 2; i <= n; i++) disx[i] = LLONG_MAX;
            for(int i = 1; i < n; i++)  disn[i] = LLONG_MAX; 

            
            

            priority_queue<pp, vpp, greater<pp>> waitin;
            waitin.push({0, 1});

	        while(!waitin.empty()){
                long long u = waitin.top().second;
                waitin.pop();

                if(getdis[u] == true)  continue;
                getdis[u] = true;

                for(int i = 0; i < gx[u].size(); i++){
                    long long v = gx[u][i].first;
                    long long w = gx[u][i].second;

                    if(disx[v] > disx[u] + w){
                        disx[v] = disx[u] + w;
                        waitin.push({disx[v], v});
                    }
                }
            }

            for(int i = 1; i <= n; i++) getdis[i] = false;
            waitin.push({0, n});

            while(!waitin.empty()){
                long long u = waitin.top().second;
                waitin.pop();

                if(getdis[u] == true)   continue;
                getdis[u] = true;

                for(int i = 0; i < gn[u].size(); i++){
                    long long v = gn[u][i].first;
                    long long w = gn[u][i].second;

                    if(disn[v] > disn[u] + w){
                        disn[v] = disn[u] + w;
                        waitin.push({disn[v], v});
                    }
                }
            }

            for(int i = 1; i <= n; i++){
                for(int j = 0; j < gx[i].size(); j++){
                    long long u = i;
                    long long v = gx[i][j].first;
                    long long w = gx[i][j].second /2 ;
                    if(disx[u] != LLONG_MAX && disn[v] != LLONG_MAX){
                        long long price =  disx[u] + w + disn[v];
                        ans = min(ans, price);
                    }
                }
            }

            cout<<ans;
            return;

            
        }
        
};
SOL hansocute;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    hansocute.solve();
}