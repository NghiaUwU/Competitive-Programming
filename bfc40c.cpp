#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        int n;
        ll ans = 0;
        ll a[100005];
        void solve(){
            cin>>n;
            for(int i = 1; i <= n; i++) cin>>a[i];
        
            for(int i = 1; i <= n - 2; i++){
                for(int j = i + 1; j <= n -1; j++){
                    for(int k = j + 1; k <= n; k++){
                        ans = max(ans, a[i] + a[j] + a[k] - (a[i] ^ a[j] ^ a[k]));
                    }
                }

            }

            cout<<ans;
        }
};  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}