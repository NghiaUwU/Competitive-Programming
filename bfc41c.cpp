#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


class SOL{
    public:
        ll n, t, q;
        ll maximize[10004];
        ll ans = 0;
        ll x, y;
        void solve(){
            cin>>n>>t>>q;
            memset(maximize, 0, sizeof(maximize));
            for(int i = 1; i <= q; i++){
                cin>>x>>y;
                
                //long long temp = maximize[x];
                
                if(y > maximize[x]){
                    ans += y - maximize[x];
                    maximize[x] = max(maximize[x], y);
                }
                //cout<<ans<<" "<<maximize[x]<<'\n';
                if(ans >= t){
                    cout<<i;
                    return;
                }
            }
            ans = 0;
            for(int i = 1; i <= n; i++) ans += maximize[i];
            if(ans >= t)    cout<<n;
            else    cout<<"-1";
        }
};
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
 }
