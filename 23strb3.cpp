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
        string s, num;
        int doop[1000];

        void solve(){
            cin>>s>>num;
            for(int i = 0; i < s.size(); i++){
                doop[i] = (s[i] - 65) + (num[i % num.size()] - 48) % 66;
                doop[i] += 65;
                int temp = doop[i] % 91;
                if(doop[i] > 90){
                    doop[i] = 65;
                    doop[i] += temp;
                }
                //cout<<doop[i]<<' ';
            }

            for(int i = 0; i < s.size(); i++){
                cout<<char(doop[i]);
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}