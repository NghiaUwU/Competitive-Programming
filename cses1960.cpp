#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MOD = 1e9 + 7;
class SOL{
    public:
        long long f[22][(1 << 20) + 1], a, b, n, v, m;
        vector <long long> g[22];

        long long dq(long long u, long long mask){
            if(u == 0){
                if(mask == 1)   return 1;
                else    return 0;
            }

            if(f[u][mask] != -1)    return f[u][mask];
            long long res = 0;
            
            for(auto v : g[u]){
                if((mask >> v & 1) && u != v){
                    long long msk = mask & ~(1 <<u);
                    res = (res + dq(v, msk)) % MOD;
                }
            }

            f[u][mask] = res;
            return res;


        }

        void solving(){
            cin>>n>>m;
            for(int i = 1; i <= m; i += 1){
                cin>>a>>b;
                g[--b].push_back(--a);
            }

            memset(f, -1, sizeof(f));
            cout<<dq(n - 1,  (1 << n) - 1);
        }
};

SOL GHL;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    GHL.solving();
}
