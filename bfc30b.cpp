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
        long long n, s;
        long long w[206], v[206];
        long long ss = 0;
        void solve(){
            cin>>n>>s;
            ss = 0;
            for(int i = 1; i <= n; i++) cin>>w[i];
            for(int i = 1; i <= n; i++) cin>>v[i];

            for(int i = 1; i <= n; i++){
                if(w[i] <= s)   ss += v[i];  
            }

            cout<<ss<<'\n';
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    int test;
    cin>>test;
    while(test--){
        GHL.solve();
    }

}