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
        bool check(long long a, long long b, long long c){
            if(a != b && b != c){
                if(a + b > c && c + a > b && b + c > a) return true;
            }
            return false;
        }
        long long a, b, c;
        void solve(){
            cin>>a>>b>>c;
            if(check(a, b, c))  cout<<"YES";
            else    cout<<"NO"<<endl;
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();

}   