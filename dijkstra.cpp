#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        int n, m;
        long long u, v, q;
        vector <pair <long long, long long> > path[10004];
        long long a[10004];
        long long trace[10004];

        void solve(){
            cin>>n>>m;
            for(int i = 1; i <= m; i++){
                cin>>u>>v>>q;
                if(u > v)   swap(u, v);
                path[u].push_back({v, q});
            }
            memset(a, - 1, sizeof(a));
            a[1] = 0;
            for(int i = 1; i <= n; i++){
                for(auto v : path[i]){
                    

                    if(a[v.first]  == -1){
                        
                        a[v.first] = a[i] +  v.second;
                        trace[v.first] = i;
                    } 
                    else{
                        if(a[v.first] > a[i] + v.second){
                            a[v.first] = a[i] + v.second;
                            trace[v.first] = i;
                        }
                    }
                    //cout<<i<<" "<<v.first<<" "<<a[i]<<endl;
                }
            }

            for(int i = 2; i <= n; i++) cout<<a[i]<<" ";


        }
        
};

SOL han;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    han.solve();
}