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
        string s;
        void solve(){
            cin>>s;

            ll a = 0, b = 0, c = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == 'A') a++;
                else if(s[i] == 'B')    b++;
                else    c++;
            }

            if(a == s.size() || b  == s.size() || c == s.size()){
                cout<<"YES";
                return;
            }
            if(a == b)  cout<<"YES";
            else    cout<<"NO";
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}