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

};

ll n, m;
ll price[10000002];
long long ans = 1e18;

void solve(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>price[i];

    sort(price + 1, price + 1 + n);

    for(int i = 1; i <= n - m + 1; i++){
        ans = min(ans, price[i + m - 1] - price[i]);
    }

    cout<<ans, 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("CHOSEBOOK.INP", "r", stdin);
    freopen("CHOSEBOOK.OUT", "w", stdout);
 ///   SOL GHL;
    //GHL.solve();
    solve();
}