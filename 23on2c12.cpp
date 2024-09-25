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
        long long l, r, m , k;
        long long op = 0;
        bool check(long long n){
            int ans = 0;
            while(n){
                ans += n % 10;
                n /= 10;
            }
            if(ans >= l && ans <= r)    return true;
            else    return false;
        }
        void solve(){
            cin>>l>>r>>m>>k;
            if(m == 1){
                string ans = "";

                while(l / 9 != 0){
                    ans += '9';
                    l -= 9;
                }
                if(l > 0)   ans = to_string(l) + ans;
                cout<<ans<<'\n';
                return;

            }
            for(int i = 1; i <= 1000006; i++){
                op = i * m + k;
                if(check(op)){
                    cout<<op<<'\n';
                    return;
                }
            }

            cout<<"-1"<<'\n';
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    int t;
    cin>>t;
    while(t--)
        GHL.solve();

}