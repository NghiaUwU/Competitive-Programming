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
        ll n, k;
        void solve(){
            cin>>n>>k;
             
            int ans = 0;
            for(int i = sqrt(k) - 1; i <= sqrt(n) + 1; i++){
                if(i * i >= k && i * i <= n)    ans++;
            }
            cout<<ans;
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    freopen("SQUARE.INP", "r", stdin);
    freopen("SQUARE.OUT", "w", stdout);
    SOL GHL;
    GHL.solve();

}