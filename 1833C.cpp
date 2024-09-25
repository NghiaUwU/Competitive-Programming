#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

//  ~~ * ~~ NGHIA HAS GH ~~ * ~~ //
//  ~~ * ~~ NGHIA belongs to GHL ~~ * ~~

const long long ghl = 15052007;
const long long anniversary = 11102022;
const bool i_love_you_so_much = true; 
const long long MOD = 1e9 + 7;
const long long MAX = 1e18;

// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //


class SOL{
    public:
        int n;
        ll a[200005];
        
        
        void solve(){
            cin>>n;
            ll mnchan = 1e10, mnle = 1e10;
            ll mn = 1e10;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                mn = min(a[i], mn);

                if(a[i] % 2 == 0)   mnchan = min(mnchan, a[i]);
                else    mnle = min(mnle, a[i]);
            }
            //cout<<">> "<<mn<<' '<<mnchan<<' '<<mnle<<'\n';
            if(mnle == 1e10 || mnchan == 1e10){
                cout<<"YES"<<'\n';
                return;
            }

            if(mn % 2 != 0){
                cout<<"YES"<<'\n';
                return;
            }

            else    cout<<"NO"<<'\n';
            return;
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    int t;
    cin>>t;

    while(t--){
        GHL.solve();
    }

}