#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef uint64_t ull;

class Solution{
    public: 
        int n, m, q;
        vector <long long> link[100005];
        int a[100005];
        
        void solve(){
            cin>>n>>m>>q;
            // INPUT: 

            for(int i = 1; i <= n; i++) cin>>a[i];

            for(int i = 1; i <= m; i++){
                int u, v;
                cin>>u>>v;
                link[u].push_back(v);
                link[v].push_back(u);
            }

            for(int i = 1; i <= q; i++){
                int a, b, c, d;
                cin>>a>>b>>c>>d;
                
            }
        }
};