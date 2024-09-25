#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SOL{
    public:
        long long n;

        void solve(){
            cin>>n;

            long long temp = n;
            long long ans = 0;
            // MIN POINT
            for(int i = 6; i >= 1; i--){
                long long veil = temp / i;
                temp %= i;

                ans += (7 - i) * veil;

            }

            cout<<ans;
             temp = n;
             ans = 0;
            // MIN POINT
            for(int i = 1; i <= n; i++){
                long long veil = temp / i;
                temp %= i;

                ans += (7 - i) * veil;

            }
            cout<<" "<<ans;
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}