#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        int n, k;

        ll a[100005];
        void solve(){
            cin>>n>>k;
            for(int i = 1; i <= n; i++) cin>>a[i];
            sort(a + 1, a + 1 + n);
            ll mn = 0, mx = 0;
            for(int i = 1; i <= k; i++){
                mn += a[i];
                mx += a[n - i];
            }

            cout<<mn<<" "<<mx;
        }
};  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}