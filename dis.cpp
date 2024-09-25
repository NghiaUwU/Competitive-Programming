#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SOL{
    public:
        
};
int n;
        long long a[1000006];

        void solve(){
            cin>>n;
            long long ans = 0;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                if(i <= 2)  continue;
                else    ans = max(ans, a[i] - a[i - 2]);
            }

            cout<<ans;
        }
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("BAI2.INP", "r")){
        freopen("BAI2.INP", "r", stdin);
        freopen("BAI2.OUT", "w", stdout);
    }
    SOL GHL;
    solve();
}