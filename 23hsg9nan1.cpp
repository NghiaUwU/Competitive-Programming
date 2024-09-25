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
        long long n;

        long long phi(long long n){
            if(n == 0)  return 0;
            ll ans = n;


            for(int i = 2; i * i <= n; i++){
                if(n % i == 0){
                    ans -= ans / i;
                    while(n % i == 0)   n /= i;
                }
            }

            if(n > 1)   ans -= ans / n;
            return ans;
        }
        void solve(){
            cin>>n;
            cout<<phi(n);
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();

}