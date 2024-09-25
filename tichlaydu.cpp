#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        ll a, b, c;

        void solve(){
            cin>>a>>b>>c;
            long long tich = 1;
            for(int i = a; i <= b; i++){
                tich = ((tich % c) * (i % c) % c) % c;
            }

            cout<<tich;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("CAU1.inp", "r", stdin);
    freopen("CAU1.out", "w", stdout);
    SOL GHL;
    GHL.solve();
}