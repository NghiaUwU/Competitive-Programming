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

long long mul(long long a, long long b, long long mod){
    if(b == 0)  return 0;
    if(b == 1)  return a;
    long long t = mul(a, b / 2, mod) % mod;
    if(b % 2 == 0){
        return ((t % mod) + (t % mod) % mod) % mod;
    }
    else    return (((a % mod) + (t % mod) % mod) + (t % mod) % mod) % mod;
}
class SOL{
    public:
        long long a[5], M;

        void solve(){
            cin>>a[1]>>a[2]>>a[3]>>M;
            sort(a + 1, a + 1 + 3);
            if(a[1] < 0 && a[2] < 0){
                cout<<mul(abs(a[1]), abs(a[2]), M) % M;
            }
            else cout<<mul(a[2], a[3], M);
            
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("MAXPRO.inp", "r")){
        freopen("MAXPRO.inp", "r", stdin);
        freopen("MAXPRO.out", "w", stdout);
    }
    SOL GHL;
    GHL.solve();

}