#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


class SOL{
    public:
        long long k;
        long long mod = 0;


        void solve(){
            cin>>k;
            if(k % 2 == 0){
                cout<<"-1";
                return;
            }
            for(int i = 1; i <= 1000001; i++){
                mod *= 10;
                mod ++;
                mod %= k;
                if(mod == 0){
                    cout<<i<<'\n';
                    return;
                }
            }
            cout<<"-1";
        }
};
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
 }
