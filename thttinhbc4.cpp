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
        long long n, m, q;
        long long widthl = 1e18, widthr = 0;
        long long lengthl = 1e18, lengthr = 0;

        long long x, y;
        void solve(){
            cin>>n>>m>>q;
            while(q--){
                cin>>x>>y;
                lengthl = min(lengthl, x);
                lengthr = max(lengthr, x);

                widthl =  min(widthl, y);
                widthr = max(widthr, y);

                cout<<'>'<<'>'<<' '<<widthl<<" "<<widthr<<" "<<lengthl<<" "<<lengthr<<'\n';
            }
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();

}