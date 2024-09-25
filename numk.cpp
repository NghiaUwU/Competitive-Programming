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

long long k, m, ans = 0;
int x;
        int digit[15];
        bool valid(long long m){
            int temp;
            while(m != 0){
                temp = m % 10;
                m /= 10;
                if(digit[temp] == 0)    return false;
            }
            return true;
        }
        void solve(){
            cin>>k>>m;
            for(int i = 1; i <= k; i++){
                //int x;
                cin>>x;
                digit[x]++;
            }

            for(int i = m; i <= 1000000000; i += m){
                
                if(valid(i) ){
                    cout<<i;
                    return;
                }
            }

            cout<<"-1";
        }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}