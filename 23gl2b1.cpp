#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long ghl = 15052007;
const long long anniversary = 11102022;
const string every_second_with_you = "esctasy";

class SOL{
    public:
       
};

 int n;
        ll a[1000006];

        void solve(){
            cin>>n;
            ll mx = 0;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                mx = max(mx, a[i]);
            }

            cout<<mx;
            return;
        }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}